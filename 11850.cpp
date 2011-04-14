#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int n;
  int cur;
  int location;
  bool result;
  vector<int> stations;
  vector<int> dist;

  while (cin >> n) {
    if (n == 0)
      break;

    stations.clear();
    dist.clear();

    while (n--) {
      cin >> location;
      stations.push_back(location);
    }

    sort(stations.begin(), stations.end());

    cur = 0;
    dist.push_back(stations[0] - cur);

    for (int i = 1, sz = stations.size(); i < sz; i++) {
      dist.push_back(stations[i] - stations[i-1]);
    }

    dist.push_back((1422 - stations[stations.size()-1]) * 2);

    for (int i = stations.size() - 1; i > 0; i--) {
      dist.push_back(stations[i] - stations[i-1]);
    }

    sort(dist.begin(), dist.end());

    if (dist[dist.size() - 1] > 200)
      cout << "IMPOSSIBLE" << endl;
    else
      cout << "POSSIBLE" << endl;
  }

  return 0;
}
