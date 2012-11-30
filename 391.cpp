#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int find_number(string &input, int index) {
    int result = 0;
    bool dot_found = false;

    REP (i, index, input.size()) {
        if (input[i] >= '0' && input[i] <= '9') {
            result++;
            continue;
        } else if (input[i] == '.' && !dot_found) {
            dot_found = true;
            result++;
            continue;
        } else
            break;
    }

    return result;
}

int main(void) {
    int shift;
    bool process_marks = true;
    string input;

    while (getline(cin, input)) {
        rep (i, input.size()) {
            if (input[i] == '\\' && i + 1 < input.size()) {
                i++;

                switch (input[i]) {
                    case 'b':
                        if (!process_marks)
                            cout << "\\b";
                        break;
                    case 'i':
                        if (!process_marks)
                            cout << "\\i";
                        break;
                    case 's':
                        if (!process_marks)
                            cout << "\\s";
                        else {
                            shift = find_number(input, i+1);
                            i += shift;
                        }
                        break;
                    case '*':
                        if (process_marks)
                            process_marks = false;
                        else
                            process_marks = true;
                        break;
                    default:
                        if (process_marks)
                            cout << input[i];
                        else {
                            cout << "\\";
                            i--;
                        }
                        break;
                }
            } else {
                cout << input[i];
            }
        }

        cout << endl;
    }

    return 0;
}
