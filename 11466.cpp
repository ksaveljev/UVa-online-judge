#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int MAX_N = 10000000;

int main(void)
{
  int *lp = new int[MAX_N];
  vector<int> primes;
  long long input;


  fill(lp, lp + MAX_N, 0);


  for (int i = 2; i < MAX_N; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }

    for (int j = 0; j < primes.size() && primes[j] <= lp[i] && i * primes[j] < MAX_N; j++) {
      lp[i * primes[j]] = primes[j];
    }
  }


  while (cin >> input) {
    if (input == 0) {
      break;
    }

    bool negative = false;
    bool found = false;
    long long result = 0;
    int divisor_count = 0;

    if (input < 0) {
      input = -input;
    }

    for (int i = 0, sz = primes.size(); i < sz; i++) {
      if (primes[i] > input) {
        break;
      } else if (input == primes[i]) {
        break;
      } else if (input % primes[i] == 0) {
        found = true;
        result = primes[i];
        divisor_count++;

        do {
          input /= primes[i];
        } while (input % primes[i] == 0);
      }
    }

    if (!found) {
      cout << -1 << endl;
    } else if (divisor_count < 2 && input == 1) {
      cout << -1 << endl;
    } else if (input > result) {
      cout << input << endl;
    } else {
      cout << result << endl;
    }
  }
  


  delete [] lp;
  
  return 0;
}
