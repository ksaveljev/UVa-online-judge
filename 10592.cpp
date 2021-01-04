#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

int n;
char field[51][51];
bool visited[51][51];

int dir[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

bool is_sector(int row, int col) {
    return field[row][col] == '*' || field[row][col] == 'P' || field[row][col] == 'B';
}

bool is_valid(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

bool handle_group(char group, char other_group, int row, int col) {
    bool fighting = false;
    queue<pair<int,int>> q;
    q.push({row, col});
    field[row][col] = '*';

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];
            if (is_valid(r, c) && field[r][c] == other_group) {
                fighting = true;
            } else if (is_valid(r, c) && field[r][c] == group) {
                field[r][c] = '*';
                q.push({r, c});
            }
        }
    }

    return fighting;
}

tuple<int,int,int> handle_sector(int row, int col) {
    pair<int,int> result;
    int B = 0;
    int P = 0;
    int F = 0;

    if (field[row][col] == 'B') {
        bool fighting = handle_group('B', 'P', row, col);
        if (fighting) F += 2;
        B++;
    } else if (field[row][col] == 'P') {
        bool fighting = handle_group('P', 'B', row, col);
        if (fighting) F += 2;
        P++;
    }

    queue<pair<int,int>> q;
    q.push({row, col});
    visited[row][col] = true;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];
            if (is_valid(r, c) && !visited[r][c] && is_sector(r, c)) {
                if (field[r][c] == 'B') {
                    bool fighting = handle_group('B', 'P', r, c);
                    if (fighting) F += 2;
                    B++;
                } else if (field[r][c] == 'P') {
                    bool fighting = handle_group('P', 'B', r, c);
                    if (fighting) F += 2;
                    P++;
                }
                visited[r][c] = true;
                q.push({r, c});
            }
        }
    }

    return {B, P, F};
}

int main(void) {
    while (cin >> n) {
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> field[i][j];
                visited[i][j] = false;
            }
        }

        vector<tuple<int,int,int>> sectors;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && is_sector(i, j)) {
                    auto sector = handle_sector(i, j);
                    sectors.push_back(sector);
                }
            }
        }

        int F = 0;
        for (int i = 1; i <= sectors.size(); i++) {
            cout << "Sector #" << i << ": contain " << get<0>(sectors[i-1]) << " freedom fighter group(s) & " << get<1>(sectors[i-1]) << " enemy group(s)" << endl;
            F += get<2>(sectors[i-1]);
        }
        cout << "Total " << F << " group(s) are in fighting position." << endl;
        cout << endl;
    }

    return 0;
}
