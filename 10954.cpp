#include <iostream>
#include <queue>
using namespace std;

int main(void) {
  int n, tmp;
  int a, b;

  while (cin >> n) {
    if (!n)
      break;

    priority_queue< int, vector<int>, greater<int> > q;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      q.push(tmp);
    }

    int result = 0;

    while (true) {
      a = q.top();
      q.pop();

      if (q.empty())
        break;

      b = q.top();
      q.pop();

      result += a + b;
      q.push(a+b);
    }

    cout << result << endl;
  }

  return 0;
}
