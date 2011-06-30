#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
  int n, sz;
  string input;
  bool visited[52];
  pair<char,char> tmp;
  vector< pair<char,char> > v(52);

  while (cin >> n) {
    if (!n) {
      break;
    }

    int pos = -1;
    fill(visited, visited+52, false);

    for (int i = 0; i < n; i++) {
      cin >> tmp.first >> tmp.second;
      cin >> input;

      sz = input.size();

      while (sz) {
        pos++;
        pos %= n;

        if (visited[pos]) {
          continue;
        }

        sz--;
      }

      v[pos] = tmp;
      visited[pos] = true;
    }

    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << v[i].first << v[i].second;
    }
    cout << endl;
  }
  
  return 0;
}
