#include <iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

int main()
{
	int max_Length = 0;
	string longestWord;
	string secondLongest;
	string currentWord;
	ifstream theFile;
	theFile.open("dictionaryTest.txt");
	if (!theFile.is_open())
	{
		cout << "Error whie opening file\n" << endl;
	}
	else if (theFile.is_open())
	{
		while (getline(theFile, currentWord))
		{
			if (currentWord.length() >= max_Length)
			{
				secondLongest = longestWord;
				longestWord = currentWord;
				max_Length = currentWord.length();
			}
			else if (currentWord.length() > secondLongest.length())
			{
				secondLongest = currentWord;
			}
			else
				continue;
		}
	}
	else
	{
		cout << "Error of unknown type" << endl;
	}

	cout << "The longest word is: " << longestWord << endl << "The second longest word is: " << secondLongest << endl;
	system("pause");
	theFile.close();

	return 0;
}