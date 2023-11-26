#include "Array.h"
#include "CircularLinkedList.h"
#include "Tree.h"
#include "BinarySearchTree.h"

int main()
{
	CustomArray<int>* arraySample = new CustomArray<int>(10);
	arraySample->Add(1);
	arraySample->Add(2);
	arraySample->Add(3);

	arraySample->ViewAll();

	arraySample->Delete(2);
	arraySample->ViewAll();

	CircularLinkedList<std::string>* CLLSample 
		= new CircularLinkedList<std::string>();
	
	CLLSample->PushFront("one");
	CLLSample->PushBack("two");
	CLLSample->PushBack("three");
	
	IIterator<std::string>* CLLIter = CLLSample->Begin();
	
	std::cout << CLLIter->First()->CurrentData();
	std::cout << CLLIter->Next()->CurrentData() <<std::endl;
	CLLSample->PushFront("zero");
	CLLSample->PrintList();

	Tree<int>* treeSample = Tree<int>::CreateTree(1);
	
	treeSample->AddSubordinate(1, 2);
	treeSample->AddSubordinate(2, 3);
	treeSample->AddSubordinate(3, 4);
	treeSample->AddSubordinate(4, 5);
	treeSample->AddSubordinate(5, 6);

	treeSample->PreOrder();
	std::cout << std::endl;
	treeSample->InOrder();
	std::cout << std::endl;
	treeSample->PostOrder();
	std::cout << std::endl;
	treeSample->LevelOrder();
	std::cout << std::endl;

	BinarySearchTree* bstSample = new BinarySearchTree();
	bstSample->Insert(1);
	bstSample->Insert(2);
	bstSample->Insert(3);
	bstSample->Insert(4);
	bstSample->Insert(5);
	bstSample->Insert(6);

	bstSample->InOrder();
	bstSample->DescendingOrder();


	delete arraySample;
	delete CLLSample;
	delete CLLIter;
	delete treeSample;
	delete bstSample;

	return 0;
}