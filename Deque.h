#pragma once
#include <iostream>

template <typename T>
class Deque
{
public:
	Deque(const int maxSize) : _front(0), _rear(0), _maxSize(maxSize) 
	{
		_data = new T[maxSize];
		_size = 0;
	};
	Deque() = delete;


	void AddFront(T target) 
	{ 
		AddFront_impl(target);
	};
	void AddRear(T target) 
	{ 
		AddRear_impl(target); 
	};
	T At(const int index) 
	{ 
		return At_impl(index);
	};

private:
	void AddFront_impl(T target)
	{
		if (_front != (_rear + 1) % _maxSize)
		{
			_data[_front] = target;
			_front = (_front - 1 + _maxSize) % _maxSize;
			_size = _size + 1;
		}
		else
		{
			std::cout << "Queue is full" << std::endl;
		}
	};
	void AddRear_impl(T target)
	{
		if (_front != (_rear + 1) % _maxSize)
		{
			_rear = (_rear + 1) % _maxSize;
			_data[_rear] = target;
			_size = _size + 1;
		}
		else
		{
			std::cout << "Queue is full" << std::endl;
		}
	};
	T At_impl(const int index) 
	{
		if (index >= _size)
		{
			std::cout << "Out of index" << std::endl;
			return NULL;
		}

		int targetIndex = _front + index + 1;
		if (targetIndex >= _maxSize)
		{
			targetIndex = targetIndex - _maxSize;
		}
		return _data[targetIndex];
	};

	T* _data;
	int _front;
	int _rear;
	int _maxSize;
	int _size;
};