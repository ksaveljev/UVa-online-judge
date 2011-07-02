#include <iostream>
#include <iomanip>
using namespace std;

struct point {
  double x;
  double y;
};

bool equal(const point &a, const point &b)
{
  return a.x == b.x && a.y == b.y;
}

int main(void)
{
  point points[4];
  point result;

  while (cin >> points[0].x >> points[0].y >> points[1].x >> points[1].y >> points[2].x >> points[2].y >> points[3].x >> points[3].y) {
    if (equal(points[0], points[2])) {
      result.x = points[3].x - (points[0].x - points[1].x);
      result.y = points[3].y - (points[0].y - points[1].y);
    } else if (equal(points[0], points[3])) {
      result.x = points[2].x - (points[0].x - points[1].x);
      result.y = points[2].y - (points[0].y - points[1].y);
    } else if (equal(points[1], points[2])) {
      result.x = points[0].x - (points[1].x - points[3].x);
      result.y = points[0].y - (points[1].y - points[3].y);
    } else { // equal(points[1], points[3]
      result.x = points[0].x - (points[1].x - points[2].x);
      result.y = points[0].y - (points[1].y - points[2].y);
    }

    cout << setprecision(3) << fixed << showpoint << result.x << " " << result.y << endl;
  }
  
  return 0;
}
