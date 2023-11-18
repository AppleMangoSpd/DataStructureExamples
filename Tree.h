#pragma once
#include <iostream>
#include <queue>

template <typename T>
struct TreeNode
{
	T _data;
	TreeNode<T>* _first;
	TreeNode<T>* _second;

	TreeNode<T>(T data, TreeNode<T>* first, TreeNode<T>* second)
		: _data(data), _first(first), _second(second) {}
};

template <typename T>
class Tree
{
public:
	static Tree* CreateTree(const T& data)
	{
		Tree* tree = new Tree();
		tree->_root = new TreeNode<T>(data, nullptr, nullptr);

		return tree;
	};
	TreeNode<T>* Find(TreeNode<T>* root, const T& target)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (root->_data == target)
		{
			return root;
		}

		TreeNode<T>* firstFound = this->Find(root->_first, target);
		if (firstFound != nullptr)
		{
			return firstFound;
		}
		
		return this->Find(root->_second, target);
	};
	bool AddSubordinate(const T& parent, const T& child)
	{
		TreeNode<T>* parentTreeNode = this->Find(_root, parent);
		if (!parentTreeNode)
		{
			std::cout << "Can't find " << parent << std::endl;
			return false;
		}
		if (parentTreeNode->_first && parentTreeNode->_second)
		{
			std::cout << "Can't add " << parent << " under " << child;
			return false;
		}
		if (!parentTreeNode->_first)
		{
			parentTreeNode->_first = new TreeNode<T>(child, nullptr, nullptr);
		}
		std::cout << "Adding " << child << " under " << parent << "success" << std::endl;

		return true;
	};

	const TreeNode<T>* GetRoot() const
	{
		return this->_root;
	};
	void SetRoot(TreeNode<T>* target)
	{
		this->_root = target;
	};
private:
	Tree() {};
	TreeNode<T>* _root;
};

template <typename T>
class TreeTraversal
{
public:
	void PreOrder(const TreeNode<T>* start) const 
	{
		if (!start)
		{
			return;
		}
		std::cout << start->_data << ", ";
		PreOrder(start->_first);
		PreOrder(start->_second);
	};
	void InOrder(const TreeNode<T>* start) const 
	{
		if (!start)
		{
			return;
		}
		InOrder(start->_first);
		std::cout << start->_data << ", ";
		InOrder(start->_second);
	};
	void PostOrder(const TreeNode<T>* start) const
	{
		if (!start)
		{
			return;
		}
		PostOrder(start->_first);
		PostOrder(start->_second);
		std::cout << start->_data << ", ";
	};
	void LevelOrder(const TreeNode<T>* start) const
	{
		if (!start)
		{
			return;
		}
		std::queue<const TreeNode<T>*> nodeQueue;
		nodeQueue.push(start);

		while (!nodeQueue.empty())
		{
			int size = nodeQueue.size();
			for (int i = 0; i < size; i++)
			{
				const TreeNode<T>* current = nodeQueue.front();
				nodeQueue.pop();

				std::cout << current->_data << ", ";
				if (current->_first)
				{
					nodeQueue.push(current->_first);
				}
				if (current->_second)
				{
					nodeQueue.push(current->_second);
				}
			}
			std::cout << std::endl;
		}
	};
};