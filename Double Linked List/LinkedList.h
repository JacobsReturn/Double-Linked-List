#pragma once

class LinkedList
{
	private:
		struct Node
		{
			int value;
			Node* next;
			Node* prev;
		};

		Node* m_last;
		Node* m_first;
	public:
		int count;

		LinkedList();
		~LinkedList();

		void PushBack(int value);
		void PushFront(int value);
		
		void Pop();
		void PopFront();

		void Swap(Node* val, Node* val2);

		void Sort();
		void InsertAtIndex(int key, int value);

		Node* Get(int index);

		int GetBack();
		int GetFront();

		void PrintTree();
		void Empty();

		void RemoveAtIndex(int key);
};

