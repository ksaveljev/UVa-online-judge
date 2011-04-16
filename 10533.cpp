#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

map<int,bool> isprime;

bool is_prime(int n) {
  if (n == 2)
    return true;

  if (n % 2 == 0)
    return false;

  if (isprime.find(n) != isprime.end())
    return isprime[n];

  for (int i = 3, sq = sqrt(n); i <= sq; i += 2) {
    if (n % i == 0)
      return false;
  }

  return true;
}

bool is_digitprime(int n) {
  int sum = 0;
  while (n) {
    sum = sum + n % 10;
    n /= 10;
  }

  return is_prime(sum);
}

int main(void) {
  int n;
  int tmp;
  int counter;
  int t1, t2;
  int *result;

  result = new int[1000000];
  result[0] = 0;
  result[1] = 0;

  isprime[2] = true;
  result[2] = 1;

  counter = 3;

  for (int i = 3; i < 1000000; i += 2) {
    if (is_prime(i)) {
      isprime[i] = true;
      if (is_digitprime(i)) {
        for (int j = counter; j < i; j++) {
          result[j] = result[j-1];
        }
        result[i] = result[i-1] + 1;
        counter = i + 1;
      }
    }
  }

  for (int j = counter; j < 1000000; j++)
    result[j] = result[j-1];

  cin >> n;

  while (n--) {
    cin >> t1 >> t2;

    cout << result[t2] - result[t1 - 1] << endl;
  }

  delete [] result;

  return 0;
}
