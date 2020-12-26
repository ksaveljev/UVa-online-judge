#include <iostream>
using namespace std;

int main(void) {
    int t;

    while (cin >> t) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;

        int result = 0;

        if (a == t) result++;
        if (b == t) result++;
        if (c == t) result++;
        if (d == t) result++;
        if (e == t) result++;

        cout << result << endl;
    }

    return 0;
}
