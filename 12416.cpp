#include <iostream>
#include <cmath>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int longest_spaces(string &input) {
    int result = 0;
    int tmp = 0;

    rep (i, input.size()) {
        if (input[i] == ' ') {
            tmp++;
        } else {
            if (tmp > result)
                result = tmp;

            tmp = 0;
        }
    }

    return result;
}

int main(void) {
    string input;

    while (getline (cin, input)) {
        cout << ceil(log2(longest_spaces(input))) << endl;
    }

    return 0;
}
