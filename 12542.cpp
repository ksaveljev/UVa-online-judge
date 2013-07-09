#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
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
    if (n == 2) return true;
    if (n < 3) return false;
    if (n % 2 == 0) return false;

    for (int i = 3, sq = sqrt(n); i <= sq; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

string int_to_string(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

int main(void) {
    string input;
    vector<string> primes;

    primes.push_back("2");

    for (int i = 3; i < 100000; i += 2) {
        if (is_prime(i)) {
            primes.push_back(int_to_string(i));
        }
    }

    while (getline(cin, input)) {
        if (input == "0")
            break;

        for (vector<string>::reverse_iterator it = primes.rbegin(); it != primes.rend(); it++) {
            if (input.find(*it) != string::npos) {
                cout << *it << endl;
                break;
            }
        }
    }

    return 0;
}
