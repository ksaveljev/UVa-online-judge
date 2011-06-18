#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(void) {
  int t, n, k, c, start, end, roll;
  int *players = new int[1000001];
  map<int,int> ladder;

  cin >> t;

  while (t--) {
    cin >> n >> k >> c;

    ladder.clear();
    fill(players, players + n + 1, 1);

    while (k--) {
      cin >> start >> end;
      ladder[start] = end;
    }

    bool game_finished = false;
    int current_player = 0;
    for (int i = 0; i < c; i++) {
      cin >> roll;
      if (game_finished)
        continue;
      players[current_player] += roll;
      if (players[current_player] >= 100) {
        players[current_player] = 100;
        game_finished = true;
        continue;
      }
      if (ladder.find(players[current_player]) != ladder.end()) {
        players[current_player] = ladder[players[current_player]];
        if (players[current_player] >= 100) {
          players[current_player] = 100;
          game_finished = true;
          continue;
        }
      }
      current_player++;
      if (current_player >= n)
        current_player = 0;
    }

    for (int i = 0; i < n; i++) {
      cout << "Position of player " << i+1 << " is " << players[i] << "." << endl;
    }
  }

  delete [] players;

  return 0;
}
