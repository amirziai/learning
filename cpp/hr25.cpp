#include <iostream>
#include <string>
using namespace std;

string super_reduced_string(string s) {
	if (s.size() == 0) return "Empty String";
	for (int i=1; i < s.size(); i++) {
		if (s[i - 1] == s[i]) {
			s.erase(i - 1, 2);
			return super_reduced_string(s);
		}
	}
	return s;
}

int main() {
	string xs;
	cin >> xs;

	cout << super_reduced_string(xs) << endl;


	return 0;
}
