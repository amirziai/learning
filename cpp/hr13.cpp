#include <iostream>
using namespace std;

int binary_search(int* x, int val, int start, int end) {
	if ((end - start) <= 1) {
		if (x[start] == val) return start;
		else if (x[end] == val) return end;	
		else return -1;	
	} else {
		int mid = start + (end - start) / 2;

		if (x[mid] == val) return mid;
		else if (x[mid] > val) return binary_search(x, val, start, mid - 1);
		else return binary_search(x, val, mid + 1, end);
	}
}

int main() {
	int x[4] = {1, 2, 3, 5};
	cout << (binary_search(x, 2, 0, 3) == 1) << endl;
	cout << (binary_search(x, 3, 0, 3) == 2) << endl;
	cout << (binary_search(x, 5, 0, 3) == 3) << endl;
	cout << (binary_search(x, 1, 0, 3) == 0) << endl;

	int y[5] = {1, 10, 11, 12, 13};
	cout << (binary_search(y, 13, 0, 4) == 4) << endl;
	cout << (binary_search(y, 2, 0, 4) == -1) << endl;
	cout << (binary_search(y, 11, 0, 4) == 2) << endl;
	cout << (binary_search(y, 12, 0, 4) == 3) << endl;

	return 0;
}