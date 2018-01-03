#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int number_arrays, number_queries;
    cin >> number_arrays;
    cin >> number_queries;

    vector<int> arrays[number_arrays];

    for (int i = 0; i < number_arrays; i++) {
      int arraySize;
      cin >> arraySize;
      int val;
      for (int vector_index = 0; vector_index < arraySize; vector_index++) {
        cin >> val;
        arrays[i].push_back(val);
      }
    }

    for (int i = 0; i < number_queries; i++) {
      int array, position;
      cin >> array;
      cin >> position;
      cout << arrays[array][position] << endl;
    }

    return 0;
}
