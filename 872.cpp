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
      if (i > 0)
        cout << " ";
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
  char c, del, b;
  int cases;

  cin >> cases;
  cin.ignore(100, '\n');
  cin.ignore(100, '\n');

  while (cases--) {
    n = 0;

    fill (taken, taken + 20, false);
    m.clear();
    found = false;

    while (cin.peek() != '\n') {
      cin >> c;
      var[n] = c;
      n++;
    }

    cin.ignore(100, '\n');

    while (cin.peek() != '\n' && cin.peek() != -1) {
      cin >> c >> del >> b;
      m.insert(make_pair(c, b));
    }

    if (cin.peek() == '\n') {
      cin.ignore(100, '\n');
      cin.ignore(100, '\n');
    }

    solve(0);

    if (!found)
      cout << "NO" << endl;

    if (cases)
      cout << endl;
  }

  return 0;
}
