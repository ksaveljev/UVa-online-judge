#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

struct point {
  int x, y, z;
};

bool theTruthIsOutThere(const point &a, const point &b) {
  return a.x < b.x;
}

int main(void) {
  point tmp;
  int best;
  double dist;
  int distance;
  bool **counted;
  int result[10] = {0};
  vector<point> points;

  while (cin >> tmp.x >> tmp.y >> tmp.z) {
    if (tmp.x == 0 && tmp.y == 0 && tmp.z == 0)
      break;

    points.push_back(tmp);
  }

  sort(points.begin(), points.end(), theTruthIsOutThere);

  for (int i = 0, sz = points.size(); i < sz; i++) {
    best = 10;

    // left side
    for (int j = i - 1; j >= 0; j--) {
      if (abs(points[i].x - points[j].x) >= best)
        break;

      dist = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2) + pow(points[i].z - points[j].z, 2));
      distance = dist;

      if (distance < best)
        best = distance;
    }

    // right side
    for (int j = i + 1; j < sz; j++) {
      if (abs(points[i].x - points[j].x) >= best)
        break;

      dist = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2) + pow(points[i].z - points[j].z, 2));
      distance = dist;

      if (distance < best)
        best = distance;
    }

    if (best < 10)
      result[best]++;
  }

  for (int i = 0; i < 10; i++)
    printf("%4i", result[i]);
  cout << endl;

  return 0;
}
