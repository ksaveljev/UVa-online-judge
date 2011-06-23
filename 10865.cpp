#include <iostream>
#include <vector>
using namespace std;

int reduce(int n) {
  if (n == 0) {
    return 0;
  }
  if (n > 0) {
    return 1;
  }
  if (n < 0) {
    return -1;
  }
}

int main(void)
{
  int n, x, y;
  vector< pair<int,int> > points;

  while (cin >> n) {
    if (!n)
      break;

    points.clear();

    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      points.push_back(make_pair(x,y));
    }

    pair<int,int> mpoint = points[(n-1)/2];

    pair<int,int> result;
    result.first = result.second = 0;

    int tmp;
    for (int i = 0; i < n; i++) {
      tmp = reduce(mpoint.first - points[i].first) * reduce(mpoint.second - points[i].second);
      if (tmp > 0) {
        result.first++;
      } else if (tmp < 0) {
        result.second++;
      }
    }

    cout << result.first << " " << result.second << endl;
  }
  return 0;
}
