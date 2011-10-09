#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int num_length(int n) {
  return int(log10(n)) + 1;
}

int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  
  return a;
}

int main(void)
{
  int n, sum, tmp, case_num = 0;
  bool negative;

  while (cin >> n) {
    if (n == 0) {
      break;
    }

    case_num++;
    sum = 0;

    for (int i = 0; i < n; i++) {
      cin >> tmp;
      sum += tmp;
    }

    if (sum < 0) {
      negative = true;
      sum = -sum;
    } else {
      negative = false;
    }

    cout << "Case " << case_num << ":" << endl;

    if (sum % n == 0) {
      if (negative) {
        cout << "- ";
      }
      cout << sum / n << endl;
    } else {
      int offset = 0;

      if (negative) {
        offset += 2;
      }

      int int_v, frac_v;

      if (sum > n) {
        // int value
        int_v = sum / n;
        offset += num_length(int_v);

        // fractional value
        frac_v = sum - (n * int_v);
        int div = gcd(frac_v, n);
        frac_v /= div;
        n /= div;
      } else {
        int_v = 0;
        frac_v = sum;
        int div = gcd(frac_v, n);
        frac_v /= div;
        n /= div;
      }

      for (int i = 0; i < offset + num_length(n) - num_length(frac_v); i++) {
          cout << " ";
      }
      
      cout << frac_v << endl;

      if (negative) {
        cout << "- ";
      }

      if (int_v != 0) {
        cout << int_v;
      }

      for (int i = 0; i < num_length(n); i++) {
        cout << "-";
      }
      cout << endl;

      for (int i = 0; i < offset; i++) {
        cout << " ";
      }

      cout << n << endl;
    }
  }
  
  return 0;
}
