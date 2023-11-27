#pragma once
#include <iostream>

//template <typename T>
struct BSTNode
{
	int _index;
	//T _data;
	BSTNode* _left;
	BSTNode* _right;
};

//template <typename T>
class BinarySearchTree
{
public:
	//BSTNode<T>* _root = nullptr;
	BSTNode* _root = nullptr;

	//const BSTNode<T>* Find(const int target) const
	const BSTNode* Find(const int target) const
	{
		return this->Find_impl(this->_root, target);
	};
	void Insert(const int target)
	{
		if (!_root)
		{
			//_root = new BSTNode<T>{ target, nullptr, nullptr, nullptr };
			_root = new BSTNode{ target, nullptr, nullptr };
		}
		else
		{
			this->Insert_impl(this->_root, target);
		}
	};
	void InOrder() const 
	{
		this->InOrder_impl(this->_root);
	};
	void DescendingOrder() const 
	{
		this->DescendingOrder_impl(this->_root);
	};
	void DeleteValue(const int target)
	{
		_root = Delete_impl(_root, target);
		std::cout << target << " Deleted" << std::endl;
	};

private:
	//const BSTNode<T>* Find_impl(const BSTNode<T>* current, const int target) const
	const BSTNode* Find_impl(const BSTNode* current, const int target) const
	{
		if (!current)
		{
			std::cout << std::endl;
			return nullptr;
		}
		if (current->_index == target)
		{
			std::cout << "Found " << current->_index << std::endl;
			return current;
		}
		if (target < current->_index)
		{
			std::cout << "move from " << current->_index << " to left node ";
			return Find_impl(current->_left, target);
		}
		
		std::cout << "move from " << current->_index << " to right node ";
		return Find_impl(current->_right, target);
	};

	//void Insert_impl(BSTNode<T>* current, const int target)
	void Insert_impl(BSTNode* current, const int target)
	{
		if (target < current->_index)
		{
			if (!current->_left)
			{
				//current->_left = new BSTNode<T>{ target, nullptr, nullptr, nullptr };
				current->_left = new BSTNode{ target, nullptr, nullptr };
			}
			else
			{
				Insert_impl(current->_left, target);
			}
		}
		else
		{ 
			if (!current->_right)
			{
				//current->_right = new BSTNode<T>{ target, nullptr, nullptr, nullptr };
				current->_right = new BSTNode{ target, nullptr, nullptr };
			}
			else
			{
				Insert_impl(current->_right, target);
			}
		}

	};
	//void InOrder_impl(const BSTNode<T>* start) const
	void InOrder_impl(const BSTNode* start) const
	{
		if (!start)
		{
			return;
		}
		InOrder_impl(start->_left);
		std::cout << start->_index << " ";
		InOrder_impl(start->_right);
	};
	//void DescendingOrder_impl(const BSTNode<T>* start) const
	void DescendingOrder_impl(const BSTNode* start) const
	{
		if (!start)
		{
			return;
		}
		DescendingOrder_impl(start->_right);
		std::cout << start->_index << " ";
		DescendingOrder_impl(start->_left);
	};

	//BSTNode<T>* Delete_impl(BSTNode<T>* start, const int target)
	BSTNode* Delete_impl(BSTNode* start, const int target)
	{
		if (!start)
		{
			return nullptr;
		}
		if (target < start->_index)
		{
			start->_left = Delete_impl(start->_left, target);
		}
		else if (target > start->_index)
		{
			start->_right = Delete_impl(start->_right, target);
		}
		else
		{
			if (!start->_left)
			{
				//BSTNode<T>* tmp = start->_right;
				BSTNode* tmp = start->_right;
				delete start;
				return tmp;
			}
			if (!start->_right)
			{
				//BSTNode<T>* tmp = start->_left;
				BSTNode* tmp = start->_left;
				delete start;
				return tmp;
			}

			//BSTNode<T>* succNode = this->Successor(start);
			BSTNode* succNode = this->Successor(start);
			start->_index = succNode->_index;

			start->_right = Delete_impl(start->_right, succNode->_index);
		}
		return start;
	};

	//BSTNode<T>* Successor(BSTNode<T>* start) const 
	BSTNode* Successor(BSTNode* start) const 
	{
		//BSTNode<T>* current = start->_right;
		BSTNode* current = start->_right;
		while (current && current->_left)
		{
			current = current->_left;
		}
		return current;
	};
};