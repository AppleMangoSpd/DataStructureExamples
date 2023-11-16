#include "Array.h"
#include "CircularLinkedList.h"

int main()
{
	CustomArray<int>* arraySample = new CustomArray<int>(10);
	arraySample->Add(1);
	arraySample->Add(2);
	arraySample->Add(3);

	arraySample->ViewAll();

	arraySample->Delete(2);
	arraySample->ViewAll();

	CircularLinkedList<std::string>* CLLSample = new CircularLinkedList<std::string>();
	
	CLLSample->PushFront("one");
	CLLSample->PushBack("two");
	CLLSample->PushBack("three");
	IIterator<std::string>* CLLIter 
		= new CircularLinkedList_Iterator<std::string>(CLLSample);
	CLLIter = CLLSample->Begin();
	std::cout << CLLIter->CurrentData();
	CLLIter = CLLIter->Next();
	std::cout << CLLIter->CurrentData();

	delete arraySample;
	delete CLLSample;

	return 0;
}