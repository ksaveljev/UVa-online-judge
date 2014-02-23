#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
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

char grid[66][66];

int sardines;
int mackerels;
int salmons;
int groupers;
int turtles;
int dolphins;
int whales;
int sharks;

void clear_fish(int row, int col) {
    char c = grid[row][col];
    pair<int, int> pos;
    queue< pair<int, int> > q;

    q.push(make_pair(row, col));
    grid[row][col] = '.';

    while (!q.empty()) {
        pos = q.front();
        q.pop();

        if (grid[pos.first-1][pos.second] == c) {
            grid[pos.first-1][pos.second] = '.';
            q.push(make_pair(pos.first-1, pos.second));
        }

        if (grid[pos.first+1][pos.second] == c) {
            grid[pos.first+1][pos.second] = '.';
            q.push(make_pair(pos.first+1, pos.second));
        }

        if (grid[pos.first][pos.second-1] == c) {
            grid[pos.first][pos.second-1] = '.';
            q.push(make_pair(pos.first, pos.second-1));
        }

        if (grid[pos.first][pos.second+1] == c) {
            grid[pos.first][pos.second+1] = '.';
            q.push(make_pair(pos.first, pos.second+1));
        }
    }
}

void add_fish(int row, int col) {
    int end_col = col, end_row = row;

    while (grid[row][end_col+1] == grid[row][col]) end_col++;
    while (grid[end_row+1][col] == grid[row][col]) end_row++;

    bool is_shark = false;

    REPI (i, row, end_row) {
        if (grid[i][col-1] == grid[row][col]) is_shark = true;
        if (grid[i][end_col+1] == grid[row][col]) is_shark = true;
    }

    REPI (i, col, end_col) {
        if (grid[row-1][i] == grid[row][col]) is_shark = true;
        if (grid[end_row+1][i] == grid[row][col]) is_shark = true;
    }

    int w = end_col - col + 1;
    int h = end_row - row + 1;

    if (w > h) swap(w, h);

    if (is_shark) {
        sharks++;
    } else if (w == 1 && h == 1) {
        sardines++;
    } else if (w == 1 && h == 2) {
        mackerels++;
    } else if (w == 1) {
        salmons++;
    } else if (w == h) {
        turtles++;
    } else if (w == 2 && h > 2) {
        groupers++;
    } else if (w == 3 && h > 3) {
        dolphins++;
    } else if (w == 4 && h > 4) {
        whales++;
    }

    clear_fish(row, col);
}

int main(void) {
    int cases, rows, cols;
    string input;

    cin >> cases;

    while (cases--) {
        rep (i, 66) rep (j, 66) grid[i][j] = '.';
        sardines = mackerels = salmons = groupers = turtles = dolphins = whales = sharks = 0;

        cin >> rows >> cols;
        cin.ignore(100, '\n');

        rep (i, rows) {
            getline(cin, input);
            rep (j, input.size()) {
                grid[i+1][j+1] = input[j];
            }
        }

        rep (i, 66) rep (j, 66) if (grid[i][j] >= 'a' && grid[i][j] <= 'z') add_fish(i, j);

        cout << sardines << " " << mackerels << " " << salmons << " " << groupers << " " << turtles << " " << dolphins << " " << whales << " " << sharks << endl;

        if (cases) cout << endl;
    }

    return 0;
}
