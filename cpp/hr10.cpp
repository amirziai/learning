#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> v;
    
    int tmp;
    for (int i=0; i < n; i++) {
    	cin >> tmp;
    	v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    for (int i=0; i < n; i++) cout << v[i] << " ";

    return 0;
}
