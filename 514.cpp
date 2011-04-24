#include <iostream>
#include <stack>
using namespace std;

int main(void) {
  int n;
  int cur;
  bool ok;
  int train[1010];
  stack<int> s;

  while (cin >> n) {
    if (n == 0)
      break;

    while (cin >> train[0]) {
      if (train[0] == 0)
        break;

      while (!s.empty())
        s.pop();

      cur = 1;
      ok = true;

      for (int i = 1; i < n; i++)
        cin >> train[i];

      for (int i = 0; i < n; i++) {
        if (train[i] == cur) {
          cur++;
          continue;
        } else if (train[i] < cur) {
          if (s.size() > 0) {
            if (s.top() == train[i]) {
              s.pop();
              continue;
            }
          }
          ok = false;
          break;
        } else if (train[i] > cur) {
          while (train[i] != cur) {
            s.push(cur);
            cur++;
          }
          cur++;
          continue;
        }
      }
      
      if (ok) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }

    cout << endl;
  }

  return 0;
}
