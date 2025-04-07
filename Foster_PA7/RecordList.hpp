/*File: RecordList.hpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA6
* Created: 03/28/2025
* Last updated: 03/28/2025
* Description: Defines RecordList class to store ListNodes of RecordData objects
*/
#pragma once
#include "ListNode.hpp"
using std::cin;

template <typename T>
class RecordList
{
private:
	ListNode<T>* pHead;

public:
	RecordList();
	~RecordList();
	void insertAtFront(const T& data);
	void removeFromFront();
	bool isEmpty() const;
	void destroy();
	void import(const std::string& filename);
	void importMaster(const std::string& filename);
	void store(const std::string& filename);
	void markAbsences();
	void generateReports();
};

template <typename T>
RecordList<T>::RecordList()
{
	pHead = nullptr;
}

template <typename T>
RecordList<T>::~RecordList()
{
	destroy();
}

template <typename T>
void RecordList<T>::insertAtFront(const T& data)
{
	ListNode<T>* newNode = new ListNode<T>(data);
	newNode->setNext(pHead);
	pHead = newNode;
}

template <typename T>
void RecordList<T>::removeFromFront()
{
	if (isEmpty())
	{
		std::cerr << "List is empty, cannot remove from front." << std::endl;
		return;
	}
	ListNode<T>* temp = pHead;
	pHead = pHead->getNext();
	delete temp;
}

template <typename T>
bool RecordList<T>::isEmpty() const
{
	return pHead == nullptr;
}

template <typename T>
void RecordList<T>::destroy()
{
	while (!isEmpty())
	{
		removeFromFront();
	}
}

template <typename T>
void RecordList<T>::import(const std::string& filename)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "Error opening file: " << filename << std::endl;
		return;
	}
	T data;
	this->destroy();
	string temp;
	getline(file, temp); //get rid of first line
	while (!file.eof())
	{
	file >> data;
		insertAtFront(data);
	}
	file.close();
}

template <typename T>
void RecordList<T>::importMaster(const std:: string& filename)
{
	this->destroy();
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "Error opening file: " << filename << std::endl;
		return;
	}
	RecordData temp;
	while (!file.eof())
	{
		temp.readMasterRecord(file);
		insertAtFront(temp);
	}
	file.close();
}

template <typename T>
void RecordList<T>::store(const std::string& filename)
{
	std::ofstream file(filename);
	if (!file)
	{
		std::cerr << "Error opening file: " << filename << std::endl;
		return;
	}
	ListNode<RecordData>* current = pHead;
	while (current != nullptr)
	{
		file << current->getData();
		if (current->getNext() != nullptr)
		{
			file << std::endl;
		}
		current = current->getNext() ;
	}
	file.close();
}

template <typename T>
void RecordList<T>::markAbsences()
{
	ListNode<RecordData>* current = pHead;
	while (current != nullptr)
	{
		current->getData().markAbsent(); //make sure this actually edits list data
		current = current->getNext();
	}
	system("pause");
}

template <typename T>
void RecordList<T>::generateReports()
{
	int choice = 0;
	cout << "(1) Generate absence count report" << endl << "(2) Generate report of all students at or above x absences" << endl;
	cin >> choice;
	if (choice == 1)
	{
		std::ofstream file("report1.txt");
		ListNode<RecordData>* current = pHead;
		while (current != nullptr)
		{
			file << current->getData().getName() << ",";
			file << current->getData().getAbsences() << ",";
			if (!current->getData().getAbsenceDates().empty())
			{
				file << current->getData().getAbsenceDates().top() << endl;
			}
			else
			{
				file << "No absences recorded" << endl;
			}
			current = current->getNext();
		}
		cout << "Report generated successfully." << endl;
		system("pause");
	}
	else if (choice == 2)
	{
		std::ofstream file("report2.txt");
		int x = 0;
		cout << "Enter absences threshold x: ";
		cin >> x;
		ListNode<RecordData>* current = pHead;
		while (current != nullptr)
		{
			if (current->getData().getAbsences() >= x)
			{
				file << current->getData().getName() << endl;
			}
			current = current->getNext();
		}
		cout << "Report generated successfully." << endl;
		system("pause");
	}
	else
	{
		cout << "Invalid choice." << endl;
		system("pause");
	}
}