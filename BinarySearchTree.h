#pragma once
#include <iostream>

template <typename T>
struct BSTNode
{
	T _data;
	BSTNode* _left;
	BSTNode* _right;
};

template <typename T>
class BinarySearchTree
{
public:
	BSTNode* _root = nullptr;

	const BSTNode* Find(const T target) const
	{
		return this->Find_impl(this->_root, target);
	};
	void Insert(const T target) 
	{
		if (!_root)
		{
			_root = new BSTNode<T>{ target, nullptr, nullptr };
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
	void DeleteValue(const T target) 
	{
		_root = Delete_impl(_root, target);
	};

private:
	const BSTNode* Find_impl(const BSTNode* current, const T target) const 
	{
		if (!current)
		{
			std::cout << std::endl;
			return nullptr;
		}
		if (current->_data == target)
		{
			std::cout << "Found " << target << std::endl;
			return current;
		}
	};
	void Insert_impl(BSTNode* current, const T target) 
	{};
	void InOrder_impl(const BSTNode* start) const
	{};
	void DescendingOrder_impl(const BSTNode* start) const 
	{};
	BSTNode* Delete_impl(BSTNode* start, const T target) 
	{};
	Node* Successor(BSTNode* start) const 
	{};
}