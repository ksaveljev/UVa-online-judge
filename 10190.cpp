#include <iostream>
using namespace std;

int main(void) {
    int a, b;

    while (cin >> a >> b) {
        if (a < 2 || b < 2 || a < b) {
            cout << "Boring!" << endl;
            continue;
        }

        int tmp = a;

        while (tmp % b == 0) {
            tmp /= b;
        }

        if (tmp == 1) {
            bool first = true;
            while (a >= 1) {
                if (!first)
                    cout << " ";
                cout << a;
                a /= b;
                first = false;
            }
            cout << endl;
        } else {
            cout << "Boring!" << endl;
        }
    }

    return 0;
}
