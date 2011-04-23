#include <iostream>
#include <string>
//#include <cmath>
#include <cstdlib>
using namespace std;

bool cross_possible(const string &a, const string &b) {
  for (int i = 0, sz = a.size(); i < sz; i++) {
    for (int j = 0, sz2 = b.size(); j < sz2; j++) {
      if (a[i] == b[j])
        return true;
    }
  }

  return false;
}

int main(void) {
  int h1, h2;
  int v1, v2;
  string words[4];
  bool first = true;

  while (cin >> words[0]) {
    if (words[0] == "#")
      break;

    if (!first)
      cout << endl;

    cin >> words[1] >> words[2] >> words[3];

    if (cross_possible(words[0], words[1]) && cross_possible(words[2], words[3])) {
      for (int i = 0, sz = words[0].size(); i < sz; i++) {
        for (int j = 0, sz2 = words[1].size(); j < sz2; j++) {
          if (words[0][i] == words[1][j]) {
            h1 = i;
            v1 = j;
            i = 10000000;
            break;
          }
        }
      }

      for (int i = 0, sz = words[2].size(); i < sz; i++) {
        for (int j = 0, sz2 = words[3].size(); j < sz2; j++) {
          if (words[2][i] == words[3][j]) {
            h2 = i;
            v2 = j;
            i = 10000000;
            break;
          }
        }
      }

      // top part
      for (int i = 0, sz = max(v1, v2); i < sz; i++) {
        for (int j = 0; j < h1; j++)
          cout << " ";

        // first virtical word
        if (v1 < sz - i) {
          cout << " ";
        } else {
          if (v1 >= v2) {
            cout << words[1][i];
          } else {
            cout << words[1][i - abs(v1-v2)];
          }
        }

        // second virtical word
        if (v2 < sz - i) {
          // do nothing
        } else {
          for (int j = 0; j < words[0].size() - h1 - 1 + 3 + h2; j++)
            cout << " ";

          if (v2 >= v1)
            cout << words[3][i];
          else
            cout << words[3][i - abs(v1-v2)];
        }

        cout << endl;
      }

      // horizontal part
      cout << words[0] << "   " << words[2] << endl;

      // bottom part
      for (int i = 0, sz = max(words[1].size() - v1 - 1, words[3].size() - v2 - 1); i < sz; i++) {
        for (int j = 0; j < h1; j++)
          cout << " ";

        // first vertical word
        if (words[1].size() - v1 - 1 <= i)
          cout << " ";
        else
          cout << words[1][v1 + 1 + i];

        // second vertical word
        if (words[3].size() - v2 - 1 <= i) {
          // do nothing
        } else {
          for (int j = 0; j < words[0].size() - h1 - 1 + 3 + h2; j++)
            cout << " ";

          cout << words[3][v2 + 1 + i];
        }

        cout << endl;
      }
    } else {
      cout << "Unable to make two crosses" << endl;
    }

    first = false;
  }

  return 0;
}
