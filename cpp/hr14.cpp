#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> x, int val, int start, int end) {
	if (end == start) {
		if (x[end] == val) {
			cout << "yes ";
			return start;
		} else {
			cout << "no ";
			return start + 1;
		}
	}
	else if ((end - start) == 1) {
		cout << start << " " << end << endl;
		if (x[start] == val) {
			cout << "yes ";
			return start;
		}
		else if (x[end] == val) {
			cout << "yes ";
			return end;
		}
		else {
			cout << "no ";
			return end;
		}
	} else {
		int mid = start + (end - start) / 2;

		if (x[mid] == val) {
			cout << "yes ";
			return mid;
		}
		else if (x[mid] > val) return binary_search(x, val, start, mid - 1);
		else return binary_search(x, val, mid + 1, end);
	}
}

int main() {
	vector<int> x;
	x.push_back(1);
	x.push_back(2);
	x.push_back(5);
	x.push_back(6);
	cout << binary_search(x, 2, 0, 3) + 1 << endl;

	return 0;
}
