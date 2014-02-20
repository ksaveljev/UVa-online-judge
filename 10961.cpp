#include <iostream>
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

typedef struct _location {
    int row;
    int col;
} location;

int main(void) {
    int cases, n;
    location leporello, villagers, tmp, next_l, next_v;

    cin >> cases;

    while (cases--) {
        cin >> villagers.row >> villagers.col;
        cin >> leporello.row >> leporello.col;

        next_l = leporello;
        next_v = villagers;

        cin >> n;

        queue<location> leporello_route;

        while (n--) {
            cin >> tmp.row >> tmp.col;
            leporello_route.push(tmp);
        }

        cin >> n;

        queue<location> villagers_route;

        while (n--) {
            cin >> tmp.row >> tmp.col;
            villagers_route.push(tmp);
        }

        bool safe = true;

        while (true) {
            if (villagers.row == leporello.row && villagers.col == leporello.col) {
                if (leporello_route.empty() && leporello.row == next_l.row && leporello.col == next_l.col) {
                    safe = true;
                } else {
                    safe = false;
                }
                break;
            }

            if (next_l.row == leporello.row && next_l.col == leporello.col) {
                if (leporello_route.empty()) {
                    break;
                } else {
                    next_l = leporello_route.front();
                    leporello_route.pop();
                }
            }

            if (next_v.row == villagers.row && next_v.col == villagers.col) {
                if (villagers_route.empty()) {
                    break;
                } else {
                    next_v = villagers_route.front();
                    villagers_route.pop();
                }
            }

            if (leporello.row != next_l.row) {
                if (leporello.row < next_l.row)
                    leporello.row += 1;
                else
                    leporello.row -= 1;
            } else if (leporello.col != next_l.col) {
                if (leporello.col < next_l.col)
                    leporello.col += 1;
                else
                    leporello.col -= 1;
            }

            if (villagers.row != next_v.row) {
                if (villagers.row < next_v.row)
                    villagers.row += 1;
                else
                    villagers.row -= 1;
            } else if (villagers.col != next_v.col) {
                if (villagers.col < next_v.col)
                    villagers.col += 1;
                else
                    villagers.col -= 1;
            }
        }

        cout << (safe ? "Yes" : "No") << endl;
        if (cases) cout << endl;
    }

    return 0;
}
