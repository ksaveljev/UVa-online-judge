#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool theTruthIsOutThere(const pair<int,int> &a, const pair<int,int> &b) {
  return a.first > b.first;
}

int main(void) {
  int t, n, a;

  cin >> t;

  while (t--) {
    cin >> n;

    vector< pair<int,int> > v;
    while (n--) {
      cin >> a;

      if (a < 0) {
        v.push_back(make_pair(-a, 1));
      } else {
        v.push_back(make_pair(a, 2));
      }
    }

    sort(v.begin(), v.end(), theTruthIsOutThere);

    int prev = v[0].second;
    int result = 1;

    for (int i = 0, sz = v.size(); i < sz; i++) {
      if (v[i].second != prev) {
        result++;
        prev = v[i].second;
      }
    }

    cout << result << endl;
  }

  return 0;
}
