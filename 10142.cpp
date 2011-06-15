#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
  int n, tmp;
  int cases;
  string input;
  map<int,string> candidates;
  int votes[1001][21];
  map<int,bool> eliminated;

  cin >> cases;

  while (cases--) {
    cin >> n;
    cin.ignore(100, '\n');

    candidates.clear();
    eliminated.clear();

    for (int i = 1; i <= n; i++) {
      getline(cin, input);
      candidates[i] = input;
    }

    int cur = 0;
    while (cin.peek() != '\n' && cin.peek() != -1) {
      for (int i = 0; i < n; i++)
        cin >> votes[cur][i];

      cin.ignore(100, '\n');
      cur++;
    }

    int best;
    int count[21];

    while (true) {
      best = 0;
      fill(count, count+21, 0);

      for (int i = 0; i < cur; i++) {
        for (int j = 0; j < n; j++) {
          if (eliminated[votes[i][j]]) continue;

          count[votes[i][j]]++;

          if (count[votes[i][j]] > best)
            best = count[votes[i][j]];

          break;
        }
      }

      if (best * 2 > cur)
        break;

      int lowest = best;
      for (int i = 1; i <= n; i++) {
        if (eliminated[i]) continue;

        if (count[i] < lowest)
          lowest = count[i];
      }

      if (lowest == best)
        break;

      for (int i = 1; i <= n; i++) {
        if (eliminated[i]) continue;
        if (count[i] == lowest)
          eliminated[i] = true;
      }
    }

    for (int i = 1; i <= n; i++) {
      if (eliminated[i]) continue;

      if (count[i] == best)
        cout << candidates[i] << endl;
    }

    if (cases)
      cout << endl;
  }

  return 0;
}
