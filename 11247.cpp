#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    long long m, x;

    while (cin >> m >> x) {
        if (m == 0 && x == 0)
            break;

        if (m == 1 || x == 0 || x == 100) {
            cout << "Not found" << endl;
            continue;
        }

        long long v = (m - 1) * 100 / (100 - x);

        if ((m-1)*100 % (100-x) == 0)
            v--;

        if (v < m)
            cout << "Not found" << endl;
        else 
            cout << v << endl;
    }

    return 0;
}
