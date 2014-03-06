#include <iostream>
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
    int T, N;
    char field[101];

    cin >> T;

    REPI (case_number, 1, T) {
        cin >> N;

        rep (i, N) cin >> field[i];

        int counter = 0;

        rep (i, N) {
            if (field[i] == '.') {
                counter++;
                if (i + 1 < N) field[i+1] = '#';
                if (i + 2 < N) field[i+2] = '#';
            }
        }

        cout << "Case " << case_number << ": " << counter << endl;
    }

    return 0;
}
