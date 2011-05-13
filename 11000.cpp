#include <iostream>
#include <algorithm>
using namespace std;

unsigned int fib(int n) {
  unsigned int a = 1;
  unsigned int b = 2;

  if (n == 0)
    return a;
  if (n == 1)
    return b;

  for (int i = 2; i <= n; i++) {
    a = a + b;
    swap(a, b);
  }

  return b;
}

int main(void) {
  int n;

  while (cin >> n) {
    if (n == -1)
      break;

    cout << fib(n) - 1 << " " << fib(n+1) - 1 << endl;
  }

  return 0;
}
