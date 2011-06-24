#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
  char c;
  string input;
  map<char,bool> visited;
  map<char,int> pos;
  vector<char> chars;
  vector< pair<int,int> > pairs;
  vector<char> result;

  while (getline(cin, input)) {
    if (input == "#") {
      break;
    }

    chars.clear();
    visited.clear();
    pairs.clear();
    result.clear();

    for (int i = 0, sz = input.size(); i < sz; i++) {
      if (input[i] < 'A' || input[i] > 'Z') {
        input[i] = ' ';
      }
    }

    stringstream ss(input);
    while (ss >> c) {
      ss >> input;

      if (visited.find(c) == visited.end()) {
        visited[c] = true;
        chars.push_back(c);
      }

      for (int i = 0, sz = input.size(); i < sz; i++) {
        if (visited.find(input[i]) == visited.end()) {
          visited[input[i]] = true;
          chars.push_back(input[i]);
        }
        pairs.push_back(make_pair(c, input[i]));
      }
    }

    sort(chars.begin(), chars.end());

    int best = 10000000;
    do {
      int cur_best = 0;
      pos.clear();
      for (int i = 0, sz = chars.size(); i < sz; i++) {
        pos[chars[i]] = i;
      }

      for (int i = 0, sz = pairs.size(); i < sz; i++) {
        if (pairs[i].first == pairs[i].second) continue;

        if (abs(pos[pairs[i].first] - pos[pairs[i].second]) > cur_best) {
          cur_best = abs(pos[pairs[i].first] - pos[pairs[i].second]);
        }
      }

      if (cur_best < best) {
        result.clear();
        best = cur_best;
        for (int i = 0, sz = chars.size(); i < sz; i++) {
          result.push_back(chars[i]);
        }
      }
    } while (next_permutation(chars.begin(), chars.end()));

    for (int i = 0, sz = result.size(); i < sz; i++) {
      if (i > 0) cout << " ";
      cout << result[i];
    }
    cout << " -> " << best << endl;
  }
  return 0;
}
