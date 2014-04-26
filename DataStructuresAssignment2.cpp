#include <iostream>
#include <string>
using namespace std;


//Problem 1
// Recursive binary search via pointers. If the target is found, return a pointer to it.
// Otherwise return NULL.
template <typename T>
int * binarySearch(T * firstPtr, T * lastPtr, const T &target)
{
	T * mid = firstPtr + ((lastPtr - firstPtr) / 2);

	if (firstPtr == lastPtr)
	{
		if (target == *firstPtr) {
			return firstPtr;
		}

		else
			return NULL;
	}
	if (target <= *mid) {
		return binarySearch(firstPtr, mid, target);
	}
	return binarySearch(mid + 1, lastPtr, target);
}
// Top-level binary search function. Calls the function above.
// Return index of target in values or -1, if target isn't found.
template <typename T>
int binarySearch(T values[], int size, const T &target) {
	int * loc = binarySearch(values, values + size - 1, target);
	return loc == NULL ? -1 : loc - values;
}

//Problem 2
// Compute midpoint of lowerBound and upperBound.
// If the midpoint is too big then make a recursive call with mid-1 as the new upper bound.
// Otherwise check whether or not midpoint qualifies as the answer and proceed accordingly.
// Hint: You only need six lines of code.
//int integerSqrt(unsigned int n, int lowerBound, int upperBound);
int integerSqrt(unsigned int n, int lowerBound, int upperBound)
{
	unsigned int mid = (upperBound - lowerBound);
	if (((mid*mid) <= n && (((mid + 1)*(mid + 1))>n)))
	{
		return mid;
	}
	return (((mid*mid)>n)) ? integerSqrt(n, lowerBound, (mid / 2 - 1)) : integerSqrt(n, lowerBound, mid + 1);
}

int integerSqrt(unsigned int n)
{
	return integerSqrt(n, 0, n);
}
// return k such that k*k <= n and (k+1)*(k+1)>n;
//int integerSqrt(unsigned int n) {
//return integerSqrt(n, 0, n);
//}

//Problem 3
// Return a string with the same characters as v and w arranged in nondescending order.
// Precondition: characters in v and in w are in nondescending order.
// You may call string member functions e.g. substr, +.
string spliceSortedStrings(string v, string w)
{
	string str1 = v.substr(0, 1);
	string str2 = w.substr(0, 1);

	if (str1 == "\0")
		return str2 == "\0" ? " " : w;
	if (str2 == "\0")
		return str1 == "\0" ? " " : v;

	if (str1.compare(str2) <= 0)
		return str1 + spliceSortedStrings(v.substr(1), w.substr(0));
	else
		return str2 + spliceSortedStrings(v.substr(0), w.substr(1));
}
//Problem 4
// If s.size()  <= 1 then return s.
// Otherwise split s in half, sort each half, then recombine using spliceSortedStrings() from Problem 3
// You may call the string member function substr() to split the string in two parts.
string sort(string s)
{
	if (s.size() <= 1)
		return s;
	int mid = s.size() / 2;
	string lside = s.substr(0, mid);
	string rside = s.substr(mid);
	string str1 = sort(lside);
	string str2 = sort(rside);
	string sorted = spliceSortedStrings(str1, str2);
	return sorted;
}

//Problem 5
//  Return the number of places where the characters of s and t aren't the same.
//  You may call string member functions, e.g. s[0].
int countDifferences(const string &s, const string &t, int diffCount)
{
	if (s[0] == 0)
		return diffCount += t.size();
	else if (t[0] == 0)
		return diffCount += s.size();

	if ((s[0] > t[0]) || (s[0] < t[0]))
	{
		diffCount++;
		return countDifferences(s.substr(1), t.substr(1), diffCount);
	}
	else
		return countDifferences(s.substr(1), t.substr(1), diffCount);
}

int countDifferences(const string &s, const string &t)
{
	return countDifferences(s, t, 0);
}

//Problem 6
// Return true if total can be made by adding some or all of the coins.
// Also return true if total is 0.
// Return false if total is negative or total > 0 and array is empty.
// Precondition: all coin values nonnegative.
// Hint: use the last coin or not --> 2 recursive calls
bool canMakeTotal(int coins[], int length, int total)
{
	if (total < 0){ return false; }
	if (total == 0){ return true; }
	if (length < 0){ return false; }
	if (coins[length] == total) { return true; }
	if (canMakeTotal(coins, length - 1, total))
	{
		if (length > 0)
		{
			return canMakeTotal(coins, length - 1, total);
		}
	}
	else if (total > coins[length])
	{
		total -= coins[length];
		return canMakeTotal(coins, length - 1, total);
	}
	return false;
}
/*Output:
0Y 1Y 2Y 3N 4N 5Y 6Y 7Y 8N 9N 10Y 11Y 12Y 13N 14N 15Y 16Y 17Y 18N 19N 20Y 21Y 22Y 23N */

