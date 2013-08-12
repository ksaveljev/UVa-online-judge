#include <iostream>
#include <string>
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

int main(void) {
    int n;
    string input;
    string margarita = "MARGARITA";
    int count[30];

    cin >> n;
    cin.ignore(100, '\n');

    while (n--) {
        getline(cin, input);

        rep (i, 30) {
            count[i] = 0;
        }

        rep (i, input.size()) {
            count[input[i] - 'A']++;
        }

        int result = 0;

        bool ok = true;
        while (ok) {
            rep (i, margarita.size()) {
                if (count[margarita[i] - 'A'] < 1) {
                    ok = false;
                    break;
                } else {
                    count[margarita[i] - 'A']--;
                }
            }

            if (ok) {
                result++;
            }
        }

        cout << result << endl;
    }

    return 0;
}
