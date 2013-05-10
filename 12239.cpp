#include <iostream>
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

int abs(int a) {
    return a < 0 ? -a : a;
}

int main(void) {
    int n, b;
    int ball;

    while (cin >> n >> b) {
        if (n == 0 && b == 0)
            break;

        vector<int> balls;

        rep (i, b) {
            cin >> ball;
            balls.push_back(ball);
        }

        bool possible[n+1];

        rep (i, n+1) {
            possible[i] = false;
        }

        rep (i, b) {
            rep (j, b) {
                possible[abs(balls[i] - balls[j])] = true;
            }
        }

        bool ok = true;
        rep (i, n+1) {
            if (possible[i] == false) {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }

    return 0;
}
