#include<iostream>
#include<sstream>
using namespace std;

string convertIntegerToString(int num)
	{
		ostringstream oStream;
		oStream << num;
		return oStream.str();
	}

int main()
{
	
	int myNumber = 54321;
	istringstream iStream;
	// ACCOUNT# LASTNAME FIRSTNAME GENDER ACCTBAL
	iStream.str("123456 Everitt Keith M 1654.44");
	
	unsigned int accountNumber; //don't have to convert parts individually
	string lastName, firstName;	// so you can split up a string into different part types
	char gender;
	double accountBalance;
	
	iStream >> accountNumber >> lastName >> firstName >> gender >> accountBalance;
	
	cout << "Account Number :" << accountNumber << endl
		 << "Last Name      :" << lastName << endl
		 << "First Name     :" << firstName << endl
		 << "Gender         :" << gender << endl
		 << "Account Balance:" << accountBalance << endl;

	string myString = convertIntegerToString(myNumber);
	
	cout << myString << endl;
	
	/*The section from line 16-31 could also be reversed by doing the following:
		ostringstream OStream;
		unsigned int accountNUmber = 123456;
		string lastNAme = "Everitt", firstNAme = "Keith";
		char gEnder = 'M';
		double accountBAlance = 1654.44;
		
		oStream << accountNUmber << " " << lastNAme << " " 
			    << firstNAme << " " << gEnder << " " << accountBAlance;
		string recordString = oStream.str();
		cout << recordString << endl;
	*/
	
	return 0;
}