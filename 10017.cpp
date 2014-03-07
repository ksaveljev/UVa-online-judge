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

int n, m;
int pegs[3][252];
int top[3];

void print_pegs() {
    rep (i, 3) {
        cout << char('A' + i) << "=>";
        if (top[i] >= 0) {
            cout << "  ";
            repi (j, top[i]) cout << " " << pegs[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int a, int b, int c, int n) {
    if (n > 0) {
        solve(a, c, b, n-1);

        pegs[c][++top[c]] = pegs[a][top[a]--];
        if (m-- > 0) print_pegs();
        else return;
        
        solve(b, a, c, n-1);
    }
}

int main(void) {
    int case_number = 0;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        case_number++;
        cout << "Problem #" << case_number << endl << endl;

        for (int i = n; i >= 1; i--) pegs[0][n-i] = i;
        top[0] = n - 1;
        top[1] = top[2] = -1;

        print_pegs();

        solve(0, 1, 2, n);
    }

    return 0;
}
