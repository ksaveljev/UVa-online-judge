#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

bool is_prime(int n) {
    for (int i = 3, sq = sqrt(n); i <= sq; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

int main(void) {
    int k;
    vector<int> primes;

    primes.push_back(2);

    for (int i = 3; i <= 1299709; i += 2)
        if (is_prime(i))
            primes.push_back(i);

    while (cin >> k) {
        if (k == 0) break;

        rep (i, sz(primes)) {
            if (primes[i] == k) {
                cout << "0" << endl;
                break;
            }

            if (primes[i] > k) {
                cout << primes[i] - primes[i-1] << endl;
                break;
            }
        }
    }

    return 0;
}
