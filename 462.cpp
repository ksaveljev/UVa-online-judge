#include <iostream>
#include <algorithm>
using namespace std;

enum suit { SPADES, HEARTS, DIAMONDS, CLUBS };

struct hand {
  int points;
  int alternative_points;
  bool cards[4][15];
  hand() : points(0), alternative_points(0) {
    for (int i = 0; i < 4; i++)
      fill (cards[i], cards[i] + 15, false);
  }
};

suit char2suit(char c) {
  switch (c) {
    case 'S':
      return SPADES;
    case 'H':
      return HEARTS;
    case 'D':
      return DIAMONDS;
    case 'C':
      return CLUBS;
  }
}

int char2value(char c) {
  switch (c) {
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return int(c - '0');
    case 'T':
      return 10;
    case 'J':
      return 11;
    case 'Q':
      return 12;
    case 'K': 
      return 13;
    case 'A':
      return 14;
  }
}

bool find_card(const hand &h, int s, char _v, int n) {
  int v = char2value(_v);

  int count = 0;

  for (int i = 2; i <= 14; i++) {
    if (h.cards[s][i])
      count++;
  }

  return count <= n && h.cards[s][v];
}

bool find_card2(const hand &h, int s, char _v, int n) {
  int v = char2value(_v);

  int count = 0;

  for (int i = 2; i <= 14; i++) {
    if (h.cards[s][i])
      count++;
  }

  return count >= n && h.cards[s][v];
}

bool exact_suit(const hand &h, int s, int n) {
  int count = 0;

  for (int i = 2; i <= 14; i++)
    if (h.cards[s][i])
      count++;

  return count == n;
}

bool is_stopped(const hand &h, int s) {
  return h.cards[s][char2value('A')] || find_card2(h, s, 'K', 2) || find_card2(h, s, 'Q', 3);
}

char best_suit(const hand &h) {
  pair<int,int> best;
  best.first = best.second = 0;

  for (int i = 0; i < 4; i++) {
    int count = 0;
    for (int j = 2; j <= 14; j++)
      if (h.cards[i][j])
        count++;

    if (count > best.first) {
      best.first = count;
      best.second = i;
    }
  }

  switch (best.second) {
    case 0:
      return 'S';
    case 1:
      return 'H';
    case 2:
      return 'D';
    case 3:
      return 'C';
  }
}

int main(void) {
  char v, s;

  while (cin >> v) {
    cin >> s;

    hand input;

    input.cards[char2suit(s)][char2value(v)] = true;
    if (char2value(v) > 10)
      input.points += char2value(v) - 10;

    for (int i = 0; i < 12; i++) {
      cin >> v >> s;
      input.cards[char2suit(s)][char2value(v)] = true;
      if (char2value(v) > 10)
        input.points += char2value(v) - 10;
    }

    input.alternative_points = input.points;

    for (int i = 0; i < 4; i++) {
      if (find_card(input, i, 'K', 1)) {
        input.points -= 1;
        input.alternative_points -= 1;
      }

      if (find_card(input, i, 'Q', 2)) {
        input.points -= 1;
        input.alternative_points -= 1;
      }

      if (find_card(input, i, 'J', 3)) {
        input.points -= 1;
        input.alternative_points -= 1;
      }

      if (exact_suit(input, i, 2)) {
        input.points += 1;
      }

      if (exact_suit(input, i, 1)) {
        input.points += 2;
      }

      if (exact_suit(input, i, 0)) {
        input.points += 2;
      }
    }

    if (input.points < 14) {
      cout << "PASS" << endl;
      continue;
    }

    if (input.alternative_points >= 16) {
      bool ok = true;
      for (int i = 0; i < 4; i++) {
        if (!is_stopped(input, i)) {
          ok = false;
          break;
        }
      }

      if (ok) {
        cout << "BID NO-TRUMP" << endl;
        continue;
      }
    }

    cout << "BID " << best_suit(input) << endl;
  }

  return 0;
}
