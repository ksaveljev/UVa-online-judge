#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

bool theTruthIsOutThere(const pair<string,int> &a, const pair<string,int> &b) {
  return a.second > b.second;
}

int main(void) {
  int n;
  int courses[5];

  while (cin >> n) {
    if (!n)
      break;

    int result = 0;
    map<string,int> m;
    vector< pair<string,int> > v;

    while (n--) {
      for (int i = 0; i < 5; i++)
        cin >> courses[i];

      sort(courses, courses+5);

      stringstream ss;
      for (int i = 0; i < 5; i++)
        ss << courses[i];

      string s = ss.str();

      if (m.find(s) == m.end()) {
        m[s] = 1;
        v.push_back(make_pair(s,0));
      } else {
        m[s] += 1;
      }
    }

    for (int i = 0, sz = v.size(); i < sz; i++) {
      v[i].second = m[v[i].first];
    }

    sort(v.begin(), v.end(), theTruthIsOutThere);

    if (v.size() == 1) {
      result = v[0].second;
    } else if (v[0].second == v[1].second) {
      for (int i = 0, sz = v.size(); i < sz; i++) {
        if (v[i].second < v[0].second)
          break;

        result += v[i].second;
      }
    } else {
      result = v[0].second;
    }

    cout << result << endl;
  }

  return 0;
}
