#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

struct code {
    int n;
    int steps;
};

int main(void) {
    int l, u, r, b, case_number = 0;
    code tmp, t;

    while (cin >> l >> u >> r) {
        if (l == 0 && u == 0 && r == 0) break;

        case_number++;

        vector<int> buttons;

        rep (i, r) {
            cin >> b;
            buttons.push_back(b);
        }

        map<int,bool> visited;
        tmp.n = l;
        tmp.steps = 0;
        visited[l] = true;

        queue<code> q;
        q.push(tmp);

        int result = -1;

        while (!q.empty()) {
            tmp = q.front();
            q.pop();

            if (tmp.n == u) {
                result = tmp.steps;
                break;
            }

            rep (i, r) {
                l = tmp.n + buttons[i];
                l %= 10000;

                if (visited.find(l) == visited.end()) {
                    visited[l] = true;
                    t.n = l;
                    t.steps = tmp.steps + 1;
                    q.push(t);
                }
            }
        }

        cout << "Case " << case_number << ": ";
        if (result == -1)
            cout << "Permanently Locked" << endl;
        else
            cout << result << endl;
    }

    return 0;
}
