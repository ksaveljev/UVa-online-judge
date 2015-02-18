#include <iostream>
#include <string>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

string input;
int idx;

bool eval(int values) {
    char c = input[idx];
    idx++;

    if (c >= 'p' && c <= 't') {
        int v = c - 'p';
        if ((bit(v) & values) > 0)
            return true;
        else
            return false;
    }

    if (c == 'N') {
        return !eval(values);
    }

    bool a = eval(values);
    bool b = eval(values);

    switch (c) {
        case 'K': return a && b;
        case 'A': return a || b;
        case 'C': return !(a && !b);
        case 'E': return a == b;
    }

    return false; // should never reach it
}

bool is_tautology() {
    rep (i, pow2(5)) {
        idx = 0;
        if (!eval(i))
            return false;
    }

    return true;
}

int main(void) {

    while (getline (cin, input)) {
        if (input == "0") break;

        if (is_tautology()) 
            cout << "tautology" << endl;
        else
            cout << "not" << endl;
    }

    return 0;
}
