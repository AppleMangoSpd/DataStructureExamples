#pragma once

template<typename T> class Array;
template<typename T> class CircularLinkedList;
template<typename T> class Tree;
class BinarySearchTree;
template<typename T> class NTree;
template<typename T> class Deque;

typedef enum 
{
	INT,
	CHAR,
	STRING

}TYPE;

class SampleTester
{
public:
	SampleTester();
	~SampleTester();

	void ArrayTest();
	void CLLTest();
	void TreeTest();
	void BSTTest();
	void NTreeTest();
	void DequeTest();
private:
	void DeleteAll();
};