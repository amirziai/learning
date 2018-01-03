#include <iostream>

using namespace std;

string timeConversion(string s) {
    // Complete this function
    if (s.substr(8, 2) == "AM") {
    	if (s.substr(0, 2) == "12") {
    		return "00" + s.substr(2, 6);
    	} else return s.substr(0, 8);
    } else {
    	int hour = atoi(s.substr(0, 2).c_str());
    	int addition = (hour == 12) ? 0 : 12;
    	return to_string(hour + addition) + s.substr(2, 6);
    }
}

int main() {
	string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;

	return 0;
}
