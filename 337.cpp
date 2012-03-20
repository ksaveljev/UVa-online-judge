#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum mode {
    OVERWRITE,
    INSERT
};

void clear_terminal(char terminal[10][10]) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            terminal[i][j] = ' ';
}

void write_character(char terminal[10][10], char c, int row, int col, mode m) {
    if (m == INSERT) {
        for (int i = 8; i >= col; i--) {
            terminal[row][i+1] = terminal[row][i];
        }

        terminal[row][col] = c;
    } else { // OVERWRITE
        terminal[row][col] = c;
    }
}

int main(void) {
    int n, row, col, case_num = 0;
    mode m;
    string input;
    char terminal[10][10];

    while (cin >> n) {
        if (n == 0)
            break;

        case_num++;
        row = 0;
        col = 0;
        m = OVERWRITE;
        clear_terminal(terminal);

        cin.ignore(100, '\n');

        while (n--) {
            getline(cin, input);

            for (int i = 0, sz = input.size(); i < sz; i++) {
                if (input[i] == '^') {
                    i++;

                    switch (input[i]) {
                        case 'b':
                            col = 0;
                            break;
                        case 'c':
                            clear_terminal(terminal);
                            break;
                        case 'd':
                            row = min(row + 1, 9);
                            break;
                        case 'e':
                            for (int j = col; j < 10; j++)
                                terminal[row][j] = ' ';
                            break;
                        case 'h':
                            row = col = 0;
                            break;
                        case 'i':
                            m = INSERT;
                            break;
                        case 'l':
                            col = max(0, col - 1);
                            break;
                        case 'o':
                            m = OVERWRITE;
                            break;
                        case 'r':
                            col = min(col + 1, 9);
                            break;
                        case 'u':
                            row = max(0, row - 1);
                            break;
                        case '^':
                            write_character(terminal, '^', row, col, m);
                            col = min(col + 1, 9);
                            break;
                        default:
                            row = input[i] - '0';
                            i++;
                            col = input[i] - '0';
                            break;
                    }
                } else {
                    write_character(terminal, input[i], row, col, m);
                    col = min(col + 1, 9);
                }
            }
        }

        cout << "Case " << case_num << endl;
        cout << "+----------+" << endl;
        for (int i = 0; i < 10; i++) {
            cout << "|";
            for (int j = 0; j < 10; j++) {
                cout << terminal[i][j];
            }
            cout << "|" << endl;
        }
        cout << "+----------+" << endl;
    }

    return 0;
}
