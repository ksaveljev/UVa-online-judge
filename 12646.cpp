#include <iostream>
using namespace std;

int a, b, c;

void winner(int v) {
    if (a == v) cout << "A" << endl;
    if (b == v) cout << "B" << endl;
    if (c == v) cout << "C" << endl;
}

int main(void) {

    while (cin >> a >> b >> c) {
        int s = a + b + c;
        if (s == 0 || s == 3) cout << "*" << endl;
        else if (s == 1) {
            winner(1);
        } else if (s == 2) {
            winner(0);
        }
    }

    return 0;
}
