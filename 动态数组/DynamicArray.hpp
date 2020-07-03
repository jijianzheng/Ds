#pragma once 
#include <iostream>
#include <cstring>

template <class T>
class DArray
{
private:

	// T类型动态数组
	T* m_array;

	// 动态数组当前的元素个数
	int m_lenth;

	// 动态数组的总容量
	int m_capacity;

	/*
		rangeCheck函数检测输入的数组下标是否有效
		若无效且数组的指向不为空,释放数组的堆空间
	*/
	void rangeCheck(int index)
	{
		if (index > m_lenth || index < 0)
		{
			if (m_array != nullptr)
				delete[] m_array;
			std::cout << "index error" << std::endl;
			return;
		}
	}

	/*
		扩容函数: 使用memcpy函数复制原来的空间内容给新开辟的空间,
		使capacity的值为原来的1.5倍
	*/
	void expansion()
	{
		T* temp = new T[m_capacity];
		T* del = m_array;

		memcpy(temp, m_array, sizeof(T) * m_lenth);
		m_capacity += (m_capacity >> 1);

		m_array = new T[m_capacity]; 
		memcpy(m_array, temp, sizeof(T) * m_lenth);
		
		delete[] temp;
		delete[] del;
	}

public:

	DArray(int cap = 10)
	{
		m_lenth = 0;
		m_capacity = (cap > 10 ? cap : 10); 
		m_array = new T[m_capacity];
	}

	bool isEmpty()
	{
		return this->size() == 0;
	}

	bool contains(T element)
	{
		return indexOf(element) != -1;
	}

	int indexOf(T element)
	{
		for (int i = 0; i < m_lenth; i++)
		{
			if (m_array[i] == element)
				return i;
		}

		return -1;
	}

	void display()
	{
		for (int i = 0; i < m_lenth; i++)
			std::cout << m_array[i] << std::endl;
	}

	int size()
	{
		return m_lenth;
	}

	void add(T element)
	{
		add(m_lenth, element);
	}

	void add(int index, T element)
	{
		rangeCheck(index);
		if (m_lenth + 1 >= m_capacity)
			expansion();
		for (int i = m_lenth; i > index - 1; i--)
		{
			m_array[i+1] = m_array[i];
		}

		m_array[index] = element;

		m_lenth++;
	}

	void remove(int index)
	{
		rangeCheck(index);
		for (int i = index; i < m_lenth; i++)
		{
			m_array[i] = m_array[i+1];
		}

		m_lenth--;
	}

	void clear()
	{
		m_lenth = 0;
	}

	~DArray()
	{
		if (m_array != nullptr)
			delete[] m_array;
	}
};
