#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

char grid[4][4];

int solve(int row, int col, string& input, int pos) {
    if (pos == input.size())
        return pos;

    int diff[9][2] = { {0,0}, {-1,0}, {0, -1}, {-1, -1}, {1, 0}, {0, 1}, {1, 1}, {-1, 1}, {1, -1} };

    rep (i, 9) {
        if (row+diff[i][0] >= 0 && row+diff[i][0] < 4 && col+diff[i][1] >= 0 && col+diff[i][1] < 4 && grid[row+diff[i][0]][col+diff[i][1]] == input[pos]) {
            grid[row+diff[i][0]][col+diff[i][1]] = '-';
            int result = solve(row+diff[i][0], col+diff[i][1], input, pos+1);
            grid[row+diff[i][0]][col+diff[i][1]] = input[pos];

            if (result > 0)
                return result;
        }
    }

    return 0;
}

int find_word(string& input) {
    int result = 0;

    rep (i, 4) {
        rep (j, 4) {
            if (grid[i][j] != input[0])
                continue;

            result = solve(i, j, input, 0);

            if (result > 0) {
                i = 5;
                break;
            }
        }
    }

    return result;
}

int main(void) {
    int n, gameNumber = 0, m;
    string input;

    cin >> n;
    cin.ignore(100, '\n');

    while (n--) {
        gameNumber++;
        getline(cin, input); // empty line before the grid

        rep (i, 4) {
            getline(cin, input);
            rep (j, input.size()) {
                grid[i][j] = input[j];
            }
        }

        cin >> m;
        cin.ignore(100, '\n');

        int result = 0;

        while (m--) {
            getline(cin, input);

            int found = find_word(input);

            if (found == 3 || found == 4) {
                result += 1;
            } else if (found == 5) {
                result += 2;
            } else if (found == 6) {
                result += 3;
            } else if (found == 7) {
                result += 5;
            } else if (found > 7) {
                result += 11;
            }
        }

        cout << "Score for Boggle game #" << gameNumber << ": " << result << endl;
    }

    return 0;
}
