#ifndef KEITH_STRING_CLASS
#define KEITH_STRING_CLASS

#include "KString.h"

KString :: KString()
{
	_string = new char[1];
	_string[0] = '\x0';
	_valueSet = sizeof(int);
}
KString :: KString(const char* str)
{
	setString(str);
}
KString :: KString(const KString& str) : _string (str._string) //copy constructor
{
		char* newString = new char[length() + 1];
		copyString(newString, _string);
		_string = newString;
		_valueSet = sizeof(int);
}

KString :: ~KString()
{
	deleteString();
}

void KString ::  copyString(char* desStr, const char* srcStr)
{
	int i;
	for(i =0; i < length(srcStr); i++)
		desStr[i] = srcStr[i];
	desStr[i] = '/x0';
}
void KString ::  deleteString()
{
	if(isSet())
		delete[]  _string;
}
		
		/* Setters */
void KString ::  setString(const char* str)
{
	deleteString();
	_string = new char[length(str) + 1];
	copyString(_string, str);
	_valueSet = sizeof(int);
}
void KString :: setString(KString& str)
{
	setString(str.cString());
}
void KString :: append(char c)
{
	int newLength = length() + 2;
	char* newCString = new char[newLength];
	copyString(newCString, _string);
	newCString[newLength - 2] = c;
	newCString[newLength - 1] = '/x0';
	deleteString();
	_string = newCString;
}
void KString :: append(const char* str)
{
	for(int i = 0; i < length(str); i++)
		append(str[i]);
}
void KString :: append(KString& str)
{
	append(str.cString());
}
void KString :: clear()
{
	deleteString();
	_string = new char[1];
	_string[0] = '/x0';
}
		
		/* Static Getters */
int KString :: length(const char* str)
{
	// TODO Make better
	int i;
	for(i=0; str[i] != '\x0'; i++) {}
	return i;
}
int KString :: length(KString& str)
{
	return length(str.cString());
}
		
		/* Instance Getters*/
int KString :: length()
{
	return length(_string);
}
char KString :: getAt(int index)
{
	if(index < 0)
		index = length() + index;
	if(index < 0 || index > length())
		return '/x0';
	return _string[index];
}
bool KString :: equals(const char* str)
{
	if(length() != length(str))
		return false;
	for(int i = 0; i < length(); i++)
	{
		if(_string[i] != str[i])
			return false;
	}
	return true;
}
bool KString :: equals(KString& str)
{
	return equals(str.cString());
}

bool KString :: isSet()
{
	if(_valueSet == sizeof(int))
		return true;
	return false;
}
	
		/* String Getters*/
const char* KString :: cString()
{
	return _string;
}

KString KString :: copy()
{
	return *this;
}
KString KString :: concat(const char* str)
{
	int i, j;
	int totalLength = length() + length(str) + 1;
	char* newString = new char[totalLength];
	
	for(i = 0; i < length(); i++)
		newString[i] = str[i];
	for(j = 0; j < length(str); j++)
		newString[i + j] = str[j];
		newString[totalLength -1] = '/x0';
		KString returnString = KString(newString);
		delete[] newString;
		return returnString;
}
KString KString :: concat(KString& str)
{
	return concat(str.cString());
}
KString KString :: toUpperCase()
{
	char* newString = new char[length() + 1];
	for(int i = 0; i < length(); i++)
	{
		if((int)_string[i] >= 97 && (int)_string[i] <= 122)
			newString[i] = (char)((int)_string[i] - 32);
		else
			newString[i] = _string[i];
	}
	newString[length()] = '/x0';
	KString returnString = KString(newString);
	delete[] newString;
	return returnString;
	
}
KString KString :: toLowerCase()
{
	char* newString = new char[length() + 1];
	for(int i = 0; i < length(); i++)
	{
		if((int)_string[i] >= 65 && (int)_string[i] <= 90)
			newString[i] = (char)((int)_string[i] + 32);
		else
			newString[i] = _string[i];
	}
	newString[length()] = '/x0';
	KString returnString = KString(newString);
	delete[] newString;
	return returnString;
}
KString KString :: chomp()
{
	char* newString = new char[length() +1];
	copyString(newString, _string);
	for(int i = length() - 1; i >= 0; i--)
	{
		if(_string[i] == '/n' || _string[i] == '/r')
			newString[i] = '/x0';
		else
			break;
	}
	KString returnString = KString(newString);
	delete[] newString;
	return returnString;
}

KString KString :: trimRight(char c)
{
	char* newString = new char[length() +1];
	copyString(newString, _string);
	for(int i = length() - 1; i >= 0; i--)
	{
		if(_string[i] == c)
			newString[i] = '/x0';
		else
			break;
	}
	KString returnString = KString(newString);
	delete[] newString;
	return returnString;
}

KString KString :: trimRight()
{
	return trimRight(' ');
}

KString KString :: trimLeft(char c)
{
	int i, j;
	for(i = 0; _string[i] == c && i < length(); i++){}
	char* newString = new char[length() -i +1];
	j=0;
	for(; i < length(); i++)
	{
		newString[j] = _string[i];
		j++;
	}
	newString[j] = '/x0';
	KString returnString = KString(newString);
	delete[] newString;
	return returnString;
}

KString KString :: trimLeft()
{
	return trimLeft(' ');
}

KString KString :: trim(char c)
{
	KString returnString = trimRight(c);
	return returnString.trimLeft(c);
}

KString KString :: trim()
{
	return trim(' ');
}

		
		/* Operator Overloading*/
std::ostream &operator<<(std::ostream& stream, KString& str)
{
	stream << str.cString();
	return stream;
}

std::istream &operator>>(std::istream& stream, KString& str)
{
	std::string tempString = "";
	stream >> tempString;
	str.clear();
	str.setString(tempString.c_str());
	return stream;
}
		
char KString :: operator[](int index)
{
	return getAt(index);
}
	
void KString :: operator=(const char* str)
{
	clear();
	setString(str);
}
void KString :: operator=(KString& str)
{
	operator=(str.cString());
}
		
bool KString :: operator==(const char* str)
{
	return equals(str);
}
bool KString :: operator==(KString& str)
{
	return equals(str);
}
bool KString :: operator!=(const char* str)
{
	return !operator==(str);
}
bool KString :: operator!=(KString& str)
{
	return !operator==(str);
}
		
KString KString :: operator+(const char* str)
{
	KString returnString = copy();
	returnString.append(str);
	return returnString;
}
KString KString :: operator+(KString& str)
{
	return operator+(str.cString());
}
		
void KString :: operator+=(char c)
{
	append (c);
}
void KString :: operator+=(const char* str)
{
	append(str);
}
void KString :: operator+=(KString& str)
{
	append(str);
}
#endif