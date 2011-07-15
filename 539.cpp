#include <iostream>
#include <vector>
using namespace std;

bool visited[25];
vector< pair<int,int> > edges;

int solve(int current)
{
  int result = 0;

  for (int i = 0, sz = edges.size(); i < sz; i++) {
    if (edges[i].first == current) {
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      result = max(result, 1 + solve(edges[i].second));
      visited[i] = false;
    } else if (edges[i].second == current) {
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      result = max(result, 1 + solve(edges[i].first));
      visited[i] = false;
    }
  }

  return result;
}

int main(void)
{
  int n, m, a, b;

  while (cin >> n >> m) {
    if (!n && !m) {
      break;
    }

    edges.clear();

    for (int i = 0; i < 25; i++) {
      visited[i] = false;
    }

    while (m--) {
      cin >> a >> b;
      edges.push_back(make_pair(a,b));
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
      result = max(result, solve(i));
    }

    cout << result << endl;
  }

  return 0;
}
