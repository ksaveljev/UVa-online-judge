#include <iostream>
using namespace std;

int INF = 1000000000;

int main(void) {
  int result;
  int n, b, h, w;
  int p, a;

  while (cin >> n >> b >> h >> w) {
    result = INF;
    for (int i = 0; i < h; i++) {
      cin >> p;
      for (int j = 0; j < w; j++) {
        cin >> a;

        if (a >= n && p * n < result) {
          result = p * n;
        }
      }
    }

    if (result == INF || result > b) {
      cout << "stay home" << endl;
    } else {
      cout << result << endl;
    }
  }

  return 0;
}
