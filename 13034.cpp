#include <iostream>
using namespace std;

int main(void) {
    int s;

    cin >> s;

    for (int x = 1; x <= s; x++) {
        bool ok = true;
        int tmp;
        for (int i = 0; i < 13; i++) {
            cin >> tmp;
            if (tmp == 0) {
                ok = false;
            }
        }

        cout << "Set #" << x << ": ";
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
