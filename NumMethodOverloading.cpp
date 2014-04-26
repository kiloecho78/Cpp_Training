#include <iostream>
using namespace std;
#include "num.cpp"

int main()
{
	num n1 (12.5);
	num n()
	n.setValue(1);
	num *n2 = new num('A'); 
	cout << "n.integerValue = " << n.integerValue() << endl;
	n.setValue(5.31415);
	cout << "n.doubleValue = " << n.doubleValue() << endl;
	n.setValue('K');
	cout << "n.charValue = " << n.charValue() << endl;
	cout << n1.doubleValue() << endl;
	cout << n2->doubleValue() << endl;
	delete n2;
	
	return 0;
}