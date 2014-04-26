#include "num.h"

num :: num()
{
	_number = 0;
}

num :: num(int val)
{
	setValue(val);
}

num :: num(double val)
{
	setValue(val);
}

num :: num(char val)
{
	setValue(val);
}

void num :: setIntegerValue(int number)
{
	_number = (double)number;
}

void num :: setDoubleValue(double number)
{
	_number = number;
}

void num :: setCharValue(char ch)
{
	_number = (double)ch;
}

int num :: integerValue()  //Called if you want the integer value stored in _number
{
	return (int)_number;
}

double num :: doubleValue() //Called if you want the double value stored in _number
{
	return _number;
}

char num :: charValue() //Called if you want the character value stored in _number
{
	return (char)_number;
}

void num :: setValue(int val)
{
	setIntegerValue(val);
}

void num :: setValue(double val)
{
	setDoubleValue(val);
}

void num :: setValue(char val)
{
	setCharValue(val);
}
