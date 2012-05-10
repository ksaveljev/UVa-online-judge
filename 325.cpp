#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

string strip_input (string &input) {
    int start, end, sz;

    for (start = 0, sz = input.size(); start < sz; start++) {
        if (input[start] != ' ')
            break;
    }

    for (end = input.size() - 1; end >= 0; end--) {
        if (input[end] != ' ')
            break;
    }

    return input.substr(start, end - start + 1);
}

bool is_legal_fraction_number (string &number, bool must_be_integer) {
    int counter = 0;

    if (number[0] == '-' || number[0] == '+')
        number = number.substr(1);

    if (number.empty())
        return false;

    rep (i, number.size()) {
        if (number[i] >= '0' && number[i] <= '9' || number[i] == '.') {
            if (number[i] == '.')
                counter++;
            continue;
        }

        return false;
    }

    if (counter > 1)
        return false;

    if (counter == 1) {
        if (must_be_integer)
            return false;

        size_t pos = number.find('.');
        string before, after;

        before = number.substr(0, pos);
        after = number.substr(pos+1);

        if (before.empty() || after.empty())
            return false;
    }

    return true;
}

bool is_legal (string input) {
    string before, after;

    rep (i, input.size()) {
        if (input[i] == ' ')
            return false;

        if (input[i] == 'e')
            input[i] = 'E';
    }

    size_t pos = input.find('E');

    if (pos == string::npos) {
        bool ok = false;

        rep (i, input.size()) {
            if (input[i] == '.') {
                ok = true;
                break;
            }
        }

        return ok ? is_legal_fraction_number(input, false) : false;
    } else {
        before = input.substr(0, pos);
        after = input.substr(pos+1);

        if (before.empty() || after.empty())
            return false;

        return is_legal_fraction_number(before, false) && is_legal_fraction_number(after, true);
    }

    return true;
}

int main(void) {
    string input, line;

    while (getline(cin, line)) {
        if (line[0] == '*')
            break;

        input = strip_input(line);
        cout << input << (is_legal(input) ? " is legal." : " is illegal.") << endl;
    }

    return 0;
}
