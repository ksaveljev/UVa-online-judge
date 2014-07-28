#include <iostream>
#include <queue>
#include <set>
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
    int number_of_cases;
    int R, C, M, N, W, x, y;
    int field[101][101];
    bool visited[101][101];
    pair<int,int> location, result;

    cin >> number_of_cases;

    REPI (case_number, 1, number_of_cases) {
        rep (i, 101) rep (j, 101) { field[i][j] = 0; visited[i][j] = false; }

        cin >> R >> C >> M >> N >> W;

        int direction[8][2] = {
            {M, N}, {-M, N}, {M, -N}, {-M, -N},
            {N, M}, {-N, M}, {N, -M}, {-N, -M}
        };

        while (W--) {
            cin >> x >> y;
            field[x][y] = -1;
        }

        visited[0][0] = true;
        queue< pair<int,int> > q;

        q.push(make_pair(0, 0));

        while (!q.empty()) {
            location = q.front();
            q.pop();

            set< pair<int,int> > s;

            rep (i, 8) {
                x = location.first + direction[i][0];
                y = location.second + direction[i][1];
                s.insert(make_pair(x, y));
            }

            for (set< pair<int,int> >::iterator it = s.begin(); it != s.end(); it++) {
                x = it->first;
                y = it->second;

                if (x >= 0 && x < R && y >= 0 && y < C && field[x][y] != -1) {
                    field[x][y]++;
                    if (!visited[x][y]) {
                        visited[x][y] = true;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }

        result = make_pair(0, 0);

        rep (i, R) {
            rep (j, C) {
                if (field[i][j] < 1) continue;
                if (field[i][j] % 2 == 1) {
                    result.second++;
                } else {
                    result.first++;
                }
            }
        }

        if (result.first == 0 && result.second == 0) result.first = 1;

        cout << "Case " << case_number << ": " << result.first << " " << result.second << endl;
    }

    return 0;
}
