#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
	count = 0;
	m_first = nullptr;
	m_last = nullptr;
}

LinkedList::~LinkedList()
{
	Empty();

	delete m_first;
	delete m_last;
}

void LinkedList::PushBack(int value)
{
	Node* newNode = new Node();

	newNode->value = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	if (count != 0)
	{
		newNode->prev = m_last;
		m_last->next = newNode;

		m_last = newNode;
	}
	else
	{
		m_first = newNode;
		m_last = newNode;
	}

	count++;
}

void LinkedList::PushFront(int value)
{
	Node* newNode = new Node();

	newNode->value = value;
	newNode->next = m_first;
	newNode->prev = nullptr;

	m_first->prev = newNode;
	m_first = newNode;
}

void LinkedList::Pop()
{
	Node* newLast = m_last->prev;
	newLast->next = nullptr;

	delete m_last;

	m_last = newLast;
}

void LinkedList::PopFront()
{
	Node* newFirst = m_first->next;
	newFirst->prev = nullptr;

	delete m_first;

	m_first = newFirst;
}

void LinkedList::Swap(Node* val, Node* val2)
{
	if (val == nullptr || val2 == nullptr) return;

	if (m_last == val) m_last = val2; else if (m_last == val2) m_last = val;
	if (m_first == val) m_first = val2; else if (m_first == val2) m_first = val;

	Node* val_prev = val->prev;
	Node* val2_next = val2->next;

	if (val_prev != nullptr) val_prev->next = val2;
	val->prev = val2;
	val->next = val2_next;

	if (val2_next != nullptr) val2_next->prev = val;
	val2->next = val;
	val2->prev = val_prev;
}

void LinkedList::Sort()
{
	int i, j;
	for (i = 0; i < count; i++)
		for (j = 0; j < count - i; j++)
			if (Get(j)->value > Get(j + 1)->value)
				Swap(Get(j), Get(j + 1));
}

void LinkedList::InsertAtIndex(int key, int value)
{
	if (key > count) PushBack(value);
	else if (key <= 1) PushFront(value);
	else
	{
		Node* place = Get(key);
		Node* newNode = new Node();

		newNode->value = value;
		newNode->next = place;
		newNode->prev = place->prev;

		if (place->prev != nullptr) place->prev->next = newNode;
		place->prev = newNode;

		count++;
	}
}

LinkedList::Node* LinkedList::Get(int index)
{
	if (count > 0)
	{
		int ind = 0;
		Node* current = m_first;

		while (current != nullptr)
		{
			if (ind == index)
			{
				return current;
			}

			current = current->next;
			ind++;
		}
	}

	return nullptr;
}

int LinkedList::GetFront()
{
	if (m_first == nullptr)
		return 0;

	return m_first->value;
}

void LinkedList::PrintTree()
{
	std::cout << std::endl;
	for (int i = 0; i <= count; i++)
	{
		Node* node = Get(i);

		if (node == nullptr) std::cout << i << ": NULL" << std::endl;
		else std::cout << i << ": " << node->value << std::endl;
	}
}

void LinkedList::Empty()
{
	Node* current = m_last;
	while (current != nullptr)
	{
		Node* toCurrent = current->prev;

		delete current;

		current = toCurrent;

		delete toCurrent;
	}
}

void LinkedList::RemoveAtIndex(int key)
{
	Node* place = Get(key);
	Node* before = place->prev;
	Node* after = place->next;

	if (before != nullptr)
	{
		before->next = after;
		before->prev = before;
	}

	if (after != nullptr)
	{
		after->prev = before;
	}

	count--;

	delete place;
}

int LinkedList::GetBack()
{
	if (m_last == nullptr)
		return 0;

	return m_last->value;
}
