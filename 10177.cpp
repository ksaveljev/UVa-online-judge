#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int N;
    unsigned long long S2, S3, S4, R2, R3, R4;

    while (cin >> N) {
        S2 = S3 = S4 = R2 = R3 = R4 = 0;

        REP (i, 1, N+1) {
            S2 += i * i;
            S3 += i * i * i;
            S4 += i * i * i * i;
        }

        REP (i, 1, N+1) {
            REP (j, 1, N+1) {
                R2 += i * j;
                REP (k, 1, N+1) {
                    R3 += i * j * k;
                    REP (l, 1, N+1) {
                        R4 += i * j * k * l;
                    }
                }
            }
        }

        cout << S2 << " " << R2 - S2 << " " << S3 << " " << R3 - S3 << " " << S4 << " " << R4 - S4 << endl;
    }

    return 0;
}
