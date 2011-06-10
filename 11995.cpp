#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(void) {
  int n;
  int a, b;

  while (cin >> n) {
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    bool is_s, is_q, is_pq;

    is_s = is_q = is_pq = true;

    while (n--) {
      cin >> a >> b;

      if (a == 1) {
        if (is_s)
          s.push(b);
        if (is_q)
          q.push(b);
        if (is_pq)
          pq.push(b);
      } else { // a == 2;
        if (is_s) {
          if (s.empty() || s.top() != b) {
            is_s = false;
          } else {
            s.pop();
          }
        }
        if (is_q) {
          if (q.empty() || q.front() != b) {
            is_q = false;
          } else {
            q.pop();
          }
        }
        if (is_pq) {
          if (pq.empty() || pq.top() != b) {
            is_pq = false;
          } else {
            pq.pop();
          }
        }
      }
    }

    if (!is_s && !is_q && !is_pq) {
      cout << "impossible" << endl;
    } else if (is_s && !is_q && !is_pq) {
      cout << "stack" << endl;
    } else if (!is_s && is_q && !is_pq) {
      cout << "queue" << endl;
    } else if (!is_s && !is_q && is_pq) {
      cout << "priority queue" << endl;
    } else {
      cout << "not sure" << endl;
    }
  }

  return 0;
}
