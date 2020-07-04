#pragma once
#include <iostream>

template <class T>
class LinkedList
{
	class  Node
	{
	public:
		T element;
		Node* next;
		Node* prev;

		Node(int e, Node* n, Node* p)
		{
			element = e;
			next = n;
			prev = p;
		};
		~Node() {};
	};

private:
	int m_size;
	Node* first;
	Node* last;

	Node* node(int index)
	{
		Node* temp = nullptr;
		if (index > (m_size >> 1))
		{
			Node* node = last;
			for (int i = m_size; i > index + 1; i--)
			{
				temp = node->prev;
				node = temp;
			}
			return node;
		}
		else
		{
			Node* node = first;
			for (int i = 0; i < index; i++)
			{
				temp = node->next;
				node = temp;
			}
			return node;
		}

		return temp;
	}

	void freeMem()
	{
		if (first != nullptr)
		{
			Node* del = first;
			while (del != nullptr)
			{
				first = del->next;
				delete del;
				del = first;
			}
		}
	}

	void rangeCheck(int index)
	{
		if (index >= m_size || index < 0)
		{
			std::cout << "index error" << std::endl;
			return;
		}
	}

	void rangeCheckForAdd(int index)
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
		last = nullptr;
	}

	int size()
	{
		return this->m_size;
	}

	bool isEmpty()
	{
		return m_size == 0;
	}

	bool contains(T element)
	{
		return indexOf(element) != -1;
	}

	void add(T element)
	{
		add(m_size, element);
	}

	void add(int index, T element)
	{
		rangeCheckForAdd(index);

		Node* next = node(index);
		if (index == m_size)
		{
			Node* oldLast = last;
			last = new Node(element, nullptr, oldLast);
			if (oldLast == nullptr)
				first = last;
			else
				oldLast->next = last;
		}
		else
		{
			Node* prev = next->prev;
			Node* node = new Node(element, next, prev);
			if (prev == nullptr)
				first = node;
			else
				prev->next = node;
			next->prev = node;
		}

		m_size++;
	}

	T get(int index)
	{
		rangeCheck(index);
		return node(index)->element;
	}

	T set(int index, T element)
	{
		Node * node = node(index);
		T oldE = node->element;
		node->element = element;
		return oldE;
	}

	T remove(int index)
	{
		rangeCheck(index);

		Node* del = node(index);
		T oldE = del->element;
		Node* prev = del->prev;
		Node* next = del->next;
		if (prev == nullptr)
			first = next;
		else
			prev->next = next;

		if (next == nullptr)
			last = prev;
		else
			next->prev = prev;

		delete del;
		m_size--;

		return oldE;
	}

	int indexOf(T element)
	{
		Node* temp = first;
		int index = 0;
		while (temp != nullptr)
		{
			if (temp->element == element)
				return index;
			index++;
			temp = temp->next;
		}

		return -1;
	}

	void clear()
	{
		m_size = 0;
		first = nullptr;
		last = nullptr;
		freeMem();
	}

	void display()
	{
		Node* temp = first;
		while (temp != nullptr)
		{
			std::cout << temp->element << std::endl;
			temp = temp->next;
		}
	}

	~LinkedList()
	{
		if (first != nullptr)
		freeMem();
	}
};
