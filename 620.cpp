#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

bool verify_correctness(string &input, int start, int end) {
    if (end - start == 1) {
        if (input[start] == 'A')
            return true;
        else
            return false;
    }

    if (input[end-1] == 'B' && input[end-2] == 'A') {
        return verify_correctness(input, start, end-2);
    } else if (input[start] == 'B' && input[end-1] == 'A') {
        return verify_correctness(input, start+1, end-1);
    } else {
        return false;
    }

    return false;
}

int main(void) {
    int n;
    string input;

    cin >> n;
    cin.ignore(100, '\n');

    while (n--) {
        getline(cin, input);

        if (input.size() % 2 == 0) {
            cout << "MUTANT" << endl;
            continue;
        }

        if (input.size() == 1) {
            if (input[0] == 'A')
                cout << "SIMPLE" << endl;
            else
                cout << "MUTANT" << endl;

            continue;
        }

        if (input[input.size()-1] == 'B' && input[input.size()-2] == 'A') {
            if (verify_correctness(input, 0, input.size() - 2))
                cout << "FULLY-GROWN" << endl;
            else
                cout << "MUTANT" << endl;
        } else if (input[0] == 'B' && input[input.size()-1] == 'A') {
            if (verify_correctness(input, 1, input.size() - 1))
                cout << "MUTAGENIC" << endl;
            else
                cout << "MUTANT" << endl;
        } else {
            cout << "MUTANT" << endl;
        }
    }

    return 0;
}
