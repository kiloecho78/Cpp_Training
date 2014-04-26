#include <iostream>
using namespace std;

int main()
{
	char *myCString = "This is a CString"; //depreciated so use -w to suppress warnings
	string string1;
	string myString = "Hey there, Buddy!";
	cout << "myString.empty() = " << myString.empty() << endl; //returns boolean value that determines if the string is empty
	cout << "myString.max_size() = " << myString.max_size() << endl; //returns the maximum number of spaces for the string
	cout << "myString.capacity() = " << myString.capacity() << endl; //the number of bytes allocated for the string.
	
	for(int i = 0; i < myString.length(); i++)
		cout << myString[i] << endl;
	
	myString = myString + " How are you"; //appends string to end of myString
	myString += "?";	//also appends and sets value of myString to include '?'
	cout << myString << endl;
	
	myString.append(" I am fine."); //pretty much the same as += or + above
	cout << myString << endl;
	myString.erase(0,5);	//erases from first int for the 2nd int count
	cout << myString << endl;
	myString.insert(0, "Hey t");	//inserts new string starting at int
	cout << myString << endl;
	myString.replace(0,5, "HEY T");	//replaces from starting int to count 2nd int w/ new string
	cout << myString << endl;
	cout<< myString.find("There") << endl; //returns an int value of the first occurence of the string
	cout << myString.rfind("Buddy") << endl; //returns the int value of the last occurence of a string
	cout << myString.substr(4,4) << endl; //returns a portion of the string from 1st int start value for 2nd int count
	cout << myString.compare("Hey there, buddy!") << endl; //prints the boolean value of the comparison of myString to the input string. (= -1 b/c the strings are not equal)
		// creates empty string object named string1
	string string2("This is string 2");	//creates string object string2 that contains the string in ""
	string string3(myCString);	//creates string object string3 and inputs the value of myCString from above
	string1 = "This is String 1"; //fills in the value of string1 w/ the input string
	cout << string1 << " " << string2 << " " << string3 << endl;
	return 0;
}