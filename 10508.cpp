#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int wordsnum, sz;
map<string, bool> m;
vector<string> words;
vector<string> result;

bool solve(string &start, string &end, int depth) {
  if (depth == sz) {
    for (int i = 0; i < sz + 1; i++) {
      cout << result[i] << endl;
    }

    return true;
  }

  char c;

  for (int i = 0; i < sz; i++) {
    if (start[i] == end[i])
      continue;

    c = start[i];
    start[i] = end[i];
    if (m.find(start) != m.end()) {
      result.push_back(start);
      bool r = solve(start, end, depth + 1);
      if (r)
        return true;
      result.pop_back();
    }
    start[i] = c;
  }

  return false;
}

int main(void) {
  string input;
  string start, end;

  while (cin >> wordsnum >> sz) {
    cin.ignore(100, '\n');
    result.clear();
    words.clear();
    m.clear();

    getline(cin, start);
    getline(cin, end);

    m[end] = true;
    while (!(cin.peek() >= '0' && cin.peek() <= '9' || cin.peek() == -1)) {
      getline(cin, input);
      words.push_back(input);
      m[input] = true;
    }

    result.push_back(start);
    solve(start, end, 0);
  }

  return 0;
}
