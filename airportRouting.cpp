#include <iostream> 
#include <fstream> 
#include <string> 
#include<cstdlib> 
#include "routeGraph.h" 
using namespace std; 
  
string departCue = "Enter your departure airport name or number: "; 
string destinationCue = "Enter your destination airport name or number: "; 
string listCue = "(You can enter '?' for help or 'Q' to exit): "; 
string confirmationCue = "Is this the correct airport?"; 
string choiceY_N = " (Y:Yes/N:No)? "; 
  
bool confirm(routeGraph &alist, int dep) 
{ 
    string selection;  
    bool isValid = false; 
    cout << endl << confirmationCue; 
    cout <<"\t" <<alist.getAirport(dep) << endl; 
    cout << choiceY_N; 
    getline(cin, selection); 
    if (selection.substr(0, 1) == "Y" || selection.substr(0, 1) == "y") 
    { 
        isValid = true; 
    } 
    else 
     isValid = false;  
    return isValid; 
} 
  
int main() 
{ 
    routeGraph alist; 
    alist.openFile(); 
    string input, fullname,errorMessage; 
    int dep, dest; 
    bool isValid = false; 
    do
    { 
        do
        { 
            cout << errorMessage << endl; 
            cout << departCue << endl; 
            cout << listCue; 
            getline(cin,input); 
            if (input == "?") 
            { 
                alist.print(); 
                cout << endl << departCue;       
                getline(cin, input); 
            } 
            if (input == "Q" || input == "q") 
                return 0; 
            if (alist.isNumber(input)) 
            { 
                dep = stoi(input); 
                if (alist.inRange(dep)) 
                 isValid = confirm(alist, dep);  
                else
                { 
                    errorMessage="Input invalid \nPlease try again. \n"; 
                    isValid = false;  
                } 
            } 
            else if (alist.findAirport(input) != "-1") 
            { 
                fullname = alist.findAirport(input); 
                dep = alist.getIndex(fullname); 
                isValid = confirm(alist,dep); 
            } 
            else
                errorMessage = "Invalid input \nPlease,try again."; 
        }  
        while (!isValid); 
        errorMessage = ""; 
        do{ 
            cout << errorMessage << endl; 
            cout << "Departing from " << alist.getAirport(dep) << endl << endl; 
            cout << destinationCue << endl; 
            cout << listCue; 
            getline(cin, input); 
            if (input == "?") 
            { 
                alist.print(); 
                cout << endl << destinationCue;      
                getline(cin, input); 
            } 
            if (input == "Q" || input == "q") 
             return 0;  
            if (alist.isNumber(input)) 
            { 
                dest = stoi(input); 
                if (alist.inRange(dest)) 
                    isValid = confirm(alist, dest);  
                else
                {  
                    errorMessage= "Invalid input. \n Please try again. \n";  
                    isValid = false;  
                } 
            } 
            else if (alist.findAirport(input) != "-1") 
            { 
                fullname = alist.findAirport(input); 
                dest = alist.getIndex(fullname); 
                isValid = confirm(alist, dest); 
            } 
            else
                errorMessage= "Invalid input \nPlease,try again."; 
              
        }  
        while (!isValid); 
        errorMessage = ""; 
        cout << endl << "Departing from " << alist.getAirport(dep) << " to " << alist.getAirport(dest) << ". " << endl << endl; 
        cout << "The shortest route is: " << endl << endl; 
        alist.bfs(dep, dest); 
        cout << endl << "Would you like to check another route?: " << endl << choiceY_N;         
        getline(cin, input); 
    }  
    while (input !="Q"&& input!="q"&&input !="N"&&input !="n"&&input !="no"&&input !="No"&&input !="nO"&&input !="NO"); 
    return 0; 
} 