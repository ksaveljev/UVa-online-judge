#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int a, b;
  int alice_cards[10001], betty_cards[10001];
  bool alice[100001], betty[100001];

  while (cin >> a >> b) {
    if (a == 0 && b == 0)
      break;

    fill(alice, alice+100001, false);
    fill(betty, betty+100001, false);

    for (int i = 0; i < a; i++) {
      cin >> alice_cards[i];
      alice[alice_cards[i]] = true;
    }

    for (int i = 0; i < b; i++) {
      cin >> betty_cards[i];
      betty[betty_cards[i]] = true;
    }

    int alice_count = 0;
    int betty_count = 0;

    for (int i = 0; i < a; i++) {
      if (!betty[alice_cards[i]])
        alice_count++;
        betty[alice_cards[i]] = true;
    }

    for (int i = 0; i < b; i++) {
      if (!alice[betty_cards[i]])
        betty_count++;
        alice[betty_cards[i]] = true;
    }

    cout << min(alice_count, betty_count) << endl;
  }

  return 0;
}
