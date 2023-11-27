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
		return Find_impl(root, target);
	};
	bool AddSubordinate(const T& parent, const T& child)
	{
		return AddSubordinate_impl(parent, child);
	};

	const TreeNode<T>* GetRoot() const
	{
		return this->_root;
	};
	void SetRoot(TreeNode<T>* target)
	{
		this->_root = target;
	};

	void PreOrder() const
	{
		this->PreOrder_impl(this->_root);
	};
	void InOrder() const
	{
		this->InOrder_impl(this->_root);
	};
	void PostOrder() const
	{
		this->PostOrder_impl(this->_root);
	};
	void LevelOrder() const
	{
		this->LevelOrder_impl(this->_root);
	};

	
private:
	Tree() {};
	TreeNode<T>* Find_impl(TreeNode<T>* root, const T& target) 
	{
		if (nullptr == root)
		{
			return nullptr;
		}
		if (root->_data == target)
		{
			return root;
		}

		TreeNode<T>* firstFound = this->Find_impl(root->_first, target);
		if (nullptr != firstFound)
		{
			return firstFound;
		}

		return this->Find_impl(root->_second, target);
	};
	bool AddSubordinate_impl(const T& parent, const T& child)
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

	void PreOrder_impl(const TreeNode<T>* start) const
	{
		if (!start)
		{
			return;
		}
		std::cout << start->_data << ", ";
		PreOrder_impl(start->_first);
		PreOrder_impl(start->_second);
	};
	void InOrder_impl(const TreeNode<T>* start) const
	{
		if (!start)
		{
			return;
		}
		InOrder_impl(start->_first);
		std::cout << start->_data << ", ";
		InOrder_impl(start->_second);
	};
	void PostOrder_impl(const TreeNode<T>* start) const
	{
		if (!start)
		{
			return;
		}
		PostOrder_impl(start->_first);
		PostOrder_impl(start->_second);
		std::cout << start->_data << ", ";
	};
	void LevelOrder_impl(const TreeNode<T>* start) const
	{
		if (!start)
		{
			return;
		}
		std::queue<const TreeNode<T>*> nodeQueue;
		nodeQueue.push(start);

		while (!nodeQueue.empty())
		{
			size_t size = nodeQueue.size();
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

	TreeNode<T>* _root;
};