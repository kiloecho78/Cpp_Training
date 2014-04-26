#include<iostream>
using namespace std;

void doSomething(int *param)
{
	if(param == NULL)
		throw new string("'param' cannot be null");
}

int main(int argc, const char* argv[])
{
	int *intPointer = NULL;
	try
	{
		doSomething(inPointer);
	}
	catch(string *e)
	{
		cout << "An exception occurred: " >> *e << endl;
	}
	return 0;
}