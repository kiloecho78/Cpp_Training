#include<iostream>
using namespace std;

/*Shows basic input and output functinality
* include cin cout getline()
*/
int main()
{
	int x = 10;
	int y = 20, z;
	char karacter[128];
	string strang;
	cout << x << " + " << y << " = " << x+y << endl;  //doesn't need %d %f etc, uses << instead
	cout << "Please enter a value for z: "; // uneccessary to have endl at the end of this line, when you hit enter it goes to next line
	cin >> z;
	cout <<"x + y + z = " << x + y + z << endl;
	cout << "Write a bunch of text: ";
	cin.getline(karacter, 128);
	cout << "You typed: " << karacter << endl;
	cout << "Write a bunch of text: ";
	getline(cin, strang);
	cout << "You typed: " << strang << endl;
	
	return 0;
}
