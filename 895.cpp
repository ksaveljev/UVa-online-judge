#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  char c;
  int result;
  int dp[11][11];
  string input;
  vector<string> words;

  for (int i = 0; i < 11; i++) {
    dp[0][i] = 0;
    dp[i][0] = 0;
  }

  while (getline(cin, input)) {
    if (input == "#")
      break;

    sort(input.begin(), input.end(), less<char>());
    words.push_back(input);
  }

  while (cin.peek() != '#') {
    input = "";

    while (cin.peek() != '\n') {
      cin >> c;
      input += c;
    }

    cin.ignore(100, '\n');

    result = 0;

    sort(input.begin(), input.end(), less<char>());

    for (int w = 0, sz = words.size(); w < sz; w++) {
      if (words[w].size() > input.size())
        continue;

      for (int i = 1, sz = input.size(); i <= sz; i++) {
        for (int j = 1, sz2 = words[w].size(); j <= sz2; j++) {
          if (input[i-1] == words[w][j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
          else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      }

      if (dp[input.size()][words[w].size()] == words[w].size())
        result++;
    }

    cout << result << endl;
  }

  return 0;
}
