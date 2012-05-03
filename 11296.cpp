#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int n;
    unsigned long long result;

    while (cin >> n) {
        result = 0;

        if (n % 2 == 0) {
            for (int i = 0; i <=n ; i += 2) {
                result += (n - i) / 2 + 1;
            }
        } else {
            for (int i = 1; i <= n; i += 2) {
                result += (n - i) / 2 + 1;
            }
        }

        cout << result << endl;
    }

    return 0;
}
