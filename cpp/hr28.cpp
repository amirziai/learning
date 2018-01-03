#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
   // Complete this function
	vector<int> v;
	int i;

	stringstream ss(str);
	while (ss >> i) {
		v.push_back(i);
		if (ss.peek() == ',') ss.ignore();
	}

	return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
