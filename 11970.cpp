#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int LIMIT = 1000000000;

int main(void) {
  int t, n, x, tmp;
  vector<int> squares;
  map<int,int> sq;

  for (int i = 1, sz = sqrt(LIMIT); i <= sz; i++) {
    squares.push_back(i*i);
    sq[i*i] = i;
  }

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    cin >> n;

    cout << "Case " << casenum+1 << ":";
    for (int i = squares.size() - 1; i >= 0; i--) {
      if (squares[i] >= n) continue;

      x = n - squares[i];
      tmp = x / sq[squares[i]];
      if (x == tmp * sq[squares[i]])
        cout << " " << x;
    }
    cout << endl;
  }

  return 0;
}
