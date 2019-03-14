#include <iostream>
using namespace std;

int main(void) {
    int n;

    while (cin >> n) {
        if (n == -1) break;

        for (int i = 64000; i >= 1; i--) {
            int a1 = (2 * n / i + 1 - i) / 2;
            if (a1 <= 0) continue;
            int ai = a1 + i - 1;
            int s = i * (a1 + ai) / 2;
            if (s == n) {
                cout << n << " = " << a1 << " + ... + " << ai << endl;
                break;
            }
        }
    }

    return 0;
}
