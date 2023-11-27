#pragma once
#include <iostream>
#include "IIterator.h"

template <typename T>
struct Node
{
	T data;
	Node* prev;
	Node* next;
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
		this->PushFront_impl(data);
	};
	void PushBack(const T data)
	{
		this->PushBack_impl(data);
	};

	const int SizeOf() const
	{
		return this->_size;
	};

	IIterator<T>* Begin() const
	{
		return this->_iter->First();
	}
	IIterator<T>* End() const
	{
		return this->_iter->Last();
	}
	IIterator<T>* GetIterator() const
	{
		return this->_iter;
	}

	T At(const int target) const
	{
		return this->At_impl(target);
	}

	bool IsEmpty() const
	{
		if (nullptr == _head)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void PrintList()
	{
		this->PrintList_impl();
	}

private:
	void setFirstNode(Node<T>* firstNode)
	{
		this->_head = firstNode;
		this->_tail = firstNode;

		firstNode->prev = firstNode;
		firstNode->next = firstNode;
	}
	void PushFront_impl(const T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		if (nullptr == _head)
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
	void PushBack_impl(const T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		if (nullptr == _head)
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

	T At_impl(const int target) const
	{
		if (this->SizeOf() < target)
		{
			std::cout << "Out of index" << std::endl;
			return nullptr;
		}
		int index = 1;

		Node<T>* resultNode;
		resultNode = this->_head;
		while (index < target)
		{
			resultNode = resultNode->next;
			index++;
		}
		return resultNode->data;
	}

	void PrintList_impl()
	{
		IIterator<T>* iter = new CircularLinkedList_Iterator<T>(this);
		iter = this->Begin();
		for (int i = 0; i < _size; i++)
		{
			std::cout << iter->CurrentData() << " ";
			iter->Next();
		}

		delete iter;
	}

	int _size;
	Node<T>* _head;
	Node<T>* _tail;

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
		returnIter->SetIndex(_index);

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