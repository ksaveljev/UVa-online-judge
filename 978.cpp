#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
  int n, b, sg, sb, tmp, gs, bs;
  priority_queue<int> green, blue;
  vector<int> gv, bv;

  cin >> n;

  while (n--) {
    cin >> b >> sg >> sb;

    while (sg--) {
      cin >> tmp;
      green.push(tmp);
    }

    while (sb--) {
      cin >> tmp;
      blue.push(tmp);
    }

    while (!green.empty() && !blue.empty()) {
      gs = green.size();
      bs = blue.size();

      tmp = min(gs, bs);
      tmp = min(tmp, b);

      for (int i = 0; i < tmp; i++) {
        gs = green.top(); green.pop();
        bs = blue.top(); blue.pop();

        if (gs > bs) {
          gv.push_back(gs - bs);
        } else if (gs < bs) {
          bv.push_back(bs - gs);
        }
      }

      for (int i = 0, sz = gv.size(); i < sz; i++)
        green.push(gv[i]);

      for (int i = 0, sz = bv.size(); i < sz; i++)
        blue.push(bv[i]);

      gv.clear();
      bv.clear();
    }

    if (green.empty() && blue.empty()) {
      cout << "green and blue died" << endl;
    } else if (blue.empty()) {
      cout << "green wins" << endl;
      while (!green.empty()) {
        cout << green.top() << endl;
        green.pop();
      }
    } else { // green.empty()
      cout << "blue wins" << endl;
      while (!blue.empty()) {
        cout << blue.top() << endl;
        blue.pop();
      }
    }

    if (n)
      cout << endl;
  }

  return 0;
}
