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

int main(void) {
    int case_number = 0;
    int p, c, tmp, e;
    char command;

    while (cin >> p >> c) {
        if (p == 0 && c == 0) break;

        case_number++;
        deque<int> dq;

        if (p < 2000) {
            REPI (i, 1, p) dq.push_back(i);
        } else {
            REP (i, 1, 2000) dq.push_back(i);
        }

        cout << "Case " << case_number << ":" << endl;

        while (c--) {
            cin >> command;

            if (command == 'N') {
                e = dq.front();
                dq.pop_front();
                cout << e << endl;
                dq.push_back(e);
            } else {
                cin >> e;
                for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++) {
                    if (*it == e) {
                        dq.erase(it);
                        break;
                    }
                }
                dq.push_front(e);
            }
        }
    }

    return 0;
}
