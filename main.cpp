#include "Array.h"
#include "CircularLinkedList.h"

int main()
{
	CustomArray<int>* arraySample = new CustomArray<int>(10);
	arraySample->Add(1);
	arraySample->Add(2);
	arraySample->Add(3);

	arraySample->ViewAll();


	delete arraySample;

	return 0;
}