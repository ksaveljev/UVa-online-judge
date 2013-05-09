#include <iostream>
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

bool city[20][20];
int neighbors[20][20];

void print_separator() {
    cout << "********************" << endl;
}

void print_city() {
    print_separator();

    rep (i, 20) {
        rep (j, 20) {
            if (city[i][j]) {
                cout << "O";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void simulate() {
    int counter;

    rep (i, 20) {
        rep (j, 20) {
            counter = 0;

            // top left
            if (i-1 >= 0 && j-1 >= 0 && city[i-1][j-1]) counter++;
            // top
            if (i-1 >= 0 && city[i-1][j]) counter++;
            // top right
            if (i-1 >= 0 && j+1 < 20 && city[i-1][j+1]) counter++;
            // left
            if (j-1 >= 0 && city[i][j-1]) counter++;
            // right
            if (j+1 < 20 && city[i][j+1]) counter++;
            // bottom left
            if (i+1 < 20 && j-1 >= 0 && city[i+1][j-1]) counter++;
            // bottom
            if (i+1 < 20 && city[i+1][j]) counter++;
            // bottom right
            if (i+1 < 20 && j+1 < 20 && city[i+1][j+1]) counter++;

            neighbors[i][j] = counter;
        }
    }

    rep (i, 20) {
        rep (j, 20) {
            if (city[i][j] && (neighbors[i][j] == 2 || neighbors[i][j] == 3)) {
                city[i][j] = true;
            } else if (city[i][j] && (neighbors[i][j] > 3 || neighbors[i][j] < 2)) {
                city[i][j] = false;
            } else if (!city[i][j] && neighbors[i][j] == 3) {
                city[i][j] = true;
            } else {
                city[i][j] = false;
            }
        }
    }
}

int main(void) {
    int t, years, row, col;

    cin >> t;

    while (t--) {
        cin >> years;
        cin.ignore(100, '\n');

        rep (i, 20) {
            rep (j, 20) {
                city[i][j] = false;
            }
        }

        while (cin.peek() != '\n' && cin.peek() != -1) {
            cin >> row >> col;
            cin.ignore(100, '\n');

            row--, col--;
            city[row][col] = true;
        }

        int current_year = 1;

        do {
            print_city();

            simulate();

            current_year++;
        } while (current_year <= years);

        print_separator();

        if (t > 0)
            cout << endl;
    }


    return 0;
}
