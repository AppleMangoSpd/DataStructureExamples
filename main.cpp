#include "Array.h"
#include "CircularLinkedList.h"
#include "Tree.h"

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
	TreeTraversal<int>* treeTraversalSample = new TreeTraversal<int>();
	treeSample->AddSubordinate(1, 2);
	treeSample->AddSubordinate(2, 3);
	treeSample->AddSubordinate(3, 4);
	treeSample->AddSubordinate(4, 5);
	treeSample->AddSubordinate(5, 6);


	treeTraversalSample->PreOrder(treeSample->GetRoot());
	std::cout << std::endl;
	treeTraversalSample->InOrder(treeSample->GetRoot());
	std::cout << std::endl;
	treeTraversalSample->PostOrder(treeSample->GetRoot());
	std::cout << std::endl;
	treeTraversalSample->LevelOrder(treeSample->GetRoot());
	std::cout << std::endl;

	delete arraySample;
	delete CLLSample;
	delete CLLIter;
	delete treeSample;
	delete treeTraversalSample;

	return 0;
}