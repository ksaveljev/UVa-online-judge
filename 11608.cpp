#include <iostream>
using namespace std;

int main(void) {
  int s;
  int n[12], p[12];
  int counter = 0;

  while (cin >> s) {
    if (s < 0)
      break;

    counter++;

    for (int i = 0; i < 12; i++)
      cin >> n[i];

    for (int i = 0; i < 12; i++)
      cin >> p[i];

    cout << "Case " << counter << ":" << endl;
    for (int i = 0; i < 12; i++) {
      if (p[i] <= s) {
        s -= p[i];
        s += n[i];
        cout << "No problem! :D" << endl;
      } else {
        s += n[i];
        cout << "No problem. :(" << endl;
      }
    }
  }

  return 0;
}
