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
    int T;
    string input;

    cin >> T;
    cin.ignore(100, '\n');

    while (T--) {
        getline(cin, input);

        int result = 0;
        int counter = 0;

        rep (i, sz(input)) {
            if (input[i] == 'O') {
                counter++;
                result += counter;
            } else {
                counter = 0;
            }
        }

        cout << result << endl;
    }

    return 0;
}
