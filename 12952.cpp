#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int a, b;

    while (cin >> a >> b) {
        if (a == b) {
            cout << a << endl;
        } else {
            cout << max(a, b) << endl;
        }
    }

    return 0;
}
