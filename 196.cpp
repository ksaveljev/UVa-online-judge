#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int W, H;
const int INF = 1<<31;
int dp[1001][18300];
vector< vector<string> > m;

pair<int,int> get_coords(string& str) {
    int row = 0, col = 0;

    rep (i, str.size()) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            col = col * 26 + (str[i] - 'A' + 1);
        } else {
            row = row * 10 + (str[i] - '0');
        }
    }

    return make_pair(row - 1, col - 1);
}

vector< pair<int,int> > parse_cells(string str) {
    string tmp;
    vector< pair<int,int> > result;

    rep (i, str.size()) {
        if (str[i] == '=' || str[i] == '+')
            str[i] = ' ';
    }

    stringstream ss(str);
    while (ss >> tmp) {
        result.push_back(get_coords(tmp));
    }

    return result;
}

int solve(int row, int col) {
    if (dp[row][col] == INF) {
        if (m[row][col][0] == '=') {
            vector< pair<int,int> > cells = parse_cells(m[row][col]);
            int sum = 0;
            rep (i, cells.size()) {
                sum += solve(cells[i].first, cells[i].second);
            }
            dp[row][col] = sum;
        } else {
            dp[row][col] = stoi(m[row][col]);
        }
    }

    return dp[row][col];
}

int main(void) {
    int cases;
    string input;

    cin >> cases;

    while (cases--) {
        m.clear();

        cin >> W >> H;

        rep (i, H) {
            vector<string> row;
            rep (j, W) {
                dp[i][j] = INF;
                cin >> input;
                row.push_back(input);
            }
            m.push_back(row);
        }

        rep (i, H) {
            rep (j, W) {
                if (j > 0) cout << " ";
                cout << solve(i, j);
            }
            cout << endl;
        }
    }

    return 0;
}
