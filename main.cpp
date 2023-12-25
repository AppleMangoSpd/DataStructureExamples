#include "SampleTester.h"

int main()
{
	SampleTester* sampleTester = new SampleTester();

	sampleTester->StartAllTest();

	delete sampleTester;
	return 0;
}