#include "name.h"
#import<stdlib.h>
#import<string.h>

name :: name()
{
	_firstName = (char*)malloc(256);
	_lastName = (char*)malloc(256);
}

name :: ~name()
{
	free(_lastName);
	free(_firstName);
}

void name :: setFirstName(char *firstName)
{
	free(_firstName);
	_firstName = (char*)malloc(strlen(firstName)+1);
	strcpy(_firstName, firstName);
}

void name :: setLastName(char *lastName)
{
	free(_lastName);
	_lastName = (char*)malloc(strlen(lastName)+1);
	strcpy(_lastName, lastName);
}

char* name :: getFirstName()
{
	return _firstName;
}

char* name :: getLastName()
{
	return _lastName;
}