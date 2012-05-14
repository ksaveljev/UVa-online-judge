#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    unsigned long long n, La, Lb, Ra, Rb, Ma, Mb;
    string input;

    cin >> n;
    cin.ignore(100, '\n');

    while (n--) {
        getline(cin, input);

        La = 0, Lb = 1, Ra = 1, Rb = 0;

        Ma = (La + Ra), Mb = (Lb + Rb);

        rep (i, input.size()) {
            switch (input[i]) {
                case 'L':
                    Ra = Ma, Rb = Mb;
                    break;
                case 'R':
                    La = Ma, Lb = Mb;
                    break;
            }

            Ma = (La + Ra), Mb = (Lb + Rb);
        }

        cout << Ma << "/" << Mb << endl;
    }

    return 0;
}
