#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int asc_num(int n) {
  int tmp;
  int nums[10];

  for (int i = 0; i < 10; i++)
    nums[i] = 0;

  while (n) {
    nums[n % 10]++;
    n /= 10;
  }

  tmp = 0;
  for (int i = 0; i < 10; i++) {
    while (nums[i]) {
      tmp = tmp * 10 + i;
      nums[i]--;
    }
  }

  return tmp;
}

int desc_num(int n) {
  int tmp;
  int nums[10];

  for (int i = 0; i < 10; i++)
    nums[i] = 0;

  while (n) {
    nums[n % 10]++;
    n /= 10;
  }

  tmp = 0;
  for (int i = 9; i >= 0; i--) {
    while (nums[i]) {
      tmp = tmp * 10 + i;
      nums[i]--;
    }
  }

  return tmp;
}

int main(void) {
  int n;
  int counter;
  int a, b, c;
  map<int,bool> visited;

  while (cin >> n) {
    if (n == 0)
      break;

    counter = 0;
    visited.clear();

    cout << "Original number was " << n << endl;

    while (true) {
      a = desc_num(n);
      b = asc_num(n);
      c = a - b;

      counter++;

      cout << a << " - " << b << " = " << c << endl;

      if (visited.find(c) != visited.end()) {
        cout << "Chain length " << counter << endl;
        cout << endl;
        break;
      }

      visited[c] = true;
      n = c;
    }
  }

  return 0;
}
