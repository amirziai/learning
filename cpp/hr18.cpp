#include <iostream>
#include <iomanip> 
#include <string>
#include <math.h>
using namespace std;

string hex(int a) {
	if (a <= 16) return to_string(a);
	else {
		string quo = to_string(a / 16);
		int rem = a % 16;
		return quo + hex(rem);
	}
}

void process_a(double a) {
	cout << left << "0x" + hex(int(a)) << endl;
}

void process_b(double b) {
	cout << setfill('_') << setw(15) << showpos << right << b << endl;
}

void process_c(double c) {
	cout << noshowpos << scientific << setprecision(9) << c << endl;
}

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		cout << left << hex << showbase << nouppercase << long(A) << endl;
		cout << fixed << showpoint << setfill('_') << setw(15) << showpos << setprecision(2) << right << B << endl;
		cout << noshowpos << scientific << uppercase << setprecision(9) << C << endl;
	}

	return 0;
}
