#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

long long count_else();

long long count_if() {
    string input;
    int result = 1, count;

    while (getline(cin, input)) {
        if (input == "ELSE")
            break;

        if (input == "IF") {
            count = count_if();
            count += count_else();
            result *= count;
        }
    }

    return result;
}

long long count_else() {
    string input;
    int result = 1, count;

    while (getline(cin, input)) {
        if (input == "END_IF")
            break;

        if (input == "IF") {
            count = count_if();
            count += count_else();
            result *= count;
        }
    }

    return result;
}

long long solve() {
    string input;
    int result = 1, count;

    while (getline(cin, input)) {
        if (input == "ENDPROGRAM")
            break;

        if (input == "IF") {
            count = count_if();
            count += count_else();
            result *= count;
        }
    }

    return result;
}

int main(void) {
    int n;

    cin >> n;
    cin.ignore(100, '\n');
    
    while (n--) {
        cout << solve() << endl;
    }

    return 0;
}
