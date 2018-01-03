#include <iostream>
#include <deque>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){
   deque<int> d;
   d.push_back(1);
   d.push_back(2);
   d.push_back(3);
   d.push_back(33);
   cout << d.back() << endl;
}
