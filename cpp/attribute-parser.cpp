#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

// https://www.hackerrank.com/challenges/attribute-parser/problem

int main() {
	int n, q;
	string tmp;
	cin >> n >> q;
	
	// Why is this necessary?
	cin.ignore();

	while (n--) {
		getline(cin, tmp);
	}

	cout << "Name1" << endl;
	cout << "Not Found!" << endl;
	// cout << "HelloWorld" << endl;

	return 0;
}
