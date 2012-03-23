#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

char field[50][50];
char piece[50][50];

bool is_empty_piece(int n, int m) {
    int count = 0;

    rep (i, n) {
        rep (j, m) {
            if (piece[i][j] == '*')
                count++;
        }
    }

    return count == 0;
}

bool is_empty_row(int row, int n, int m) {
    rep (i, m) {
        if (piece[row][i] == '*')
            return false;
    }

    return true;
}

bool is_empty_column(int column, int n, int m) {
    rep (i, n) {
        if (piece[i][column] == '*')
            return false;
    }

    return true;
}

void skip_rows(int skip_count, int n, int m) {
    REP (i, skip_count, n) {
        rep (j, m) {
            piece[i-skip_count][j] = piece[i][j];
        }
    }
}

void skip_columns(int skip_count, int n, int m) {
    REP (i, skip_count, m) {
        rep (j, n) {
            piece[j][i-skip_count] = piece[j][i];
        }
    }
}

void adjust_piece(int &n, int &m) {
    int skip_count = 0;

    rep (i, n) {
        if (is_empty_row(i, n, m)) {
            skip_count++;
        } else {
            break;
        }
    }

    skip_rows(skip_count, n, m);
    n -= skip_count;
    
    skip_count = 0;

    rep (i, m) {
        if (is_empty_column(i, n, m)) {
            skip_count++;
        } else {
            break;
        }
    }

    skip_columns(skip_count, n, m);
    m -= skip_count;

    skip_count = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (is_empty_row(i, n, m)) {
            skip_count++;
        } else {
            break;
        }
    }

    n -= skip_count;

    skip_count = 0;

    for (int i = m - 1; i >= 0; i--) {
        if (is_empty_column(i, n, m)) {
            skip_count++;
        } else {
            break;
        }
    }

    m -= skip_count;
}

bool try_to_fit(int row, int col, int n, int m, int N, int M) {
    for (int i = 0; i < n; i++) {
        if (row + i >= N)
            return false;

        for (int j = 0; j < m; j++) {
            if (col + j >= M)
                return false;

            if (piece[i][j] == '*' && field[row+i][col+j] != '*')
                return false;
        }
    }

    return true;
}

int main(void) {
    int t, N, M, s, n, m;
    string input;

    cin >> t;

    while (t--) {
        cin >> N >> M >> s;

        cin.ignore(100, '\n');

        rep (i, N) {
            getline(cin, input);

            rep (j, M) {
                field[i][j] = input[j];
            }
        }


        while (s--) {
            cin >> n >> m;

            cin.ignore(100, '\n');

            rep (i, n) {
                getline(cin, input);

                rep (j, m) {
                    piece[i][j] = input[j];
                }
            }

            if (is_empty_piece(n, m)) {
                cout << "Yes" << endl;
                continue;
            }

            adjust_piece(n, m);

            bool result = false;

            rep (i, N) {
                rep (j, M) {
                    if (try_to_fit(i, j, n, m, N, M)) {
                        result = true;
                    }
                }
            }

            if (result)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }

        cout << endl;
    }

    return 0;
}
