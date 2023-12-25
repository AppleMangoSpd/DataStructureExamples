#pragma once

enum DATA_STRUCTURES
{
	BEGIN_OF_DATA_STRUCTURES,
	ARRAY,
	CLL,
	TREE,
	BST,
	NTREE,
	DEQUE,
	END_OF_DATA_STRUCTURES
};

class SampleTester
{
public:
	SampleTester();
	~SampleTester();
	void StartTest(DATA_STRUCTURES target);
	void StartAllTest();

private:
	void ArrayTest();
	void CLLTest();
	void TreeTest();
	void BSTTest();
	void NTreeTest();
	void DequeTest();
	
};