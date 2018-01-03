#include <iostream>
#include <deque>
#include <algorithm>
#include <limits.h>
using namespace std;

void printKMax(int arr[], int n, int k) {
   //Write your code here.
  deque<int> d;
  int d_max = INT_MIN;
  bool first = false;

  for (int i=0; i < n; i++) {
    if (k == 1) {
      if (i > 0) cout << " ";
      cout << arr[i];
    } else {
      if (d.size() == 0) d.push_back(arr[i]);
      else if (d.size() > 0 && d.size() < k - 1) {
        if (arr[i] > d.back()) d.push_back(arr[i]);
        else d.push_front(arr[i]);
      } else {
        d_max = max(d.back(), arr[i]);
        if (first) cout << " ";
        cout << d_max;
        first = true;
        d.pop_front();
        if (arr[i] > d.back()) d.push_back(arr[i]);
        else d.push_front(arr[i]);
      }
    }
  }

  cout << endl;
}

int main(){
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
