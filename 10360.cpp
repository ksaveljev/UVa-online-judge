#include <iostream>
#include <algorithm>
using namespace std;

struct result {
  int x;
  int y;
  int killed;
  result() : x(0), y(0), killed(0) {}
};

int field[1030][1030];

int main(void) {
  int cases;
  int d, n;
  int x, y, pop;

  cin >> cases;

  while (cases--) {
    cin >> d >> n;

    result best;

    for (int i = 0; i < 1030; i++)
      fill (field[i], field[i] + 1030, 0);

    while (n--) {
      cin >> x >> y >> pop;
      
      for (int i = x - d; i <= x + d; i++) {
        if (i < 0 || i > 1024)
          continue;

        for (int j = y - d; j <= y + d; j++) {
          if (j < 0 || j > 1024)
            continue;
          
          field[i][j] += pop;

          if (field[i][j] > best.killed) {
            best.killed = field[i][j];
            best.x = i;
            best.y = j;
          } else if (field[i][j] == best.killed) {
            if (i < best.x) {
              best.x = i;
              best.y = j;
            } else if (i == best.x) {
              if (j < best.y)
                best.y = j;
            }
          }
        }
      }
    }

    cout << best.x << " " << best.y << " " << best.killed << endl;
  }

  return 0;
}
