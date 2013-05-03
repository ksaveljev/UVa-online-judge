#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

string gen_side(char a, char b) {
    if (a > b)
        return b + "" + a;
    else
        return a + "" + b;
}

int main(void) {
    string input;

    while (getline(cin, input)) {
        vector<string> a, b;

        a.push_back(gen_side(input[0], input[5]));
        a.push_back(gen_side(input[1], input[4]));
        a.push_back(gen_side(input[2], input[3]));

        b.push_back(gen_side(input[6], input[11]));
        b.push_back(gen_side(input[7], input[10]));
        b.push_back(gen_side(input[8], input[9]));

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool ok = true;
        rep(i, 3) {
            if (a[i] != b[i]) {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }

    return 0;
}
