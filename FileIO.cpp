#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

int main()
{
	ofstream outFile;
	char outFileName[256];
	char outFileData[256];
	char appendData = 'N';
	
	cout << "Set output file name: "; cin.getline(outFileName, 256);
	cout << "Append data (Y/N): "; cin.get(appendData); cin.ignore();
	cout << "Text to write to file: "; cin.getline(outFileData, 256);
	if(toupper(appendData)=='Y')
		outFile.open(outFileName, ios_base::app);
	else
		outFile.open(outFileName, ios_base::trunc);
	outFile << outFileData;
	cout << "\"" << outFileData << "\"" << endl;
	outFile.close();
	
	return 0;
}