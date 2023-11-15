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
	CLLSample->PushFront("two");
	CLLSample->PushBack("three");
	CircularLinkedList_Iterator<std::string>* CLLIter 
		= new CircularLinkedList_Iterator<std::string>(CLLSample);



	delete arraySample;
	delete CLLSample;

	return 0;
}