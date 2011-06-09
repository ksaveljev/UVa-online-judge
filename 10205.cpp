#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

struct card {
  int value;
  int suit; // 0 - clubs, 1 - diamonds, 2 - hearts, 3 - spades
};

bool theTruthIsOutThere(const pair<card,int> &a, const pair<card,int> &b) {
  return a.second < b.second;
}

string card2str(const card &c) {
  stringstream ss;
  switch (c.value) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      ss << c.value;
      break;
    case 11:
      ss << "Jack";
      break;
    case 12:
      ss << "Queen";
      break;
    case 13:
      ss << "King";
      break;
    case 14:
      ss << "Ace";
      break;
  }

  switch (c.suit) {
    case 0:
      ss << " of Clubs";
      break;
    case 1:
      ss << " of Diamonds";
      break;
    case 2:
      ss << " of Hearts";
      break;
    case 3:
      ss << " of Spades";
      break;
  }

  return ss.str();
}

int main(void) {
  int t, n, v;
  card tmp;
  vector< pair<card,int> > cards;
  vector< vector<int> > shuffles;

  cin >> t;

  while (t--) {
    cin >> n;

    cards.clear();
    shuffles.clear();

    for (int i = 0; i < 4; i++) {
      for (int j = 2; j < 15; j++) {
        tmp.value = j;
        tmp.suit = i;
        cards.push_back(make_pair(tmp, 0));
      }
    }

    while (n--) {
      vector<int> shuffle;
      for (int i = 0; i < 52; i++) {
        cin >> v;
        shuffle.push_back(v);
      }
      shuffles.push_back(shuffle);
    }

    cin.ignore(100, '\n');
    while (cin.peek() != '\n' && cin.peek() != -1) {
      cin >> v;
      cin.ignore(100, '\n');

      for (int i = 0; i < 52; i++) {
        cards[shuffles[v-1][i]-1].second = i;
      }

      sort(cards.begin(), cards.end(), theTruthIsOutThere);
    }

    for (int i = 0; i < 52; i++) {
      cout << card2str(cards[i].first) << endl;
    }

    if (t)
      cout << endl;
  }

  return 0;
}
