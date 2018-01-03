#include <iostream>
#include <vector>
#include <set>

using namespace std;

template<typename C>
bool lastGreaterThanFirst(const C& container) {
	if (container.empty()) return false;

	typename C::const_iterator begin(container.begin());
	typename C::const_iterator end(container.end());

	return *--end > *begin;
}

int main() {
	vector<int> x;
	x.push_back(2);
	x.push_back(1);
	x.push_back(10);
	bool answer = lastGreaterThanFirst(x);
	cout << answer << endl;

	set<int> y;
	y.insert(1);
	y.insert(2);
	y.insert(3);
	y.insert(0);
	y.insert(1);
	y.insert(1);
	y.insert(1);
	cout << lastGreaterThanFirst(y) << endl;

	return 0;
}
