#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
  int t;
  int r, c, m, n;
  char ch;
  map<char,int> count;
  int best;

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    count.clear();
    best = 0;

    cin >> r >> c >> m >> n;

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> ch;

        if (count.find(ch) == count.end()) {
          count[ch] = 1;
        } else {
          count[ch] += 1;
        }

        if (count[ch] > best)
          best = count[ch];
      }
    }

    int important = 0;
    for (ch = 'A'; ch <= 'Z'; ch++) {
      if (count.find(ch) == count.end()) continue;
      if (count[ch] == best)
        important++;
    }

    cout << "Case " << casenum+1 << ": " << m * best * important + n * (c*r - best * important) << endl;
  }

  return 0;
}
