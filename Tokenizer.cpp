
// file: TokenReader.cpp
// Example program to demonstrate the following in C++:
//    command line arguments
//    reading from a text file
//    using the string tokenizer
//    dynamically allocating an array of strings
//    searching an array of strings
//
// Source: C++ How to Program, 3rd ed. by Deitel & Deitel

#include <fstream>
using std::ofstream;

#include <iostream>
//using std::cout;
//using std::endl;

#include <cstring>
#include <cstdlib>

using namespace std;


/*** reads tokens from inFile using the string tokenizer
 *** placing them in the token array and returning the number 
 *** of tokens read
 ***/
int readTokens(ifstream &inFile, char *tokens[]) { 

	char line[80];      // char array used to hold lines of text input
	char *tokenPtr;     // pointer used to tokenize string
	int tokenCount = 0;
	
	while (inFile.getline(line, 80)) {   	// reads up to 80 chars into line array
		cout << "line = " << line << endl;  

		tokenPtr = strtok( line, " ");   	// assigns tokenPtr to  first token in line
		while (tokenPtr != NULL) {   
			cout << tokenPtr << endl;
			tokens[tokenCount] = new char[strlen(tokenPtr+1)];  	// allocate space for token
			strcpy(tokens[tokenCount++],tokenPtr);			// copy token to tokens array
			tokenPtr = strtok( NULL, " ");	// gets next token from line 
		} // while
	} // end while
	return tokenCount;
}  // end readTokens
	

/*** displays the contents of the token array
 ***/

void printTokens(char *tokens[], int tokenCount) {
		
	for(int i=0; i < tokenCount; i++)
		cout << "Token " << i <<": " << tokens[i] << endl;

}  // end printTokens
	

/*** searches the tokens array for searchString
 *** returning its position, or -1 if not found
 ***/
int searchTokens(char *searchString, char *tokens[], int tokenCount) {

	for(int  i=0; i < tokenCount; i++)
		if (strcmp(searchString,tokens[i]) == 0)   
			return i;
	return -1;
	
}
int main(int argc, char *argv[]) 
{

	char *tokens[50];   // array of pointers to point to up to 50 tokens
	int tokenCount = 0; // used to count tokens as they are read 
	int position = -1; // used to hold the position of search token 
	char searchString[50];    // used to hold string to search for
	
	// at least one command line argument should be supplied
	if (argc < 2) {  
		cerr << "Error: file name argument not given" << endl;
		exit(1);
	}

	ifstream inFile( argv[1], ios::in);  // open file for input

	// checks for errors in opening the file
	if (!inFile) { 	
		cerr << "File " << argv[1] << " could not be opened" << endl;
		exit(1);
	}
	
	tokenCount = readTokens(inFile, tokens);  
	
	inFile.close();
	
	printTokens(tokens, tokenCount);
	
	cout << "Token to search for: ";
	cin >> searchString;
	
	position = searchTokens(searchString, tokens, tokenCount);
	
	if (position >= 0)
		cout << searchString << " found at position "<< position << endl;
	else
		cout << searchString << " was not found "<< endl;

	return 0;
} // end main

