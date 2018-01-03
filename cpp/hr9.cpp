#include <iostream>
#include <vector>

using namespace std;

struct myclass {
  bool operator() (string i, string j) {
    if (i.length() < j.length()) return true;
    else if (i.length() > j.length()) return false;
    else return (i < j);
    }
} myobject;

int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    std::sort(unsorted.begin(), unsorted.end(), myobject);
    for (int i=0; i < unsorted.size(); i++) cout << unsorted[i] << endl;
    
    // your code goes here
    return 0;
}
