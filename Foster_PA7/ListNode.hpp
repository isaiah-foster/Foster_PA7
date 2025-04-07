/*File: ListNode.hpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA6
* Created: 03/28/2025
* Last updated: 04/07/2025
* Description: Defines ListNode class to store RecordData object
*/
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "RecordData.hpp"

template <typename T>
class ListNode
{
private:
	T data;
	ListNode<T>* pNext;
public:

	ListNode(const T& data); 
	~ListNode();
	T& getData();
	ListNode<T>* getNext() const;
	void setNext(ListNode<T>* next) { pNext = next; }
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
T& ListNode<T>::getData()
{
	return data;
}

template <typename T>
ListNode<T>* ListNode<T>::getNext() const
{
	return pNext;
}