
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
#include <iostream>
#include <cstring>
#include <cstdlib>

using std::ofstream;
using namespace std;

// global variables
int keywords = 0, identifiers = 0, specials = 0; // used to count each token type
int miscellaneous = 0, digits = 0, characters = 0; // same as above

/*** reads tokens from inFile using the string tokenizer
 *** placing them in the token array and returning the number 
 *** of tokens read
 ***/

int readTokens(ifstream &inFile, char *tokens[]) { 

	char line[80];      // char array used to hold lines of text input
	char *tokenPtr;     // pointer used to tokenize string
	int tokenCount = 0;
	
	while (inFile.getline(line, 80)) {   	// reads up to 80 chars into line array
		//cout << "line = " << line << endl;  

		tokenPtr = strtok( line, " ");   	// assigns tokenPtr to  first token in line
		while (tokenPtr != NULL) {   
			//cout << tokenPtr << endl;
			tokens[tokenCount] = new char[strlen(tokenPtr+1)];  	// allocate space for token
			strcpy(tokens[tokenCount++],tokenPtr);			// copy token to tokens array
			tokenPtr = strtok( NULL, " ");	// gets next token from line 
		} // while
	} // end while
	return tokenCount;
}  // end readTokens
	

/*** sorts tokens into categories
 ***/

void sortTokens(char *tokens[], int tokenCount) {
		
	for(int i=0; i < tokenCount; i++)
		//cout << "Token " << i <<": " << tokens[i] << endl;
		if (strcmp("begin",tokens[i]) == 0 || strcmp("cout",tokens[i]) == 0 || strcmp("for",tokens[i]) == 0 || strcmp("end",tokens[i]) == 0)
			keywords++;
		else if (strcmp("int",tokens[i]) == 0 || strcmp("double",tokens[i]) == 0)
			identifiers++;
		else if (strcmp(";",tokens[i]) == 0 || strcmp("(",tokens[i]) == 0 || strcmp(")",tokens[i]) == 0 || strcmp("{",tokens[i]) == 0 || strcmp("}",tokens[i]) == 0
			 || strcmp("=",tokens[i]) == 0 || strcmp("<",tokens[i]) == 0 || strcmp("++",tokens[i]) == 0 || strcmp("<<",tokens[i]) == 0 || strcmp("\"",tokens[i]) == 0)
			specials++;
		else if (strcmp("0",tokens[i]) == 0 || strcmp("2",tokens[i]) == 0 || strcmp("4",tokens[i]) == 0 || strcmp("6",tokens[i]) == 0 || strcmp("7",tokens[i]) == 0
			 || strcmp("1",tokens[i]) == 0 || strcmp("3",tokens[i]) == 0 || strcmp("5",tokens[i]) == 0 || strcmp("8",tokens[i]) == 0 || strcmp("9",tokens[i]) == 0)
			digits++;
		else if (strcmp("i",tokens[i]) == 0 || strcmp("x",tokens[i]) == 0)
			characters++;
		else
			miscellaneous++;

}  // end sortTokens

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
	
	sortTokens(tokens, tokenCount);
	
	cout << "Total keywords found ----: " << keywords << "\n";
	cout << "Total identifiers found -: " << identifiers << "\n";
	cout << "Total specials found ----: " << specials << "\n";
	cout << "Total digits found ------: " << digits << "\n";
	cout << "Total characters found --: " << characters << "\n";
	cout << "Total miscellaneous found: " << miscellaneous << "\n";
		
	return 0;
} // end main

