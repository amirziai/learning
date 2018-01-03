#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n, type, value;
    string name;
    cin >> n;
    map<string, int> x;
    vector<int> q;

    for (int i=0; i < n; i++) {
    	cin >> type;
        cin >> name;

        if (type == 1) {
            cin >> value;
            if (x.find(name) == x.end()) x.insert(make_pair(name, value));
            else x[name] += value;
        } 
        else if (type == 2) x.erase(name);
    	else q.push_back((x.find(name) == x.end() ? 0 : x[name]));
    }

    for (int i=0; i < q.size(); i++) {
    	cout << q[i] << endl;
    }

    return 0;
}
