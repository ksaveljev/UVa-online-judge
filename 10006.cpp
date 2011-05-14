#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool is_prime(int n) {
  if (n == 2)
    return true;
  
  if (n % 2 == 0)
    return false;

  for (int i = 3, sq = sqrt(n); i <= sq; i += 2)
    if (n % i == 0)
      return false;

  return true;
}

// a ^ k mod n
unsigned int calc(unsigned int a, int k, int n) {
  if (k == 1)
    return a;

  if (k % 2 == 0)
    return calc((a * a) % n, k / 2, n);
  else
    return (a * calc((a * a) % n, k / 2, n)) % n;
}

int main(void) {
  int n;
  vector<int> carmichael;

  for (int i = 2; i < 65000; i++) {
    if (is_prime(i))
      continue;

    unsigned int j;
    for (j = 2; j < i; j++) {
      if (calc(j, i, i) != j)
        break;
    }

    if (j == i)
      carmichael.push_back(i);
  }

  while (cin >> n) {
    if (n == 0)
      break;

    bool found = false;
    for (int i = 0, sz = carmichael.size(); i < sz; i++) {
      if (carmichael[i] == n) {
        found = true;
        break;
      }
    }

    if (found) {
      cout << "The number " << n << " is a Carmichael number." << endl;
    } else {
      cout << n << " is normal." << endl;
    }
  }

  return 0;
}
