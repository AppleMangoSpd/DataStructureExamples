#include "Array.h"
#include "CircularLinkedList.h"
#include "Tree.h"
#include "BinarySearchTree.h"
#include "NTree.h"

int main()
{
	std::cout << "Array Sample Test Start" << std::endl;
	CustomArray<int>* arraySample = new CustomArray<int>(10);
	arraySample->Add(1);
	arraySample->Add(2);
	arraySample->Add(3);

	arraySample->ViewAll();

	arraySample->Delete(2);
	arraySample->ViewAll();

	std::cout << "Array Sample Test End" << std::endl;
	std::cout << std::endl;
	std::cout << "CircularLinkedList Sample Test Start" << std::endl;

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

	std::cout << "CircularLinkedList Sample Test End" << std::endl;
	std::cout << std::endl;
	std::cout << "Tree Sample Test Start" << std::endl;

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

	std::cout << "Tree Sample Test End" << std::endl;
	std::cout << std::endl;
	std::cout << "BinarySearchTree Sample Test Start" << std::endl;

	BinarySearchTree* bstSample = new BinarySearchTree();
	bstSample->Insert(12);
	bstSample->Insert(10);
	bstSample->Insert(20);
	bstSample->Insert(8);
	bstSample->Insert(11);
	bstSample->Insert(15);
	bstSample->Insert(28);
	bstSample->Insert(4);
	bstSample->Insert(2);

	bstSample->InOrder();
	bstSample->DescendingOrder();
	
	if (bstSample->Find(4))
	{
		std::cout << "found 4 in bstSample";
	}

	bstSample->DeleteValue(15);
	bstSample->InOrder();

	std::cout << "BinarySearchTree Sample Test End" << std::endl;
	std::cout << std::endl;
	std::cout << "NTree Sample Test Start" << std::endl;

	NTree<std::string>* ntreeSample = new NTree<std::string>();
	ntreeSample->Insert("root", "root");
	ntreeSample->Insert("first", "root");
	ntreeSample->Insert("second", "root");
	ntreeSample->Insert("third", "root");
	ntreeSample->Insert("forth", "third");
	ntreeSample->AddData("added hello", "first");
	std::cout << ntreeSample->Find("third")->_name << std::endl;
	std::cout << std::endl;
	std::cout << "NTree Sample Test End" << std::endl;

	delete arraySample;
	delete CLLSample;
	delete CLLIter;
	delete treeSample;
	delete bstSample;
	delete ntreeSample;

	return 0;
}