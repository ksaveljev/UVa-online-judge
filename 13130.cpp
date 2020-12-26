#include <iostream>
using namespace std;

int main(void) {
    int t;
    int v[5];

    cin >> t;

    while (t--) {
        for (int i = 0; i < 5; i++) {
            cin >> v[i];
        }

        bool ok = true;

        for (int i = 1; i < 5; i++) {
            if (v[i] - v[i-1] != 1) {
                ok = false;
            }
        }

        if (ok) cout << "Y" << endl;
        else cout << "N" << endl;
    }

    return 0;
}
