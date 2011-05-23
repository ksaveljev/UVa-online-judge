#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n;
char var[20];
multimap<char,char> m;
char current[20];
bool taken[20];
bool found;

bool fit(char c, int depth) {
  multimap<char,char>::iterator it;
  pair<multimap<char,char>::iterator,multimap<char,char>::iterator> ret;

  ret = m.equal_range(c);
  for (it = ret.first; it != ret.second; it++) {
    for (int i = 0; i < depth; i++) {
      if (current[i] == it->second)
        return false;
    }
  }

  return true;
}

void solve(int depth) {
  if (depth == n) {
    for (int i = 0; i < n; i++) {
      cout << current[i];
    }
    cout << endl;
    found = true;
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!fit(var[i], depth) || taken[i])
      continue;
    taken[i] = true;
    current[depth] = var[i];
    solve(depth + 1);
    taken[i] = false;
  }
}

int main(void) {
  char a, b;
  bool first = true;

  while (cin.peek() != -1) {
    n = 0;
    fill (taken, taken + 20, false);
    m.clear();

    if (!first)
      cout << endl;

    while (cin.peek() != '\n') {
      cin >> a;
      var[n] = a;
      n++;
    }

    sort(var, var + n);

    cin.ignore(100, '\n');

    while (cin.peek() != '\n' && cin.peek() != -1) {
      cin >> a >> b;
      m.insert(make_pair(a, b));
    }

    cin.ignore(100, '\n');

    solve(0);

    first = false;
  }

  return 0;
}
