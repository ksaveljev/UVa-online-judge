#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int t, case_num = 0;
    unsigned long long n, precalc[60];

    precalc[0] = 1;
    for (int i = 1; i < 60; i++)
        precalc[i] = precalc[i-1] * 2;

    cin >> t;

    while (t--) {
        case_num++;
        cout << "Case " << case_num << ": ";

        cin >> n;

        if (n == 0) {
            cout << "0" << endl;
            continue;
        }

        n++;

        for (int i = 0; i < 60; i++) {
            if (n <= precalc[i]) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
