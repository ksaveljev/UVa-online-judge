#include <iostream>
#include <queue>
#include <bitset>
#include <map>
using namespace std;

int solve(int n, int m, const vector<int> switches[100])
{
  bitset<15> lamps;

  for (int i = 0; i < n; i++) {
    lamps.flip(i);
  }

  map<unsigned long,bool> visited;
  pair<bitset<15>, int> tmp;
  queue< pair<bitset<15>, int> > q;

  tmp.first = lamps;
  tmp.second = 0;
  q.push(tmp);

  visited[lamps.to_ulong()] = true;

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first.to_ulong() == 0) {
      return tmp.second;
    }

    for (int i = 0; i < m; i++) {
      bitset<15> current = tmp.first;
      for (int j = 0, sz = switches[i].size(); j < sz; j++) {
        current.flip(switches[i][j]);
      }

      if (!visited[current.to_ulong()]) {
        visited[current.to_ulong()] = true;
        q.push(make_pair(current, tmp.second+1));
      }
    }
  }

  return -1;
}

int main(void)
{
  int t, n, m, tmp;

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    cin >> n >> m;

    vector<int> switches[100];

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> tmp;
        if (tmp == 1) {
          switches[i].push_back(j);
        }
      }
    }

    int result = solve(n, m, switches);
    cout << "Case " << casenum+1 << ": ";
    if (result == -1) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << result << endl;
    }
  }
  
  return 0;
}
