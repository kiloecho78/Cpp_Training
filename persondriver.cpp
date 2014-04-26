#include<iostream>
using namespace std;
#include "person.cpp"

int main()
{
	person david;
	david.setFirstName("Davie");
	david.setLastName("Wavie");
	
	cout << "Hello " << david.getFirstName() << " " << david.getLastName() << endl;
	return 0;
}