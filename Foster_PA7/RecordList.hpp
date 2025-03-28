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
	newNode->pNext = pHead;
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
	pHead = pHead->pNext;
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
	while (file >> data)
	{
		insertAtFront(data);
	}
	file.close();
}