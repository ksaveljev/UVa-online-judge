#include <iostream>
#include <string>
#include <algorithm>
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
    int case_number = 0;
    string input;
    int field[3][3];

    while (getline(cin, input)) {
        case_number++;
        rep (i, 3) rep (j, 3) field[i][j] = 0;

        reverse(input.begin(), input.end());

        rep (i, sz(input)) {
            switch (input[i]) {
                case 'a':
                    field[0][0] += 1;
                    field[0][1] += 1;
                    field[1][0] += 1;
                    break;
                case 'b':
                    field[0][0] += 1;
                    field[0][1] += 1;
                    field[0][2] += 1;
                    field[1][1] += 1;
                    break;
                case 'c':
                    field[0][1] += 1;
                    field[0][2] += 1;
                    field[1][2] += 1;
                    break;
                case 'd':
                    field[0][0] += 1;
                    field[1][0] += 1;
                    field[1][1] += 1;
                    field[2][0] += 1;
                    break;
                case 'e':
                    field[0][1] += 1;
                    field[1][0] += 1;
                    field[1][1] += 1;
                    field[1][2] += 1;
                    field[2][1] += 1;
                    break;
                case 'f':
                    field[0][2] += 1;
                    field[1][1] += 1;
                    field[1][2] += 1;
                    field[2][2] += 1;
                    break;
                case 'g':
                    field[1][0] += 1;
                    field[2][0] += 1;
                    field[2][1] += 1;
                    break;
                case 'h':
                    field[1][1] += 1;
                    field[2][0] += 1;
                    field[2][1] += 1;
                    field[2][2] += 1;
                    break;
                case 'i':
                    field[1][2] += 1;
                    field[2][1] += 1;
                    field[2][2] += 1;
                    break;
            }

            rep (i, 3) rep (j, 3) if (field[i][j] > 9) field[i][j] -= 10;
        }

        cout << "Case #" << case_number << ":" << endl;
        rep (i, 3) {
            rep (j, 3) {
                if (j > 0) cout << " ";
                cout << field[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
