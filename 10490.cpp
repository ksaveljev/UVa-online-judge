#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n) {
  if (n == 2)
    return true;

  if (n % 2 == 0)
    return false;

  for (int i = 3, sq = sqrt(n); i <= sq; i++)
    if (n % i == 0)
      return false;

  return true;
}

int main(void) {
  int n;

  while (cin >> n) {
    if (!n)
      break;

    if (is_prime(n)) {
      if (is_prime(pow(2, n)-1)) {
        unsigned long long result = pow(2, n-1) * (pow(2, n) - 1);
        cout << "Perfect: " << result << "!" << endl;
      } else {
        cout << "Given number is prime. But, NO perfect number is available." << endl;
      }
    } else {
      cout << "Given number is NOT prime! NO perfect number is available." << endl;
    }
  }

  return 0;
}