//Problem 7
// Return true if small is a prefix of big.
// Note: empty string is a prefix of any string.
// No calls to any functions other than isPrefix().
// Precondition: small and big are null-terminated.
bool isPrefix(char small[], char big[])
{
	if (small[0] == NULL)
		return true;
	else if (big[0] == NULL)
		return false;
	return small[0] == big[0] && isPrefix(small + 1, big + 1);
}

// Return true if small is a substring of big.
// No calls to any functions other than isPrefix() and isSubstring().
// Precondition: small and big are null-terminated.
bool isSubstring(char small[], char big[])
{
	if (big[0] == NULL)
		return false;
	else if (small[0] == big[0])
		isPrefix(small, big);
	return isPrefix(small, big) || isSubstring(small, big + 1);
}

//Problem 8
// return index of the leftmost value in range lowerBound..upperBound
// return  -1 if there's no value in that range.
// e.g. findInRange({4,2,5,3,7,2},2,3} will return 1  (not 5 or 3).
// and  findInRange({4,2,5,3,7,2},0,1} will return -1.
int findInRange(int nums[], int length, int lowerBound, int upperBound)
{

	if (length == 1)
	{
		if (nums[length - 1] >= lowerBound && nums[length - 1] <= upperBound)
		{
			return length - 1;
		}
		return -1;
	}


	int loc = findInRange(nums, length - 1, lowerBound, upperBound);
	return loc >-1 ? loc : ((nums[length - 1] >= lowerBound && nums[length - 1] <= upperBound) ? loc = length - 1 : -1);
}

//Problem 9
// Replace all occurrences of oldChar in s by newChar.
// Precondition: s is null terminated.
// No function calls allowed except the recursive one.
void replaceCharacter(char s[], char oldChar, char newChar)
{
	if (s[0] == NULL)
		return;
	else if (s[0] == oldChar)
		s[0] = newChar;

	replaceCharacter(s + 1, oldChar, newChar);
	return;
}

int main()
{
	cout << "Keith Everitt     Data Structures Assignment 2       02/02/2014" << endl;
	//Problem 1
	cout << "Problem 1:" << endl;
	int nums1[] = { 1, 3, 5, 7, 9, 11, 13, 17, 18, 20, 21 };
	for (int i = 0; i < 23; i++)
		cout << i << "\t" << binarySearch(nums1, 11, i) << endl;
	//Problem 2
	cout << endl << "Problem 2:" << endl;
	int final = integerSqrt(10);
	cout << final << endl;
	//Problem 3
	cout << endl << "Problem 3:" << endl;
	string first = "acegx";
	string second = "bcfjkltz";
	cout << spliceSortedStrings(first, second) << endl;
	//Problem 4
	cout << endl << "Problem 4:" << endl;
	string thirteen = "tristadecaphobia";
	cout << sort(thirteen) << endl;
	//Problem 5
	cout << endl << "Problem 5:" << endl;
	cout << countDifferences("a", "abc") << endl;     // output 2
	cout << countDifferences("abc", "a") << endl;      // output 2
	cout << countDifferences("abc", "abc") << endl;        // output 0
	cout << countDifferences("xbc", "abx") << endl;        // output 2
	cout << countDifferences("abab", "baba") << endl;  // output 4
	cout << countDifferences("green", "trees") << endl;     // output 2
	//Problem 6
	cout << endl << "Problem 6:" << endl;
	int nums6[] = { 0, 0, 0 };
	for (int i = 1; i < 4; i++)
	{
		nums6[0] = i;
		for (int j = 1; j < 4; j++)
		{
			nums6[1] = j;
			for (int k = 1; k < 4; k++)
			{
				nums6[2] = k;
				cout << "Coins are {" << nums6[0] << ", " << nums6[1] << ", " << nums6[2] << "}: ";
				for (int l = 0; l < 11; l++)
				{
					cout << l << (canMakeTotal(nums6, 3, l) ? "Y" : "N") << " ";
				}
				cout << endl;
			}
		}
		cout << endl;
	}
	//problem 7
	cout << endl << "Problem 7:";
	char sm[] = "settle";
	char big[] = "settlement";
	cout << endl << (isPrefix(sm, big) ? "True" : "False") << endl;
	char sma[] = "bred";
	char bg[] = "abcbredh";
	cout << (isSubstring(sma, bg) ? "True" : "False") << endl;
	//Problem8
	cout << endl << "Problem 8:" << endl;
	int theArray[] = { 4, 2, 5, 3, 7, 2 };
	cout << findInRange(theArray, 6, 2, 3) << endl;
	cout << findInRange(theArray, 6, 0, 1) << endl;
	//Problem 9
	cout << endl << "Problem 9:" << endl;
	char findReplace[] = "rU-rah-rah";
	char find = 'r';
	char replace = 'R';
	replaceCharacter(findReplace, find, replace);
	for (int i = 0; i < 11; i++)
	{
		cout << findReplace[i];
	}
	cout << endl;
	return 0;
}
