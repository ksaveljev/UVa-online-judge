#include <iostream>
#include <string>
#include <cctype>
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

int storage;
char previousOperand;
bool valueInStack;

void processInput(char input) {
    if (input == '@') {
        if (previousOperand) {
            if (valueInStack) {
                cout << "ST $" << storage++ << endl;
            }
            cout << "L " << previousOperand << endl;
            previousOperand = 0;
            valueInStack = true;
        }
        cout << "N" << endl;
    } else if (input == '+') {
        if (previousOperand) {
            cout << "A " << previousOperand << endl;
            previousOperand = 0;
        } else {
            cout << "A $" << --storage << endl;
        }
    } else if (input == '-') {
        if (previousOperand) {
            cout << "S " << previousOperand << endl;
            previousOperand = 0;
        } else {
            cout << "N" << endl << "A $" << --storage << endl;
        }
    } else if (input == '*') {
        if (previousOperand) {
            cout << "M " << previousOperand << endl;
            previousOperand = 0;
        } else {
            cout << "M $" << --storage << endl;
        }
    } else if (input == '/') {
        if (previousOperand) {
            cout << "D " << previousOperand << endl;
            previousOperand = 0;
        } else {
            cout << "ST $" << storage++ << endl;
            cout << "L $" << storage - 2 << endl;
            cout << "D $" << --storage << endl;
            storage--;
        }
    } else {
        if (previousOperand) {
            if (valueInStack) {
                cout << "ST $" << storage++ << endl;
            }
            cout << "L " << previousOperand << endl;
            valueInStack = true;
        }
        previousOperand = input;
    }
}

int main(void) {
    bool first = true;
    string input;

    while (cin >> input) {
        if (first)
            first = false;
        else
            cout << endl;

        storage = 0;
        previousOperand = 0;
        valueInStack = false;

        rep (i, input.size()) {
            processInput(input[i]);
        }
        processInput(0);
    }

    return 0;
}
