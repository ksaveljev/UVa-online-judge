#include <iostream>
#include <map>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int case_number = 0;
    int r, c, n;
    int x, y;

    while (cin >> r >> c >> n) {
        if (r == 0 && c == 0 && n == 0)
            break;

        map<int,bool> row_taken, col_taken;

        while (n--) {
            cin >> x >> y;
            row_taken[x] = true;
            col_taken[y] = true;
        }

        cin >> x >> y;

        bool ok = false;

        int dx[] = { 0, 0, 0, -1, 1 };
        int dy[] = { 0, -1, 1, 0, 0 };

        rep (i, 5) {
            if (x + dx[i] >= 0 && x + dx[i] < r && y + dy[i] >= 0 && y + dy[i] < c && !row_taken[x + dx[i]] && !col_taken[y + dy[i]])
                ok = true;
        }

        if (ok)
            cout << "Case " << ++case_number << ": Escaped again! More 2D grid problems!" << endl;
        else
            cout << "Case " << ++case_number << ": Party time! Let's find a restaurant!" << endl;
    }

    return 0;
}
