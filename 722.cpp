#include <iostream>
#include <string>
#include <queue>
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
    int m, row, col, r;
    int field[99][99];
    string input;

    cin >> m;

    while (m--) {
        cin >> row >> col;
        row--, col--;

        rep (i, 99)
            rep (j, 99)
                field[i][j] = 1;

        cin.ignore(100, '\n');

        r = 0;

        while (getline(cin, input)) {
            if (input == "")
                break;

            rep (i, input.size()) {
                field[r][i] = input[i] == '0' ? 0 : 1;
            }

            r++;
        }

        int count = 0;
        queue< pair<int,int> > q;
        field[row][col] = 1;
        q.push(make_pair(row,col));

        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();

            count++;

            row = p.first;
            col = p.second;

            if (row - 1 >= 0 && field[row-1][col] == 0) {
                field[row-1][col] = 1;
                q.push(make_pair(row-1,col));
            }

            if (col - 1 >= 0 && field[row][col-1] == 0) {
                field[row][col-1] = 1;
                q.push(make_pair(row,col-1));
            }

            if (row + 1 < 99 && field[row+1][col] == 0) {
                field[row+1][col] = 1;
                q.push(make_pair(row+1,col));
            }

            if (col + 1 < 99 && field[row][col+1] == 0) {
                field[row][col+1] = 1;
                q.push(make_pair(row,col+1));
            }
        }

        cout << count << endl;

        if (m)
            cout << endl;
    }

    return 0;
}
