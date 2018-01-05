#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

// https://www.hackerrank.com/challenges/attribute-parser/problem

int main() {
	int n, q;
	string tmp;
	vector<string> s;
	map<string, string> m;

	cin >> n >> q;
	
	// http://www.cplusplus.com/reference/istream/istream/ignore/
	cin.ignore();

	while (n--) {
		getline(cin, tmp);
		
		if (tmp[1] == '/') {
			s.pop_back();
		} else {
			stringstream ss(tmp);
			string buf;
			int count = 0;
			string key;
			while (ss >> buf) {
				// cout << buf << endl;

				if (count == 0) {
					buf.erase(0, 1);
					if (buf[buf.size() - 1] == '>')
						buf.erase(buf.size() - 1, buf.size());
					s.push_back(buf);
				} else {
					if ((count - 1) % 3 == 0) key = buf;
					else if ((count - 1) % 3 == 2) {
						string key_prefix;
						for (int i=0; i < s.size(); i++) {
							if (i == 0) key_prefix = s[i];
							else key_prefix += "." + s[i];
						}
						buf.erase(0, 1);
						if (buf[buf.size() - 1] == '>')
							buf.erase(buf.size() - 2, buf.size() - 1);
						else
							buf.erase(buf.size() - 1, buf.size());
						m.insert(make_pair(key_prefix + "~" + key, buf));
					}
				}

				count++;
			}
		}
	}

	while (q--) {
		getline(cin, tmp);
		map<string, string>::iterator it;
		it = m.find(tmp);
		if (it != m.end()) {
			cout << m.at(tmp) << endl;
		} else {
			cout << "Not Found!" << endl;
		}
	}

	return 0;
}
