#include <iostream>
#include <set>
using namespace std;

int main(void)
{
  int t, m, n, u;
  multiset<int> s;
  multiset<int>::iterator it;
  int nums[30000];

  cin >> t;

  while (t--) {
    cin >> m >> n;

    s.clear();

    for (int i = 0; i < m; i++) {
      cin >> nums[i];
    }

    s.insert(nums[0]);
    bool first = true;
    int sz = 1; // current set size

    for (int i = 0; i < n; i++) {
      cin >> u;

      while (u > sz) {
        s.insert(nums[sz]);
        if (*it > nums[sz]) {
          it--;
        }
        sz++;
      }

      if (first) {
        it = s.begin();
        first = false;
      } else {
        it++;
      }

      cout << *it << endl;
    }

    if (t) {
      cout << endl;
    }
  }
  
  return 0;
}
