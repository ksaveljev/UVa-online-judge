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

char braille[10][6] = {
    {'.','*','*','*','.','.'},
    {'*','.','.','.','.','.'},
    {'*','.','*','.','.','.'},
    {'*','*','.','.','.','.'},
    {'*','*','.','*','.','.'},
    {'*','.','.','*','.','.'},
    {'*','*','*','.','.','.'},
    {'*','*','*','*','.','.'},
    {'*','.','*','*','.','.'},
    {'.','*','*','.','.','.'},
};

void process_decimal(int d) {
    string input;
    getline(cin, input);

    rep (i, 3) {
        rep (j, sz(input)) {
            if (j > 0) cout << " ";
            cout << braille[input[j]-'0'][2*i] << braille[input[j]-'0'][2*i+1];
        }
        cout << endl;
    }
}

void process_braille(int d) {
    char b[3][310];
    string input;

    rep (i, 3) {
        getline(cin, input);
        for (int j = 0; j < sz(input); j += 3) {
            b[i][j*2/3] = input[j];
            b[i][j*2/3+1] = input[j+1];
        }
    }

    rep (i, d) {
        rep (j, 10) {
            if (braille[j][0] == b[0][i*2] &&
                braille[j][1] == b[0][i*2+1] &&
                braille[j][2] == b[1][i*2] &&
                braille[j][3] == b[1][i*2+1] &&
                braille[j][4] == b[2][i*2] &&
                braille[j][5] == b[2][i*2+1]) {
                cout << j;
                break;
            }
        }
    }

    cout << endl;
}

int main(void) {
    int D;
    char type;

    while (cin >> D) {
        if (D == 0) break;

        cin >> type;
        cin.ignore(100, '\n');

        if (type == 'S') {
            process_decimal(D);
        } else if (type == 'B') {
            process_braille(D);
        }
    }

    return 0;
}
