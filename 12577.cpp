#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    string input;
    int case_number = 0;

    while (getline(cin, input)) {
        if (input == "*")
            break;

        case_number++;

        if (input == "Hajj") {
            cout << "Case " << case_number << ": Hajj-e-Akbar" << endl;
        } else {
            cout << "Case " << case_number << ": Hajj-e-Asghar" << endl;
        }
    }

    return 0;
}
