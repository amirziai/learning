#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
void printKMax(int arr[], int n, int k) {
   //Write your code here.
  deque<int> d;

  for (int i=0; i < n; i++) {
    if (d.size() < k) {
      d.push_back(arr[i]);
      if (d.size() == k) cout << d[max_element(d.begin(), d.end()) - d.begin()] << " ";
    } else {
      d.pop_front();
      d.push_back(arr[i]);
      cout << d[max_element(d.begin(), d.end()) - d.begin()] << " ";
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
