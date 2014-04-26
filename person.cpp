#include "person.h"
person::person(){}
person::person(string firstName, string lastName)
{
	setFirstName(firstName);
	setLastName(lastName);
}
void person :: setFirstName(string firstName)
{
	_firstName = firstName;
}

void person :: setLastName(string lastName)
{
	_lastName = lastName;
}

string person :: getLastName()
{
	return _lastName;
}

string person :: getFirstName()
{
	return _firstName;
}