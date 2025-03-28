/*File: ListNode.hpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA6
* Created: 03/28/2025
* Last updated: 03/28/2025
* Description: Defines ListNode class to store RecordData object
*/
#pragma once
#include "RecordData.hpp"

template <typename T>
class ListNode
{
private:
	T data;
	T* pNext;

public:

	ListNode(const T& data); 
	~ListNode();
	T getData() const;
	T* getNext() const;
	void setNext(T* next);
};

template <typename T>
ListNode<T>::ListNode(const T& data)
{
	this->data = data;
	pNext = nullptr;
}

template <typename T>
ListNode<T>::~ListNode()
{
}

template <typename T>
T ListNode<T>::getData() const
{
	return data;
}

template <typename T>
T* ListNode<T>::getNext() const
{
	return pNext;
}

template <typename T>
void ListNode<T>::setNext(T* next)
{
	pNext = next;
}