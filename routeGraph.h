#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <stdio.h> 
#include <ctype.h> 
using namespace std; 
  
class routeGraph 
{ 
    public: 
        routeGraph(); 
        ~routeGraph(); 
        void openFile(); 
        void createAirports(string airport); 
        void print(); 
        void bfs(int start, int target); 
        void printPath(int parents[], int size, int startVertex, int endVertex); 
        string getAirport(int id); 
        string findAirport(string str); 
        int getMax(); 
        int getIndex(string airport); 
        bool isNumber(string s); 
        bool inRange(int num); 
    private: 
        fstream file; 
        vector<int> alist[150]; 
        string airports[150]; 
        string line; 
        int airportIndex; 
          
          
}; 
  
routeGraph::routeGraph() 
{ 
    airportIndex = 0;  
}; 
  
routeGraph::~routeGraph(){  }; 
  
void routeGraph::openFile() 
{ 
    fstream file; 
    string filename = "connections.txt"; 
    string choice; 
    cout << "Open " << filename << " (Y:yes, N:no)? "; 
    getline(cin, choice); 
    if (choice.substr(0, 1) == "N" || choice.substr(0, 1) == "n") 
    { 
        cout << "please enter file dir: "; 
        getline(cin, filename); 
        file.open(filename); 
        while (!file.is_open()) 
        { 
            cout << "File does not exist." << endl; 
            cout << "Please enter file directory: "; 
            getline(cin, filename); 
            file.open(filename); 
        } 
    file.close(); 
    } 
      
    file.open(filename); 
    if (file.is_open()) 
    { 
        int i = 1; 
        int departureID = 0;  
        int destinationID = 0; 
        while (getline(file, line)) 
        { 
            if (line.at(0) == 'F') 
            { 
                line.erase(0, 7); 
                createAirports(line); 
                departureID = getIndex(line); 
            } 
            else if (line.at(0) == 'T' || line.at(0) == ' ') 
            { 
                line.erase(0, 7); 
                createAirports(line); 
                destinationID = getIndex(line); 
            } 
        cout << departureID << " " << destinationID << endl; 
            alist[departureID].push_back(destinationID); 
        } 
        file.close(); 
    } 
    else { 
        cout << "file does not exist ... ";  
          
    } 
      
} 
  
void routeGraph::createAirports(string airport) 
{ 
    bool inList = false; 
    if (airportIndex == 0) 
    { 
        airports[0] = airport; 
        airportIndex++;  
    } 
    else
    { 
        for (int i = 0; i <= airportIndex; i++) 
        { 
            if (airports[i] == airport) 
            {  
                inList = true; 
                break; 
            } 
        } 
        if (!inList) 
        { 
            airports[airportIndex] = airport;  
            airportIndex++; 
        } 
    } 
} 
  
void routeGraph::print() 
{ 
    int i = 0; 
    while (i < airportIndex) 
    { 
        cout << i << " " << airports[i] <<endl; 
        i++; 
    } 
} 
  
void routeGraph::bfs(int start, int target) 
{ 
    int * parents = new int[airportIndex]; 
    for (int i = 0; i< airportIndex; i++) parents[i] = -1; 
    parents[start] = start; 
    queue<int> q; 
    q.push(start); 
    bool found = false; 
    while (!q.empty() && !found) 
    { 
        int v = q.front(); 
        q.pop(); 
        if (v == target) 
            found = true; 
  
        else for (unsigned int i = 0; i < alist[v].size(); i++) 
        { 
            int w = alist[v][i]; 
            if (parents[w] == -1)  
            { 
                parents[w] = v; 
                q.push(w); 
            } 
        } 
    } 
    if (found) 
        printPath(parents, 10, start, target); 
    else
        cout << "Not found"; 
    cout << endl; 
    delete[] parents; 
} 
  
void routeGraph::printPath(int parents[], int size, int startVertex, int endVertex)  
{ 
    if (endVertex != startVertex) 
    { 
        printPath(parents, size, startVertex, parents[endVertex]); 
    } 
    cout <<" " << getAirport(endVertex) << endl; 
} 
  
string routeGraph::getAirport(int id) 
{ 
    if (id <= airportIndex) 
    {  
        return airports[id];  
    } 
    return "-1"; 
} 
  
string routeGraph::findAirport(string str) 
{ 
    int strlen = str.length(); 
    int i = 0;  string airport;  
    while (i < airportIndex) 
    { 
        airport = airports[i].substr(0, strlen); 
        for (int j = 0; j < strlen; j++){ 
            airport[j] = tolower(airport[j]); 
            str[j] = tolower(str[j]); 
            j++; 
        } 
        if (airport == str) 
         return airports[i];  
        i++; 
    } 
    return "-1"; 
} 
  
int routeGraph::getMax() 
{ 
    return airportIndex; 
} 
  
int routeGraph::getIndex(string airport) 
{ 
    int i = 0; 
    while (airports[i] != airport) 
    { 
        if (i > airportIndex) 
        {  
            return -1; 
        } 
        i++; 
    } 
    return i; 
} 
  
bool routeGraph::isNumber(string s) 
{ 
    for (unsigned int i = 0; i < s.length(); i++) 
    { 
        if (!isdigit(s[i])) 
         return false;  
    } 
    return true; 
} 
  
bool routeGraph::inRange(int num) 
{ 
    if (num >= 0 && num <= airportIndex) 
        return true;  
    return false; 
} 