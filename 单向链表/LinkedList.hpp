#pragma once
#include <iostream>

template <class T>
class LinkedList
{
	class Node
	{
	public:
		T element;
		Node* next;
	public:
		Node()
		{
			element = 0;
			next = nullptr;
		}
		Node(T e, Node* n)
		{
			element = e;
			next = n;
		};
		~Node() {};
	};

private:
	int m_size;
	Node* first;

	Node* findNode(int index)
	{
		if (index == 0)
			return first;
		else
		{
			Node* temp = first;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			return temp;
		}
	}

	void freeMem()
	{
		Node* temp = first;

		while (temp != nullptr)
		{
			first = temp->next;
			delete temp;
			temp = first;
		}
	}

	void rangeCheck(int index)
	{
		if (index > m_size || index < 0)
		{
			std::cout << "index error" << std::endl;
			return;
		}
	}

public:
	LinkedList()
	{
		m_size = 0;
		first = nullptr;
	}

	int size()
	{
		return m_size;
	}

	bool isEmpty()
	{
		return size() == 0;
	}

	void add(T element)
	{
		add(m_size, element);
	}

	void add(int index, T element)
	{
		if (first == nullptr)
			first = new Node(element, nullptr);
		else
		{
			Node* prev = findNode(index);
			Node* node = new Node(element, prev->next);
			if (index == 0)
			{
				first = node;
				first->next = prev;
			}
			else
				prev->next = node;
		}
		m_size++;
	}

	bool contains(T element)
	{
		return indexOf(element) != -1;
	}

	int indexOf(T element)
	{
		Node * temp = first;
		int index = 0;
		while (temp != nullptr)
		{
			if (temp->element == element)
				return index;
			temp = temp->next;
			index++;
		}
		return -1;
	}

	void remove(int index)
	{
		rangeCheck(index);
		if (index == 0)
		{
			Node * temp = first;
			if (temp == nullptr)
				return;
			first = first->next;
			delete temp;
		}
		else
		{
			Node* prev = findNode(index);
			if (prev == nullptr)
				return;
			Node* node = findNode(index + 1);
			if (node == nullptr)
				prev->next = nullptr;
			else
			{
				prev->next = node->next;
				delete node;
			}
		}
		m_size--;
	}

	void clear()
	{
		m_size = 0;
		freeMem();
		first = nullptr;
	}

	void display()
	{
		Node * temp = first;
		while (temp != nullptr)
		{
			std::cout << temp->element << std::endl;
			temp = temp->next;
		}
	}

	~LinkedList()
	{
		while (first != nullptr)
			freeMem();
	}
};
