#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[101][101], tmp[101][101];

void apply_transformation(int ring) {
    for (int i = ring; i <= n - ring - 1; i++) {
        for (int j = ring; j <= n - ring - 1; j++) {
            if (i == ring || i == n - ring - 1 || j == ring || j == n - ring - 1)
                board[i][j] = tmp[i][j];
        }
    }
}

void upside_down_flip(int ring) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            tmp[n-i-1][j] = board[i][j];
        }
    }

    apply_transformation(ring);
}

void left_right_flip(int ring) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            tmp[i][n-j-1] = board[i][j];
        }
    }

    apply_transformation(ring);
}

void flip_through_main_diagonal(int ring) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            swap(tmp[i][j], tmp[j][i]);
        }
    }

    apply_transformation(ring);
}

void flip_through_main_inverse_diagonal(int ring) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            swap(tmp[i][j], tmp[n - j - 1][n - i - 1]);
        }
    }

    apply_transformation(ring);
}

void print_board() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0)
                cout << " ";
            cout << board[i][j];
        }
        cout << endl;
    }
}

int main(void) {
    int cases, t, c;

    cin >> cases;

    while (cases--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        int rings = (n % 2 == 0) ? n / 2 : n / 2 + 1;

        for (int ring = 0; ring < rings; ring++) {
            cin >> t;

            while (t--) {
                cin >> c;

                switch (c) {
                    case 1:
                        upside_down_flip(ring);
                        break;
                    case 2:
                        left_right_flip(ring);
                        break;
                    case 3:
                        flip_through_main_diagonal(ring);
                        break;
                    case 4:
                        flip_through_main_inverse_diagonal(ring);
                        break;
                }
            }
        }

        print_board();
    }

    return 0;
}
