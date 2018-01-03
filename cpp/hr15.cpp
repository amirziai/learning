#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int n, no_q, tmp;
	vector<int> x, q;

	cin >> n;
	for (int i=0; i < n; i++) {
		cin >> tmp;
		x.push_back(tmp);
	}

	cin >> no_q;

	for (int i=0; i < no_q; i++) {
		cin >> tmp;
		q.push_back(tmp);
	}

	for (int i=0; i < no_q; i++) {
		vector<int>::iterator low = lower_bound(x.begin(), x.end(), q[i]);
		int pos = low - x.begin();
		cout << (x[pos] == q[i] ? "Yes " : "No ") << pos + 1 << endl;
	}

    return 0;
}