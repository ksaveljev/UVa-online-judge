#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void) {
  int n;
  int tmp;
  bool found;
  vector<int> cubes;

  cubes.push_back(1);
  for (int i = 2; ; i++) {
    tmp = pow(i, 3);
    if (tmp - cubes[cubes.size() - 1] > 10000)
      break;
    cubes.push_back(tmp);
  }

  while (cin >> n) {
    if (n == 0)
      break;

    found = false;
    for (int i = 0, sz = cubes.size(); i < sz - 1; i++) {
      for (int j = i + 1; j < sz; j++) {
        if (cubes[j] - cubes[i] == n) {
          cout << cubes[j] / ((j+1) * (j+1)) << " " << cubes[i] / ((i+1) * (i+1)) << endl;
          found = true;
          j = sz;
          i = sz;
        }
      }
    }

    if (!found)
      cout << "No solution" << endl;
  }

  return 0;
}
