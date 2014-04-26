#include<iostream>
using namespace std;
#include "person.cpp"
int main()
{
	person p1;
	p1.setFirstName("Bill");
	p1.setLastName("Mill");
	
	person p2 ("Will", "Nill");
	
	person *p3 = new person ("Jill","Fill");
	
	cout << "p1's name is: " << p1.getFirstName() + " " + p1.getLastName() << endl;
		 << "p2's name is: " << p2.getFirstName() + " " + p2.getLastName() << endl;
		 << "p3's name is: " << p3->getFirstName() + " " + p3->getLastName() << endl;
	delete p3;
	return 0;
}