#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

map<int,bool> isprime;

bool is_prime(int n) {
  for (int i = 3, sq = sqrt(n); i <= sq; i += 2) {
    if (n % i == 0)
      return false;
  }

  return true;
}

bool is_circular(int prime) {
  int size = (int)log10(prime) + 1;

  for (int i = 0; i < size; i++) {
    prime = (prime % (int)pow(10, size-1))*10 + prime/(int)pow(10, size-1);
    if (isprime[prime] == false)
      return false;
  }

  return true;
}

int main(void) {
  int a, b;
  vector<int> primes;
  vector<int> circular;

  for (int i = 101; i < 1000000; i += 2) {
    if (is_prime(i)) {
      primes.push_back(i);
      isprime[i] = true;
    }
  }

  for (int i = 0, sz = primes.size(); i < sz; i++) {
    if (is_circular(primes[i]))
      circular.push_back(primes[i]);
  }

  while (cin >> a) {
    if (a == -1)
      break;

    cin >> b;

    int result = 0;
    for (int i = 0, sz = circular.size(); i < sz; i++) {
      if (circular[i] > b)
        break;

      if (circular[i] < a)
        continue;

      result++;
    }

    if (result == 0) {
      cout << "No Circular Primes." << endl;
    } else if (result == 1) {
      cout << "1 Circular Prime." << endl;
    } else {
      cout << result << " Circular Primes." << endl;
    }
  }

  return 0;
}
