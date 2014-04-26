#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

long getFileSize(ifstream *file)
{
	file -> seekg(0, ios::end);
	long lengthOfFile = file -> tellg();
	file -> seekg(0, ios::beg);
	return lengthOfFile;
}

int main(int argc, const char* argv[])
{
	ifstream inputFile;
	char* fileData = NULL;
	inputFile.open(argv[1]);
	long fileSize = getFileSize(&inputFile);
	fileData = (char*)calloc(fileSize, 8);
	inputFile.read(fileData, fileSize);
	cout<<fileData<<endl;
	inputFile.close();
	free(fileData);
	return 0;
}