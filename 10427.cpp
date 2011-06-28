#include <iostream>
#include <cmath>
using namespace std;

int get_digit(int n, int d)
{
  int digits[9];

  for (int i = int(log10(n)); i >= 0; i--) {
    digits[i] = n % 10;
    n /= 10;
  }

  return digits[d];
}

int main(void)
{
  int n, i;
  int sum, tmp, num;
  int count[9] = {0, 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000 };

  while (cin >> n) {
    sum = 0;

    if (n < 10) {
      cout << n << endl;
      continue;
    }

    for (i = 1; i <= 8; i++) {
      sum += i * count[i];

      if (sum >= n) {
        break;
      }
    }

    for (int j = 0; j < i; j++) {
      n -= j * count[j];
    }

    tmp = (n % i == 0 ? n/i - 1 : n/i);
    num = (i == 1 ? 0 : int(pow(10, i-1))) + tmp;
    tmp = (n % i == 0 ? i - 1 : n % i - 1);
    cout << (i == 1 ? num : get_digit(num, tmp)) << endl;
  }
  
  return 0;
}
