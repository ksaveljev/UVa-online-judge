#include <iostream>
#include <string>
#include <deque>
#include <cstdio>
using namespace std;

int card2int(const string &card) {
  switch (card[1]) {
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return int(card[1] - '0');
      break;
    case 'T':
      return 10;
      break;
    case 'J':
      return 11;
      break;
    case 'Q':
      return 12;
      break;
    case 'K':
      return 13;
      break;
    case 'A':
      return 14;
      break;
  }
}

int main(void) {
  int tmp;
  int cover;
  string card;

  while (cin >> card) {
    if (card == "#")
      break;

    deque<int> player, dealer, middle;
    bool p = true; // player starts the game, not the dealer
    cover = 0;

    player.push_front(card2int(card));
    for (int i = 0; i < 51; i++) {
      cin >> card;
      if (i % 2 == 0) {
        dealer.push_front(card2int(card));
      } else {
        player.push_front(card2int(card));
      }
    }

    while (true) {
      if (player.empty() && p || dealer.empty() && !p)
        break;

      //cout << "player = " << player.size() << " dealer = " << dealer.size() << " cover = " << cover << endl;
      //cout << "middle = " << middle.size() << " front = " << middle.front() << endl;
      if (p) {
        tmp = player.front();
        player.pop_front();
        middle.push_front(tmp);

        if (tmp > 10) {
          p = false;
          cover = tmp - 10;
          continue;
        }

        if (cover > 0) {
          if (cover == 1) {
            cover = 0;
            while (!middle.empty()) {
              dealer.push_back(middle.back());
              middle.pop_back();
            }
            p = false;
          } else {
            cover--;
          }
        } else {
          p = false;
        }
      } else {
        tmp = dealer.front();
        dealer.pop_front();
        middle.push_front(tmp);

        if (tmp > 10) {
          p = true;
          cover = tmp - 10;
          continue;
        }

        if (cover > 0) {
          if (cover == 1) {
            cover = 0;
            while (!middle.empty()) {
              player.push_back(middle.back());
              middle.pop_back();
            }
            p = true;
          } else {
            cover--;
          }
        } else {
          p = true;
        }
      }
    }

    if (player.size() == 0) {
      printf("%d%3d\n", 1, dealer.size());
    } else {
      printf("%d%3d\n", 2, player.size());
    }
  }

  return 0;
}
