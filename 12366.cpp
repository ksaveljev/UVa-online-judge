#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

bool is_set(int a, int b, int c) {
    return a == b && b == c;
}

bool is_pair(int a, int b, int c) {
    return a == b || a == c || b == c;
}

int main(void) {
    int a, b, c;

    while (cin >> a >> b >> c) {
        if (!a && !b && !c) {
            break;
        }

        if (is_set(a, b, c)) {
            if (a == 13) {
                cout << "*" << endl;
            } else {
                cout << a + 1 << " " << a + 1 << " " << a + 1 << endl;
            }
        } else if (is_pair(a, b, c)) {
            int kicker = a ^ b ^ c;
            int card = a == kicker ? b : a;
            if (kicker == 13) {
                cout << 1 << " " << card + 1 << " " << card + 1 << endl;
            } else if (card == 13) {
                if (kicker == 12) {
                    cout << "1 1 1" << endl;
                } else {
                    int x[3] = { card, card, kicker + 1 };
                    sort(x, x + 3);
                    cout << x[0] << " " << x[1] << " " << x[2] << endl;
                }
            } else {
                int x[3] = { card, card, kicker + 1 == card ? kicker + 2 : kicker + 1 };
                sort(x, x + 3);
                cout << x[0] << " " << x[1] << " " << x[2] << endl;
            }
        } else {
            cout << "1 1 2" << endl;
        }
    }

    return 0;
}
