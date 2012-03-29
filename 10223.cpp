#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

unsigned long long catalan_numbers[20];

void compute_catalan_numbers() {
    catalan_numbers[1] = 1;

    REP (i, 2, 20) {
        catalan_numbers[i] = (2 * (i-1) + 2) * (2 * (i-1) + 1) * catalan_numbers[i-1] / (((i-1) + 1) * ((i-1) + 2));
    }
}

int main(void) {
    unsigned long long n;

    compute_catalan_numbers();

    while (cin >> n) {
        rep (i, 20) {
            if (catalan_numbers[i] == n) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
