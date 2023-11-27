#pragma once
#include <string>
#include <vector>
#include <iostream>

template <typename T>
struct NNode
{
	std::string _name;
	NNode<T>* _parent;
	std::vector<NNode<T>*> _children;
	std::vector<T> _data;
};

template <typename T>
class NTree
{
public:
	NTree() : _root(nullptr) {}

	void Insert(std::string name, std::string parentName)
	{
		Insert_impl(name, parentName);
	}
	NNode<T>* Find(std::string name) const
	{
		NNode<T>* tempNode = FindWithName_impl(_root, name);
		if (nullptr == tempNode)
		{
			std::cout << name << "doesn't exisit in NTree" << std::endl;
		}
		return tempNode;
	}
	
	void AddData(T data, std::string target)
	{
		AddData_impl(data, target);
	}

	NNode<T>* GetRoot() const
	{
		return _root;
	}	

private:

	void Insert_impl(std::string name, std::string parentName)
	{
		if (nullptr == _root)
		{
			NNode<T>* childNode = new NNode<T>();
			childNode->_name = name;
			childNode->_parent = nullptr;
			_root = childNode;

			return;
		}
		NNode<T>* parentNode = FindWithName_impl(_root, parentName);
		if (nullptr == parentNode)
		{
			std::cout << "Can't find " << parentName << " NNode" << std::endl;
			return;
		}
		NNode<T>* childNode = new NNode<T>();
		childNode->_name = name;
		childNode->_parent = parentNode;

		parentNode->_children.push_back(childNode);
	}
	NNode<T>* FindWithName_impl(NNode<T>* current, std::string targetName) const
	{
		NNode<T>* tempNode = nullptr;

		if (current->_name == targetName)
		{
			return current;
		}
		else
		{
			typename std::vector<NNode<T>*>::iterator iter;

			for (iter = current->_children.begin(); iter != current->_children.end(); ++iter)
			{
				tempNode = FindWithName_impl(*iter, targetName);
				if (nullptr != tempNode)
				{
					return tempNode;
				}
			}
		}
		return tempNode;
	}

	void AddData_impl(T data, std::string target)
	{
		NNode<T>* parentNode = FindWithName_impl(_root, target);
		if (nullptr == parentNode)
		{
			std::cout << "Can't find " << target << "node" << std::endl;
			return;
		}
		parentNode->_data.push_back(data);
	}

	NNode<T>* _root;
};