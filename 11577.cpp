#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
  int cases;
  int best;
  int count[26];
  string input;

  cin >> cases;
  cin.ignore(100, '\n');

  while (cases--) {
    getline(cin, input);

    best = 0;

    fill(count, count+26, 0);
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    for (int i = 0, sz = input.size(); i < sz; i++) {
      if (input[i] >= 'a' && input[i] <= 'z') {
        count[input[i] - 'a']++;
        if (count[input[i]-'a'] > best)
          best = count[input[i]-'a'];
      }
    }

    for (int i = 0; i < 26; i++) {
      if (count[i] == best) {
        cout << char('a' + i);
      }
    }

    cout << endl;
  }

  return 0;
}
