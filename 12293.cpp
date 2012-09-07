#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    unsigned long long n, i;

    while (cin >> n) {
        if (n == 0)
            break;

        i = 1;

        while (i < n) {
            i = i * 2 + 1;
        }

        if (n == i)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }

    return 0;
}
