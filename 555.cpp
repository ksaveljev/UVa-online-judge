#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct card {
  char suit;
  char value;
};

void print_hand(const vector<card> &v) {
  for (int i = 0, sz = v.size(); i < sz; i++) {
    if (i > 0)
      cout << " ";
    cout << v[i].suit << v[i].value;
  }
  cout << endl;
}

int value2int(char c) {
  int v;

  switch (c) {
    case '2':
      v = 2;
      break;
    case '3':
      v = 3;
      break;
    case '4':
      v = 4;
      break;
    case '5':
      v = 5;
      break;
    case '6':
      v = 6;
      break;
    case '7':
      v = 7;
      break;
    case '8':
      v = 8;
      break;
    case '9':
      v = 9;
      break;
    case 'T':
      v = 10;
      break;
    case 'J':
      v = 11;
      break;
    case 'Q':
      v = 12;
      break;
    case 'K':
      v = 13;
      break;
    case 'A':
      v = 14;
      break;
  }

  return v;
}

int suit2int(char c) {
  int v;

  switch (c) {
    case 'C':
      v = 1;
      break;
    case 'D':
      v = 2;
      break;
    case 'S':
      v = 3;
      break;
    case 'H':
      v = 4;
      break;
  }

  return v;
}

bool theTruthIsOutThere(const card &a, const card &b) {
  if (a.suit == b.suit) {
    return value2int(a.value) < value2int(b.value);
  }

  return suit2int(a.suit) < suit2int(b.suit);
}

int main(void) {
  char c;
  int dealer;
  string deck, tmp;
  card crd;
  vector<card> players[4];

  while (cin >> c) {
    if (c == '#')
      break;

    for (int i = 0; i < 4; i++)
      players[i].clear();

    if (c == 'N')
      dealer = 0;
    else if (c == 'E')
      dealer = 1;
    else if (c == 'S')
      dealer = 2;
    else if (c == 'W')
      dealer = 3;

    cin.ignore(100, '\n');

    getline(cin, deck);
    getline(cin, tmp);
    deck += tmp;

    for (int i = 0; i < 104; i += 2) {
      crd.suit = deck[i];
      crd.value = deck[i+1];
      players[(dealer + 1) % 4].push_back(crd);
      dealer++;
    }

    for (int i = 0; i < 4; i++) {
      sort(players[i].begin(), players[i].end(), theTruthIsOutThere);
    }

    cout << "S: ";
    print_hand(players[2]);
    cout << "W: ";
    print_hand(players[3]);
    cout << "N: ";
    print_hand(players[0]);
    cout << "E: ";
    print_hand(players[1]);
  }

  return 0;
}
