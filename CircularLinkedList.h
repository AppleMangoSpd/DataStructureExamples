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
		//Delete All new?
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

		node<T>* resultNode;
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
		CircularLinkedList_Iterator* returnIter = new CircularLinkedList_Iterator(_circularLinkedList);
		returnIter->SetIndex(1);

		return returnIter;
	};
	virtual IIterator<T>* Last() override
	{
		CircularLinkedList_Iterator* returnIter = new CircularLinkedList_Iterator(_circularLinkedList);
		returnIter->SetIndex(_circularLinkedList->SizeOf());

		return returnIter;
	};
	virtual IIterator<T>* Next() override 
	{
		CircularLinkedList_Iterator* returnIter = new CircularLinkedList_Iterator(_circularLinkedList);
		_index++;
		if (_index > _circularLinkedList->SizeOf())
		{
			_index = 1;
		}
		returnIter->SetIndex(_circularLinkedList->SizeOf());

		return returnIter;
	};
	virtual IIterator<T>* Current() override 
	{
		CircularLinkedList_Iterator* returnIter = new CircularLinkedList_Iterator(_circularLinkedList);
		returnIter->SetIndex(_index);

		return returnIter;
	};
	virtual T CurrentData() override 
	{
		T result = _circularLinkedList->At(_index);
		return result;
	};
	virtual bool IsEnd() override 
	{
		if (this->_index == _circularLinkedList->SizeOf())
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	void SetIndex(int input) 
	{
		if (input >= _circularLinkedList->SizeOf() + 1)
		{
			input = 1;
		}
		_index = input;
	};
	int GetIndex() const 
	{
		return _index;
	};

private:
	int _index;

	CircularLinkedList<T>* _circularLinkedList;
};