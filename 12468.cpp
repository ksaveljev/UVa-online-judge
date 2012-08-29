#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int a, b;

    while (cin >> a >> b) {
        if (a == -1 && b == -1)
            break;

        if (a > b)
            swap(a, b);

        int result = b - a;

        result = min(result, 100 + a - b);

        cout << result << endl;
    }

    return 0;
}
