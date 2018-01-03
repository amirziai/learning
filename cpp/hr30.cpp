#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main() {
	int n, q;
	string tmp;
	cin >> n >> q;
	cout << n << " " << q << endl;

	// Why is this necessary?
	cin.ignore();

	while (n--) {
		getline(cin, tmp);
		cout << tmp << endl;
	}

	return 0;
}
