#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int n, tmp;
    
    while (cin >> n) {
        if (n == 0)
            break;

        tmp = 1;

        while (tmp * 2 <= n) {
            tmp *= 2;
        }

        cout << (2 * (n - tmp) == 0 ? n : 2 * (n - tmp)) << endl;
    }

    return 0;
}
