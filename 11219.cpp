#include <iostream>
using namespace std;

int date_diff(int d1, int m1, int y1, int d2, int m2, int y2) {
  int result = 0;

  if (y1 > y2)
    return -1;

  if (y1 == y2) {
    if (m1 > m2)
      return -1;

    if (m1 == m2) {
      if (d1 > d2)
        return - 1;
    }
  } else {
    result = y2 - y1;

    if (m2 == m1) {
      if (d2 < d1)
        result--;
    } else if (m2 < m1) {
      result--;
    }
  }

  return result;
}

int main(void) {
  int cases;
  int d1, d2, m1, m2, y1, y2;
  char delimiter;

  cin >> cases;

  for (int i = 0; i < cases; i++) {
    cout << "Case #" << i+1 << ": ";

    cin >> d1 >> delimiter >> m1 >> delimiter >> y1;
    cin >> d2 >> delimiter >> m2 >> delimiter >> y2;

    int diff = date_diff(d2, m2, y2, d1, m1, y1);

    if (diff < 0) {
      cout << "Invalid birth date" << endl;
    } else if (diff < 131) {
      cout << diff << endl;
    } else {
      cout << "Check birth date" << endl;
    }
  }

  return 0;
}
