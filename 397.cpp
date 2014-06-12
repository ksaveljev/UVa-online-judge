#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
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

int next_multiplication_or_division(const vector<string> &components) {
    rep (i, components.size()) {
        if (components[i] == "*" || components[i] == "/")
            return i;
    }

    return -1;
}

int next_addition_or_subtraction(const vector<string> &components) {
    rep (i, components.size()) {
        if (components[i] == "+" || components[i] == "-")
            return i;
    }

    return -1;
}

long long string_to_int(const string &value) {
    stringstream ss(value);
    long long v;
    ss >> v;
    return v;
}

string int_to_string(long long value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

void solve_equation(vector<string> &components) {
    int pos;

    while (true) {
        rep (i, components.size()) {
            if (i > 0) cout << " ";
            cout << components[i];
        }
        cout << endl;

        if (components.size() == 3) break;

        pos = next_multiplication_or_division(components);
        
        if (pos == -1) {
            pos = next_addition_or_subtraction(components);
        }

        if (pos != -1) {
            long long left = string_to_int(components[pos-1]);
            long long right = string_to_int(components[pos+1]);
            long long result;
            if (components[pos] == "*") {
                result = left * right;
            } else if (components[pos] == "/") {
                result = left / right;
            } else if (components[pos] == "+") {
                result = left + right;
            } else if (components[pos] == "-") {
                result = left - right;
            }
            string tmp = int_to_string(result);

            components.erase(components.begin() + pos - 1);
            components.erase(components.begin() + pos - 1);
            components.erase(components.begin() + pos - 1);

            components.insert(components.begin() + pos - 1, tmp);
        }
    }
}

int main(void) {
    string input;
    bool first = true;

    while (getline (cin, input)) {
        if (!first) cout << endl; else first = false;

        input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

        vector<string> components;

        int index = 0;
        string tmp;

        while (true) {
            // read integer operand
            tmp = "";

            bool negative = false;

            if (input[index] == '+' || input[index] == '-') {
                if (input[index] == '-') tmp += input[index];
                index++;
            }

            while (input[index] >= '0' && input[index] <= '9') {
                tmp += input[index];
                index++;
            }

            components.push_back(tmp);
            
            if (input[index] == '=') {
                tmp = "=";
                components.push_back(tmp);
                input.erase(input.begin(), input.begin() + index + 1);
                components.push_back(input);
                break;
            } else { // it is an operator: * / - +
                tmp = "";
                tmp += input[index];
                index++;
                components.push_back(tmp);
            }
        }

        solve_equation(components);
    }

    return 0;
}
