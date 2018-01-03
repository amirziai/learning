#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main() {
    int n, q;
    map<string, string> m;
    vector<string> reference;
    string tmp, token;

    while (n--) {
    	cin >> tmp;
    	if (tmp[1] == '/') {
    		reference.pop_back();
    	} else {
    		stringstream ss(tmp);
			while (ss >> token) {
				if (token[0] == '<') {
					token.erase(0, 1);
					reference.push_back(token);
				}
				v.push_back(i);
				if (ss.peek() == ',') ss.ignore();
			}
    	}
    }

    while (q--) {
    	cin >> tmp;
    	cout << map[tmp] << endl;
    }


    return 0;
}
