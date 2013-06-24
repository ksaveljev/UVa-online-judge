#include <iostream>
#include <cmath>
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

#define N 1120
#define K 14
#define PRIMES_NR 187

bool is_prime(int n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;

    for (int i = 3, sz = sqrt(n); i <= sz; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int primes[PRIMES_NR];
int dp[N+1][K+1][PRIMES_NR+1];
int n, k;

int main(void) {
    int index = 0;
    repi (i, N) {
        if (is_prime(i)) {
            primes[index] = i;
            index++;
        }
    }

    repi (a, N) {
        repi (b, K) {
            repi (c, PRIMES_NR) {
                dp[a][b][c] = 0;
            }
        }
    }

    REPI (a, 1, N) {
        if (is_prime(a)) {
            REPI (c, 1, PRIMES_NR) {
                if (primes[c-1] < a) continue;
                else dp[a][1][c] = 1;
            }
        }
    }

    REPI (a, 1, N) {
        REPI (b, 2, K) {
            REPI (c, 1, PRIMES_NR) {
                if (primes[c-1] <= a) {
                    dp[a][b][c] = dp[a-primes[c-1]][b-1][c-1] + dp[a][b][c-1];
                } else {
                    dp[a][b][c] = dp[a][b][c-1];
                }
            }
        }
    }

    while (cin >> n >> k) {
        if (n == 0 && k == 0)
            break;

        cout << dp[n][k][PRIMES_NR] << endl;
    }

    return 0;
}
