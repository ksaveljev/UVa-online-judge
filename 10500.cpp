#include <iostream>
using namespace std;

void print_border(int m) {
    cout << "|";
    for (int i = 0; i < m; i++) {
        cout << "---|";
    }
    cout << endl;
}

void mark_visibility(bool visible[12][12], int x, int y) {
    visible[x][y] = true;
    visible[x-1][y] = true;
    visible[x][y-1] = true;
    visible[x+1][y] = true;
    visible[x][y+1] = true;
}

int main(void) {
    int n, m, x, y;
    char map[12][12];
    bool visited[12][12];
    bool visible[12][12];

    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;

        cout << endl;

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                map[i][j] = 'X';
                visited[i][j] = visible[i][j] = false;
            }
        }

        cin >> x >> y;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i + 1][j + 1];
            }
        }

        int moves = 0;

        while (true) {
            visited[x][y] = true;
            mark_visibility(visible, x, y);

            if (map[x-1][y] == '0' && !visited[x-1][y]) {
                x--;
            } else if (map[x][y+1] == '0' && !visited[x][y+1]) {
                y++;
            } else if (map[x+1][y] == '0' && !visited[x+1][y]) {
                x++;
            } else if (map[x][y-1] == '0' && !visited[x][y-1]) {
                y--;
            } else
                break;

            moves++;
        }

        print_border(m);

        for (int i = 0; i < n; i++) {
            cout << "|";
            for (int j = 0; j < m; j++) {
                cout << " ";
                if (!visible[i+1][j+1])
                    cout << "?";
                else
                    cout << map[i+1][j+1];
                cout << " |";

            }
            cout << endl;
            print_border(m);
        }

        cout << endl;
        cout << "NUMBER OF MOVEMENTS: " << moves << endl;
    }

    return 0;
}
