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
	void print() const;
	void import(const std::string& filename);
	void store(const std::string& filename);
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
void RecordList<T>::print() const
{
	ListNode<T>* current = pHead;
	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->pNext;
	}
	std::cout << std::endl;
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
	file >> data;
	while (!file.eof())
	{
		insertAtFront(data);
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
	ListNode<T>* current = pHead;
	while (current != nullptr)
	{
		file << current->getData() << std::endl;
		current = current->getNext() ;
	}
	file.close();
}