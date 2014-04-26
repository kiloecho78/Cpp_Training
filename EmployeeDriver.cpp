#include<iostream>
using namespace std;
#include "person.cpp"
#include "employee.cpp"

int main()
{
	person *p = new person("Amy", "Everitt");
	employee e1;
	employee e2("Wibit","The Frog");
	e1.setFirstName("Keith");
	e1.setLastName("Everitt");
	e1.setEmployeeID("135468");
	e1.setJobTitle("Software Engineer");
	e2.setEmployeeID("123456");
	e2.setJobTitle("Fly Eater");
	employee *e = new employee(*p);
	e->setEmployeeID("111222");
	e->setJobTitle("Doctor of Everything");
	
	cout << "Employee Name: " << e1.getFirstName() + " " + e1.getLastName() << endl;
	cout << "Employee ID  : " << e1.getEmployeeID() << endl;
	cout << "Job Title    : " << e1.getJobTitle() << endl << endl;
	cout << "Employee Name: " << e2.getFirstName() + " " + e2.getLastName() << endl;
	cout << "Employee ID  : " << e2.getEmployeeID() << endl;
	cout << "Job Title    : " << e2.getJobTitle() << endl << endl;
	cout << "Employee Name: " << e->getFirstName() + " " + e->getLastName() << endl;
	cout << "Employee ID  : " << e->getEmployeeID() << endl;
	cout << "Job Title    : " << e->getJobTitle() << endl << endl;
	delete p; delete e;
	return 0;
}