#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <sstream>  
using namespace std;

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
 
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
 
  return internal;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int number_arrays, number_queries;
    cin >> number_arrays;
    cin >> number_queries;

    vector<int> arrays[number_arrays];

    cout << "Number of arrays:" << number_arrays << endl;

    for (int i = 0; i < number_arrays; i++) {
    	int index = 0;
    	string line;
    	getline(cin, line, ' ');
		vector<string> lineSplit = split(line, ' ');
		cout << "hi" << endl;
		for (int j = 0; j < lineSplit.size(); j++) {
			int val = atoi(lineSplit[j].c_str());
			cout << val << endl;
			if (j > 0) arrays[i].push_back(val);
		}
    }

    for (int i = 0; i < number_queries; i++) {
    	string line;
    	getline(cin, line, ' ');
    	vector<string> lineSplit = split(line, ' ');
    	cout << arrays[atoi(lineSplit[0].c_str())][atoi(lineSplit[1].c_str())] << endl;
    }
    
    return 0;
}
