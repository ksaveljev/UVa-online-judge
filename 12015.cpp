#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool starts_with_www(const string &s) {
  if (s.size() > 3 && string(s.begin(), s.begin() + 4) == "www.")
    return true;

  return false;
}

bool theTruthIsOutThere(const pair<string,int> &a, const pair<string,int> &b) {
  if (a.second == b.second) {
    if (starts_with_www(a.first) && starts_with_www(b.first)) {
      return a.first < b.first;
    } else if (starts_with_www(a.first) && !starts_with_www(b.first)) {
      return true;
    } else if (!starts_with_www(a.first) && starts_with_www(b.first)) {
      return false;
    } else {
      return a.first < b.first;
    }
  }

  return a.second > b.second;
}

int main(void) {
  int cases;
  string url;
  int relevance;
  vector< pair<string,int> > v;

  cin >> cases;

  for (int casenum = 0; casenum < cases; casenum++) {
    v.clear();

    for (int i = 0; i < 10; i++) {
      cin >> url >> relevance;
      v.push_back(make_pair(url, relevance));
    }

    sort(v.begin(), v.end(), theTruthIsOutThere);

    int best = v[0].second;

    cout << "Case #" << casenum+1 << ":" << endl;

    for (int i = 0; i < 10; i++) {
      if (v[i].second < best)
        break;
      cout << v[i].first << endl;
    }
  }

  return 0;
}
