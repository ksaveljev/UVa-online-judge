#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int card2int(const string &card) {
  switch (card[0]) {
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      return int(card[0] - '0');
      break;
    default:
      return 10;
      break;
  }
}

int main(void) {
  int t;
  int y;
  string c;
  vector<string> cards;

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    y = 0;
    cards.clear();

    for (int i = 0; i < 52; i++) {
      cin >> c;
      cards.push_back(c);
    }

    reverse(cards.begin(), cards.end());

    for (int i = 0; i < 3; i++) {
      int v = card2int(cards[25]);
      y += v;
      cards.erase(cards.begin()+25, cards.begin()+26+(10-v));
    }

    reverse(cards.begin(), cards.end());

    cout << "Case " << casenum+1 << ": " << cards[y-1] << endl;
  }

  return 0;
}
