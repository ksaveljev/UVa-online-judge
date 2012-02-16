#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void)
{
  int n, k;

  while (cin >> n >> k) {
    if (n == 0 && k == 0) {
      break;
    }

    queue< pair<int, int> > q;

    for (int i = 1; i <= n; i++) {
      q.push(make_pair(i, 40));
    }

    int tmp;
    int atm_store = 1;
    int next_limit = min(2, k);
    pair<int,int> student;

    while (!q.empty()) {
      student = q.front();
      q.pop();

      tmp = min(student.second, atm_store);
      student.second -= tmp;
      atm_store -= tmp;

      if (atm_store == 0) {
        atm_store = next_limit;
        next_limit++;
        if (next_limit > k) {
          next_limit = 1;
        }
      }

      if (student.second > 0) {
        q.push(student);
      } else {
        cout << setw(3) << student.first;
      }
    }

    cout << endl;
  }
  
  return 0;
}
