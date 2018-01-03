#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int n, type, value;
    cin >> n;
    set<int> x;
    vector<bool> q;

    for (int i=0; i < n; i++) {
    	cin >> type;
    	cin >> value;

    	if (type == 1) x.insert(value);
    	else if (type == 2) x.erase(value);
    	else q.push_back((x.find(value) == x.end() ? false : true));
    }

    for (int i=0; i < q.size(); i++) {
    	cout << (q[i] == true ? "Yes" : "No") << endl;
    }

    return 0;
}
