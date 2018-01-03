#include <iostream>
#include <deque>
#include <algorithm>
#include <limits.h>
using namespace std;

void printKMax(int arr[], int n, int k) {
   //Write your code here.
  deque<int> d;
  
  for (int i = 0; i < n; i++) {
    if (i < k) {
      while(!d.empty() && arr[i] >= arr[d.back()])
        d.pop_back();

      d.push_back(i);
    } else {
      cout << arr[d.front()] << " ";

      while ( (!d.empty()) && d.front() <= i - k)
        d.pop_front();

      while(!d.empty() && arr[i] >= arr[d.back()])
        d.pop_back();

      d.push_back(i);
    }
  }

  cout << arr[d.front()] << endl;
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
