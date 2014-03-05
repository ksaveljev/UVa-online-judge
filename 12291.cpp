#include <iostream>
#include <cstdio>
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
char field[15][15], poly[15][15];
bool field_taken[15][15], poly_taken[15][15];
bool ok;

void dfs(int px, int py, int fx, int fy) {
    if (px < 0 || py < 0 || px >= m || py >= m) return;
    
    if (!ok || poly[px][py] == '.' || poly_taken[px][py]) return;

    if (fx < 0 || fy < 0 || fx >= n || fy >= n || field[fx][fy] == '.' || field_taken[fx][fy]) ok = false;

    poly_taken[px][py] = true;
    field_taken[fx][fy] = true;

    dfs (px + 1, py, fx + 1, fy);
    dfs (px - 1, py, fx - 1, fy);
    dfs (px, py + 1, fx, fy + 1);
    dfs (px, py - 1, fx, fy - 1);
}

int main(void) {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        cin.ignore(100, '\n');

        rep (i, n) scanf("%s", &field[i]);
        rep (i, m) scanf("%s", &poly[i]);

        pair<int,int> poly_start;

        rep (i, m) {
            rep (j, m) {
                if (poly[i][j] == '*') {
                    poly_start.first = i;
                    poly_start.second = j;
                    i = m, j = m;
                }
            }
        }

        int result = 0;

        rep (i, n) {
            rep (j, n) {
                if (field[i][j] != '*') continue;
                rep (a, 15) rep (b, 15) { field_taken[a][b] = false; poly_taken[a][b] = false; }
                ok = true;
                dfs (poly_start.first, poly_start.second, i, j);
                if (!ok) continue;

                rep (p, n) {
                    rep (q, n) {
                        if (field[p][q] == '.' || field_taken[p][q]) continue;
                        rep (a, 15) rep (b, 15) poly_taken[a][b] = false;
                        ok = true;
                        dfs (poly_start.first, poly_start.second, p, q);
                        if (!ok) continue;
                        result = 1;
                        p = n, q = n, i = n, j = n;
                    }
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
