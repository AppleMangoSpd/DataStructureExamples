#pragma once
#include <iostream>
#include "IIterator.h"

template <typename T>
struct node
{
	T data;
	node* prev;
	node* next;
};

template <typename T>
class CircularLinkedList_Iterator;

template <typename T>
class CircularLinkedList
{
public:
	CircularLinkedList()
	{
		_iter = new CircularLinkedList_Iterator<T>(this);
		_size = 0;
	};
	~CircularLinkedList()
	{
		delete _iter;
	};

	void PushFront(T data)
	{
		node<T>* newNode = new node<T>;
		newNode->data = data;
		if (_head == nullptr)
		{
			setFirstNode(newNode);
		}
		else
		{
			_head->prev = newNode;
			newNode->next = _head;
			this->_head = newNode;
			newNode->prev = _tail;
		}
		_size++;
	};
	
	void PushBack(T data)
	{
		node<T>* newNode = new node<T>;
		newNode->data = data;
		if (_head == nullptr)
		{
			setFirstNode(newNode);
		}
		else
		{
			_tail->next = newNode;
			newNode->prev = this->_tail;
			this->_tail = newNode;
			newNode->next = _head;
		}
		_size++;
	};
	const int SizeOf() const
	{
		return this->_size;
	};

	IIterator<T>* Begin() const
	{
		return _iter->First();
	}
	IIterator<T>* End() const
	{
		return _iter->Last();
	}
	IIterator<T>* GetIterator() const
	{
		return _iter;
	}

	T At(const int target) const
	{
		if (this->SizeOf() < target)
		{
			std::cout << "Out of index" << std::endl;
			return nullptr;
		}
		int index = 1;

		node* resultNode;
		resultNode = this->_head;
		while (index < target)
		{
			resultNode = resultNode->next;
			index++;
		}
		return resultNode->data;
	}

	bool IsEmpty() const
	{
		if (_head == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	void setFirstNode(node<T>* firstNode)
	{
		this->_head = firstNode;
		this->_tail = firstNode;

		firstNode->prev = firstNode;
		firstNode->next = firstNode;
	}

	int _size;
	node<T>* _head;
	node<T>* _tail;

	IIterator<T>* _iter;
};

template <typename T>
class CircularLinkedList_Iterator : public IIterator<T>
{
public:
	CircularLinkedList_Iterator<T>(CircularLinkedList<T>* target) 
	{
		_circularLinkedList = target;
	}

	~CircularLinkedList_Iterator()
	{
		delete _circularLinkedList;
	}

	//IIterator 기능 구현
	virtual IIterator<T>* First() override
	{
		
	};
	virtual IIterator<T>* Last() override
	{};
	virtual IIterator<T>* Next() override {};
	virtual IIterator<T>* Current() override {};
	virtual T CurrentData() override {};
	virtual bool IsEnd() override {};

	void SetIndex(int input);
	int GetIndex() const;

private:
	int _index;

	CircularLinkedList<T>* _circularLinkedList;
};