#include <iostream>
using namespace std;

pair<int,int> int2pos(int n) {
  int row = n / 8;
  int col = n % 8;

  return make_pair(row, col);
}

int k, q, new_q;
pair<int,int> king, queen, new_queen;

bool can_queen_move() {
  if (k == new_q)
    return false;

  if (q == new_q)
    return false;

  if (new_queen.first - queen.first != 0 && new_queen.second - queen.second != 0)
    return false;

  if (queen.first == new_queen.first) {
    int start = min(queen.second, new_queen.second);
    int end = max(queen.second, new_queen.second);
    for (int i = start; i <= end; i++) {
      if (king.first == queen.first && king.second == i)
        return false;
    }
  } else {
    int start = min(queen.first, new_queen.first);
    int end = max(queen.first, new_queen.first);
    for (int i = start; i <= end; i++) {
      if (king.second == queen.second && king.first == i)
        return false;
    }
  }

  return true;
}

bool queen_move_allowed() {
  if (king.first - 1 == new_queen.first && king.second == new_queen.second)
    return false;

  if (king.first + 1 == new_queen.first && king.second == new_queen.second)
    return false;

  if (king.first == new_queen.first && king.second - 1 == new_queen.second)
    return false;

  if (king.first == new_queen.first && king.second + 1 == new_queen.second)
    return false;

  return true;
}

bool king_blocked() {
  if (king.first > 0 && king.first - 1 != new_queen.first && king.second != new_queen.second)
    return false;

  if (king.first < 7 && king.first + 1 != new_queen.first && king.second != new_queen.second)
    return false;

  if (king.second > 0 && king.second - 1 != new_queen.second && king.first != new_queen.first)
    return false;

  if (king.second < 7 && king.second + 1 != new_queen.second && king.first != new_queen.first)
    return false;

  return true;
}

int main(void) {

  while (cin >> k >> q >> new_q) {
    if (k == q) {
      cout << "Illegal state" << endl;
      continue;
    }

    king = int2pos(k);
    queen = int2pos(q);
    new_queen = int2pos(new_q);

    if (!can_queen_move()) {
      cout << "Illegal move" << endl;
      continue;
    }

    if(!queen_move_allowed()) {
      cout << "Move not allowed" << endl;
      continue;
    }

    if (king_blocked()) {
      cout << "Stop" << endl;
    } else {
      cout << "Continue" << endl;
    }
  }

  return 0;
}
