#include <iostream>
#include <map>
#include <cstdlib>
using namespace std;

int main(void) {
  int n, a, b;
  int players[6];
  bool miss[6];
  int throws[1001];
  map<int,int> ladder;
  map<int,int> extra;

  n = 0;
  while (cin >> throws[n]) {
    if (throws[n] == 0)
      break;

    n++;
  }

  while (cin >> n) {
    if (!n)
      break;

    ladder.clear();
    extra.clear();

    while (cin >> a >> b) {
      if (!a && !b)
        break;

      ladder[a] = b;
    }

    while (cin >> a) {
      if (a == 0)
        break;

      extra[abs(a)] = a;
    }

    int winner;
    int cur_player = 0;
    for (int i = 0; i < 6; i++) {
      miss[i] = false;
      players[i] = 0;
    }
    int cur_throw = 0;

    while (true) {
      if (miss[cur_player]) {
        miss[cur_player] = false;
        cur_player++;
        if (cur_player >= n)
          cur_player = 0;
        continue;
      }

      if (players[cur_player] + throws[cur_throw] > 100) {
        cur_throw++;
        cur_player++;
        continue;
      } else if (players[cur_player] + throws[cur_throw] == 100) {
        winner = cur_player + 1;
        break;
      }

      players[cur_player] += throws[cur_throw];
      cur_throw++;

      if (ladder.find(players[cur_player]) != ladder.end()) {
        players[cur_player] = ladder[players[cur_player]];
        if (players[cur_player] == 100) {
          winner = cur_player + 1;
          break;
        }
      }

      if (extra.find(players[cur_player]) != extra.end()) {
        if (extra[players[cur_player]] < 0) {
          miss[cur_player] = true;
        } else {
          cur_player--;
        }
      }

      cur_player++;
      if (cur_player >= n)
        cur_player = 0;
    }

    cout << winner << endl;
  }

  return 0;
}
