#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

bool is_number (char c) {
    return c >= '0' && c <= '9';
}

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap (a, b);
    }

    return a;
}

int main(void) {
    int cases, tmp;
    string input;

    cin >> cases;
    cin.ignore(1000, '\n');

    while (cases--) {
        getline(cin, input);

        int top = 1, bottom = 1, current_top, current_bottom;

        rep (i, input.size()) {
            if (!is_number(input[i]))
                continue;

            for (tmp = 0; i < input.size() && is_number(input[i]); i++)
                tmp = tmp * 10 + input[i] - '0';

            if (i == input.size() || input[i] == ' ')
                current_top = tmp, current_bottom = 1;
            else if (input[i] == '-') {
                for (current_top = 0, i++; i < input.size() && is_number(input[i]); i++)
                    current_top = current_top * 10 + input[i] - '0';
                for (current_bottom = 0, i++; i < input.size() && is_number(input[i]); i++)
                    current_bottom = current_bottom * 10 + input[i] - '0';

                current_top += tmp * current_bottom;
            } else if (input[i] == '/') {
                current_top = tmp;

                for (tmp = 0, i++; i < input.size() && is_number(input[i]); i++)
                    tmp = tmp * 10 + input[i] - '0';

                current_bottom = tmp;
            }

            top *= current_top;
            bottom *= current_bottom;
            i--;
        }

        int _gcd = gcd(top, bottom);
        top /= _gcd;
        bottom /= _gcd;

        if (top % bottom == 0)
            cout << top / bottom << endl;
        else if (top / bottom)
            cout << top / bottom << "-" << top % bottom << "/" << bottom << endl;
        else
            cout << top << "/" << bottom << endl;
    }

    return 0;
}
