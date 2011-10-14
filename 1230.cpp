#include <iostream>
using namespace std;

unsigned int calc(unsigned int x, int y, int n) {
  if (y == 1) {
    return x;
  }

  if (y % 2 == 0) {
    return calc((x*x) % n, y / 2, n);
  } else {
    return (x * calc((x*x) %n, y / 2, n)) % n;
  }
}

int main(void)
{
  int cases;
  unsigned int x;
  int y, n;

  cin >> cases;

  while (cases--) {
    cin >> x >> y >> n;
    cout << calc(x, y, n) << endl;
  }
  
  return 0;
}
