#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	int n, tmp, single, r1, r2;
	vector<int> x;

	cin >> n;
	for (int i=0; i < n; i++) {
		cin >> tmp;
		x.push_back(tmp);
	}

	cin >> single;
	x.erase(x.begin() + single - 1);
	cin >> r1;
	cin >> r2;
	x.erase(x.begin() + r1 - 1, x.begin() + r2 - 1);

	cout << x.size() << endl;
	for (int i=0; i < x.size() ; i++) {
		cout << x[i] << " ";
	}

    return 0;
}
