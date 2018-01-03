#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  long A = 1435434255433;
  

  try {
    vector<int> v(A, 2);
    cout << "a" << endl;
  } catch (...) {
    cout << "b" << endl;
  } finally {
    cout << "c" << endl;
  }
  

  
  return 0;
}
