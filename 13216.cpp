#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int t;
    string n;

    cin >> t;
    cin.ignore();

    while (t--) {
        getline(cin, n);

        if (n == "0") {
            cout << 1 << endl;
        } else if (n == "1") {
            cout << "66" << endl;
        } else {
            switch(n[n.size() - 1]) {
                case '0':
                case '5':
                    cout << 76 << endl;
                    break;
                case '1':
                case '6':
                    cout << 16 << endl;
                    break;
                case '2':
                case '7':
                    cout << 56 << endl;
                    break;
                case '3':
                case '8':
                    cout << 96 << endl;
                    break;
                case '4':
                case '9':
                    cout << 36 << endl;
                    break;
            }
        }
    }

    return 0;
}
