#pragma once
#include <iostream>

template<typename T>
class CustomArray
{
public:
	CustomArray()
	{
		std::cout << "Please set size of CustomArray" << std::endl;
		int size;
		std::cin >> size;

		_array = new T[size];
		_arraySize = size;
		_currentSize = 0;
	};
	CustomArray(const int size)
	{
		_array = new T[size];
		_arraySize = size;
		_currentSize = 0;
	};
	~CustomArray()
	{
		if (_array)
		{
			delete[] _array;
		}
	};

	void Add(const T target)
	{
		this->Add_impl(target);
	};
	void Delete(const int target)
	{
		this->Delete_impl(target);
	}

	T At(const int index)
	{
		return this->At_impl(index);
	}
	//int Search(const T target)

	void ViewAll()
	{
		this->ViewAll_impl();
	};

	int sizeOf()
	{
		return _currentSize;
	};
	int Capacity()
	{
		return _arraySize;
	};

private:
	void Add_impl(const T target)
	{
		if (_currentSize == _arraySize)
		{
			std::cout << "Array is full" << std::endl;
			return;
		}
		_array[_currentSize] = target;
		_currentSize++;
	};
	void Delete_impl(const int target)
	{
		int targetIndex = target - 1;
		if (targetIndex > _currentSize)
		{
			std::cout << "Out of index" << std::endl;
			return;
		}
		for (int i = targetIndex; i < _currentSize; i++)
		{
			_array[i] = _array[i + 1];
		}
		_array[_currentSize] = 0;
		_currentSize--;
	};
	T At_impl(const int index)
	{
		if (index > _arraySize)
		{
			std::cout << "Out of index" << std::endl;
			return nullptr;
		}
		return _array[index];
	};
	void ViewAll_impl()
	{
		for (int i = 0; i < _currentSize; i++)
		{
			std::cout << _array[i] << " ";
		}
		std::cout << std::endl;
	}

	T* _array;
	int _currentSize;
	int _arraySize;
};