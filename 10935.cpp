#include <iostream>
#include <deque>
using namespace std;

int main(void) {
  int n;
  int remain;

  while (cin >> n) {
    if (!n)
      break;

    deque<int> q;
    bool first = true;

    for (int i = 1; i <= n; i++)
      q.push_back(i);

    cout << "Discarded cards:";

    while (!q.empty()) {
      remain = q.front();
      q.pop_front();

      if (q.empty())
        break;

      if (first)
        cout << " " << remain;
      else
        cout << ", " << remain;

      remain = q.front();
      q.pop_front();
      q.push_back(remain);

      first = false;
    }
    cout << endl;

    cout << "Remaining card: " << remain << endl;
  }

  return 0;
}
