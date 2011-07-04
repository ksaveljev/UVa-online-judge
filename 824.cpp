#include <iostream>
using namespace std;

bool land_at(int d, char pos[][3])
{
  switch (d) {
    case 0:
      return pos[0][1] == '1';
    case 1:
      return pos[0][0] == '1';
    case 2:
      return pos[1][0] == '1';
    case 3:
      return pos[2][0] == '1';
    case 4:
      return pos[2][1] == '1';
    case 5:
      return pos[2][2] == '1';
    case 6:
      return pos[1][2] == '1';
    case 7:
      return pos[0][2] == '1';
  }
}

int main(void)
{
  int x, y, a, b, d, new_d;
  char c, pos[3][3];

  while (cin >> y) {
    if (y == -1) {
      break;
    }

    cin >> x >> d;

    pos[1][1] = '1';

    for (int i = 0; i < 8; i++) {
      cin >> b >> a >> c;

      pos[1 - (a-x)][1 + b-y] = c;
    }

    for (int i = 0; i < 8; i++) {
      new_d = (d + i + 5) % 8;
      if (land_at(new_d, pos)) {
        cout << new_d << endl;
        break;
      }
    }
  }
  
  return 0;
}
