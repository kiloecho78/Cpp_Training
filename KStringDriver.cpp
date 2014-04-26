#include<iostream>
#include "KString.cpp"
using namespace std;

int main()
{
	KString fruit = KString();
	KString banana = KString("banana");
	KString bananaAlso = KString(banana);
	cout << "fruit=" << fruit << endl;
	cout << "banana=" << banana << endl;
	cout << "bananaAlso=" << bananaAlso << endl;
	return 0;
}