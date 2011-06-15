#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void) {
  int k, m;
  int course;
  int n, req;
  map<int,bool> taken;

  while (cin >> k) {
    if (k == 0)
      break;

    cin >> m;

    taken.clear();

    for (int i = 0; i < k; i++) {
      cin >> course;
      taken[course] = true;
    }
    
    bool ok = true;
    for (int i = 0; i < m; i++) {
      cin >> n >> req;

      for (int j = 0; j < n; j++) {
        cin >> course;
        if (taken[course])
          req--;
      }

      if (req > 0)
        ok = false;
    }

    if (ok)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }

  return 0;
}
