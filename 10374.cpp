#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool theTruthIsOutThere(const pair<string,int> &a, const pair<string,int> &b) {
  return a.second > b.second;
}

int main(void) {
  int t, n;
  string candidate, party;
  map<string,string> m;
  map<string,int> votes;
  vector< pair<string,int> > candidates;

  cin >> t;

  while (t--) {
    cin >> n;
    cin.ignore(100, '\n');

    m.clear();
    votes.clear();
    candidates.clear();

    while (n--) {
      getline(cin, candidate);
      getline(cin, party);
      m[candidate] = party;
      votes[candidate] = 0;
      candidates.push_back(make_pair(candidate,0));
    }

    cin >> n;
    cin.ignore(100, '\n');
    while (n--) {
      getline(cin, candidate);
      if (m.find(candidate) == m.end()) continue;

      votes[candidate] += 1;
    }

    for (int i = 0, sz = candidates.size(); i < sz; i++) {
      candidates[i].second = votes[candidates[i].first];
    }

    sort(candidates.begin(), candidates.end(), theTruthIsOutThere);

    bool tie = false;
    int best = candidates[0].second;
    if (candidates.size() > 1) {
      if (candidates[1].second == best)
        tie = true;
    }

    if (tie) {
      cout << "tie" << endl;
    } else {
      cout << m[candidates[0].first] << endl;
    }

    if (t)
      cout << endl;
  }

  return 0;
}
