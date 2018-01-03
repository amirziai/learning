#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binary_search(vector<int> x, int val, int start, int end) {
	// cout << start << "-" << end << endl;
	if (end == start) {
		if (x[end] == val) {
			cout << "Yes ";
			return start;
		} else {
			cout << "No ";
			return start;
		}
	}
	else if ((end - start) == 1) {
		if (x[start] == val) {
			cout << "Yes ";
			return start;
		}
		else if (x[end] == val) {
			cout << "Yes ";
			return end;
		}
		else {
			cout << "No ";
			return end;
		}
	} else {
		int mid = start + (end - start) / 2;

		if ((x[mid] == val && mid == 0) || (x[mid] == val && mid > 0 && x[mid] != x[mid - 1])) {
			cout << "Yes ";
			return mid;
		}
		else if (x[mid] >= val) {
			if (mid == 0) {
				cout << "No ";
				return mid;
			} 
			else if (x[mid] >= val and x[mid - 1] < val) {
				cout << "No ";
				return mid;
			}
			else return binary_search(x, val, start, mid - 1);
		}
		else {
			if (mid == x.size()) {
				cout << "No ";
				return mid;
			}
			else if (x[mid] < val && x[mid + 1] > val) {
				cout << "No ";
				return mid + 1;
			}
			else if (mid > 0 && x[mid] > val && x[mid - 1] < val) {
				cout << "No ";
				return mid;
			}
			else return binary_search(x, val, mid + 1, end);
		} 
	}
}

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
		cout << binary_search(x, q[i], 0, x.size() - 1) + 1 << endl;
	}
	// cout << binary_search(x, 4, 0, x.size() - 1) + 1 << endl;

    return 0;
}
