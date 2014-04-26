#include<iostream>
#include "name.cpp"
using namespace std;

int main(int argc, char** args)
{
	name myName;
	myName.setFirstName("Keith");
	myName.setLastName("Everitt");
	
	cout << "Hello " << myName.getFirstName() << " " << myName.getLastName() << endl;
	
	name *HerName = new name;
	HerName -> setFirstName("Amy");
	HerName -> setLastName("Everitt");
	cout << "Hello " << HerName->getFirstName() << " " << HerName->getLastName() << endl;
	delete HerName;
	
	name *userName = new name;
	userName->setFirstName(args[1]);
	userName->setLastName(args[2]);
	cout << "Hello " << userName->getFirstName() << " " << userName->getLastName() << endl;
	delete userName;	
	
	return 0;
}