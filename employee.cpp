#include "employee.h"
employee :: employee() {}
employee :: employee(string firstName, string lastName) : person(firstName, lastName) {}
employee :: employee(person p)
{
	_firstName = p.getFirstName();
	_lastName = p.getLastName();
} 

void employee :: setEmployeeID(string employeeID)
{
	_employeeID = employeeID;
}

void employee :: setJobTitle(string jobTitle)
{
	_jobTitle = jobTitle;
}

string employee :: getEmployeeID()
{
	return _employeeID;
}

string employee :: getJobTitle()
{
	return _jobTitle;
}