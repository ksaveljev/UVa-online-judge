#include <iostream>
#include <string>
using namespace std;

string alphabet = "pqrstuvwxyzNCDEI";

bool is_correct_hedonian(string &s) {
    int stack = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] >= 'p' && s[i] <= 'z') {
            stack++;
        } else if (s[i] == 'N') {
            if (stack < 1) {
                break;
            }
        } else if (s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'I') {
            if (stack < 2) {
                stack = 0;
                break;
            } else {
                stack--;
            }
        }
    }

    return stack == 1;
}

bool is_hedonian(string &s) {
    size_t found;

    for (int i = 0, sz = s.size(); i < sz; i++) {
        found = alphabet.find(s[i]);
        if (found == string::npos)
            return false;
    }

    return is_correct_hedonian(s);
}

int main(void) {
    string input;

    while (getline(cin, input)) {
        cout << (is_hedonian(input) ? "YES" : "NO") << endl;
    }

    return 0;
}
