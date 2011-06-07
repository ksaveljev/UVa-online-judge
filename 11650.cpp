#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
  int t;
  int h, m;
  char c;

  cin >> t;
  
  while (t--) {
    cin >> h >> c >> m;

    int new_h = (h == 12 ? 12 : 12 - h);
    if (m > 0) {
      new_h--;
      if (new_h == 0)
        new_h = 12;
    }

    int new_m = (m == 0 ? 0 : 60 - m);

    printf("%02d:%02d\n", new_h, new_m);
  }

  return 0;
}
