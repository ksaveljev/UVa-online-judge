#include <iostream>
using namespace std;

bool fits(long long n)
{
  int nums[10] = {0};

  while (n) {
    nums[n%10]++;
    if (nums[n%10] > 1) {
      return false;
    }
    n /= 10;
  }

  return true;
}

int main(void)
{
  int t;
  long long s1, s2, n, limit = 9999999999LL;

  cin >> t;

  while (t--) {
    cin >> n;

    s1 = n;
    s2 = 1;

    while (true) {
      if (fits(s1) && fits(s2))
        cout << s1 << " / " << s2 << " = " << n << endl;
      s1 += n;
      s2++;

      if (s1 > limit) {
        break;
      }
    }

    if (t) {
      cout << endl;
    }
  }
  return 0;
}
