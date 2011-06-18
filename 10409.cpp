#include <iostream>
#include <string>
using namespace std;

struct die {
  int north, south, east, west, top, bottom;
  die() : north(2), south(5), east(4), west(3), top(1), bottom(6) {}
  void move_north() {
    die tmp = *this;
    north = tmp.top;
    south = tmp.bottom;
    east = tmp.east;
    west = tmp.west;
    top = tmp.south;
    bottom = tmp.north;
  }
  void move_south() {
    die tmp = *this;
    north = tmp.bottom;
    south = tmp.top;
    east = tmp.east;
    west = tmp.west;
    top = tmp.north;
    bottom = tmp.south;
  }
  void move_east() {
    die tmp = *this;
    north = tmp.north;
    south = tmp.south;
    east = tmp.top;
    west = tmp.bottom;
    top = tmp.west;
    bottom = tmp.east;
  }
  void move_west() {
    die tmp = *this;
    north = tmp.north;
    south = tmp.south;
    east = tmp.bottom;
    west = tmp.top;
    top = tmp.east;
    bottom = tmp.west;
  }
};

int main(void) {
  int n;
  string input;

  while (cin >> n) {
    if (!n)
      break;

    die tmp;

    cin.ignore(100, '\n');

    while (n--) {
      getline(cin, input);

      if (input == "north") {
        tmp.move_north();
      } else if (input == "south") {
        tmp.move_south();
      } else if (input == "west") {
        tmp.move_west();
      } else if (input == "east") {
        tmp.move_east();
      }
    }

    cout << tmp.top << endl;
  }

  return 0;
}
