#pragma once
template <typename T>
struct Node
{
	T _data;
	Node* _first;
	Node* _second;

	Node(T data, Node* first, Node* second)
		: _data(data), _first(first), _second(second) {}
};

template <typename T>
class Tree
{
public:
	static Tree* CreateTree(const T& data)
	{

	};
	Node* Find(Node* root, const T& target)
	{

	};
	bool AddSubordinate(const T& data, const T& child)
	{

	}

	const Node* GetRoot() const
	{

	};
	void SetRoot(Node* target)
	{

	};
private:
	Tree() {};
	Node* _root;
};