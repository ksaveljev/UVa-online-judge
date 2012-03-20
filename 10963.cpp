#include <iostream>
using namespace std;

int main(void) {
    int cases, w, a, b;

    cin >> cases;

    while (cases--) {
        cin >> w;

        bool first = true, ok = true;
        int diff;

        while (w--) {
            cin >> a >> b;

            if (first) {
                first = false;
                diff = a - b;
            } else {
                if (a - b != diff)
                    ok = false;
            }
        }

        if (ok)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

        if (cases)
            cout << endl;
    }

    return 0;
}
