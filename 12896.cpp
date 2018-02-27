#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

char decode[10][4] = {
    {' ', ' ', ' ', ' '},
    {'.', ',', '?', '"'},
    {'a', 'b', 'c', ' '},
    {'d', 'e', 'f', ' '},
    {'g', 'h', 'i', ' '},
    {'j', 'k', 'l', ' '},
    {'m', 'n', 'o', ' '},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v', ' '},
    {'w', 'x', 'y', 'z'}
};

int main(void) {
    int t, L, count;
    int nums[100];

    cin >> t;

    while (t--) {
        cin >> L;

        rep (i, L) {
            cin >> nums[i];
        }
        rep (i, L) {
            cin >> count;
            cout << decode[nums[i]][count - 1];
        }
        cout << endl;
    }

    return 0;
}
