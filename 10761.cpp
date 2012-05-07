#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

string extra_broken_keys(int keys[128]) {
    string result = "";

    for (char c = 'a'; c <= 'z'; c++) {
        if (keys[c] == 0)
            result += c;
    }

    return result;
}

int main(void) {
    int case_number = 0;
    string input, broken_keys;

    cout << "+----------+----------------+-----------------------------+" << endl;
    cout << "| Keyboard | # of printable | Additionally, the following |" << endl;
    cout << "|          |      lines     |  letter keys can be broken  |" << endl;
    cout << "+----------+----------------+-----------------------------+" << endl;

    while (getline(cin, broken_keys)) {
        if (broken_keys == "finish")
            break;

        case_number++;

        int number_of_printable_lines = 0;
        int keys[128] = { 0 };

        transform(broken_keys.begin(), broken_keys.end(), broken_keys.begin(), ::tolower);

        rep (i, broken_keys.size()) {
            keys[broken_keys[i]]++;
        }

        bool should_end = false;

        while (getline(cin, input)) {
            if (input == "END")
                should_end = true;

            transform(input.begin(), input.end(), input.begin(), ::tolower);

            bool ok = true;

            rep (i, input.size()) {
                if (broken_keys.find(input[i]) != string::npos) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                number_of_printable_lines++;

                rep (i, input.size()) {
                    keys[input[i]]++;
                }
            }

            if (should_end)
                break;
        }

        printf("|   %3d    |      %3d       | ", case_number, number_of_printable_lines);

        string s = extra_broken_keys(keys);
        cout << s;

        int space = s.size();
        while (28 - space) {
            cout << " ";
            space++;
        }

        cout << "|" << endl;

        cout << "+----------+----------------+-----------------------------+" << endl;
    }

    return 0;
}
