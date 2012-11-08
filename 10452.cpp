#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int numberOfCases, rows, cols;
    char room[8][8];
    string input;

    cin >> numberOfCases;

    while (numberOfCases--) {
        cin >> rows >> cols;
        cin.ignore(100, '\n');

        pair<int,int> start;

        rep (i, rows) {
            getline(cin, input);
            rep (j, cols) {
                room[i][j] = input[j];

                if (input[j] == '@')
                    start = make_pair(i, j);
            }
        }

        string solution = "IEHOVA#";
        pair<int,int> currentPosition = start;

        rep (i, solution.size()) {
            if (currentPosition.first > 0) {
                if (room[currentPosition.first - 1][currentPosition.second] == solution[i]) {
                    if (i > 0)
                        cout << " ";

                    currentPosition.first -= 1;
                    cout << "forth";

                    continue;
                }
            }

            if (currentPosition.second > 0) {
                if (room[currentPosition.first][currentPosition.second - 1] == solution[i]) {
                    if (i > 0)
                        cout << " ";

                    currentPosition.second -= 1;
                    cout << "left";

                    continue;
                }
            }

            if (currentPosition.second + 1 < cols) {
                if (room[currentPosition.first][currentPosition.second + 1] == solution[i]) {
                    if (i > 0)
                        cout << " ";

                    currentPosition.second += 1;
                    cout << "right";

                    continue;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
