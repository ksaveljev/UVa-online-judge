#include <iostream>
#include <cmath>
using namespace std;

bool primes[32];
bool taken[17];
int circle[17];

bool is_prime(int n) {
    for (int i = 3, m = sqrt(n); i <= m; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

void init_primes() {
    for (int i = 0; i < 32; i++)
        primes[i] = false;

    primes[2] = true;

    for (int i = 3; i < 32; i += 2) {
        if (is_prime(i)) primes[i] = true;
    }
}

void solve(int idx, int n) {
    if (idx == n) {
        if (primes[circle[idx - 1] + circle[0]]) {
            for (int i = 0; i < n; i++) {
                if (i > 0) cout << " ";
                cout << circle[i];
            }
            cout << endl;
        }
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (!taken[i] && primes[i + circle[idx - 1]]) {
            circle[idx] = i;
            taken[i] = true;
            solve(idx + 1, n);
            taken[i] = false;
        }
    }
}

int main(void) {
    int n;
    int test_case = 0;

    init_primes();

    for (int i = 0; i < 17; i++) {
        taken[i] = false;
    }
    taken[1] = true;

    while (cin >> n) {
        test_case += 1;

        if (test_case > 1) cout << endl;

        cout << "Case " << test_case << ":" << endl;
        circle[0] = 1;
        solve(1, n);
    }

    return 0;
}
