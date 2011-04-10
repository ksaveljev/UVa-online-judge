#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int len(unsigned long long n) {
  return log10(n) + 1;
}

int main(void) {
  int t, n;
  int L;
  unsigned long long k;
  int largest = 0;
  map<int,bool> visited;

  cin >> t;

  while (t--) {
    cin >> n >> k;
    
    visited.clear();
    
    largest = k;
    visited[k] = true;

    while (true) {
      k = (k * k);
      L = len(k);
      while (L > n) {
        k /= 10;
        L--;
      }
      if (visited[k] == true)
        break;

      if (k > largest)
        largest = k;

      visited[k] = true;
    }

    cout << largest << endl;
  }

  return 0;
}
