#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <numeric>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case " << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

char field[51][51];
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool check(string& s, int row, int col) {
    int d = 0;
    int r = 0, c = 0;

    for (int i = 0; i < s.size(); i++) {
        field[r][c] = s[i];

        int nr = r + dir[d][0];
        int nc = c + dir[d][1];

        if (nr >= 0 && nr < row &&  nc >= 0 && nc < col && field[nr][nc] == ' ') {
            r += dir[d][0];
            c += dir[d][1];
        } else {
            d = (d + 1) % 4;
            r += dir[d][0];
            c += dir[d][1];
        }
    }

    for (int i = 0; i < col; i++) {
        for (int r = 1; r < row; r++) {
            if (field[r][i] != field[0][i]) {
                return false;
            }
        }
    }

    return true;
}

int main(void) {
    int t;
    string input;

    cin >> t;

    rep(T, 0, t) {
        goog(T+1);
        cin >> input;
        int len = input.size();

        int result = -1;
        for (int n = 2; n <= len/2; n++) {
            if (len % n != 0) continue;

            for (int i = 0; i < 51; i++) {
                for (int j = 0; j < 51; j++) {
                    field[i][j] = ' ';
                }
            }

            if (check(input, n, len / n)) {
                if (result == -1) {
                    result = n + len / n;
                } else {
                    result = min(result, n + len / n);
                }
            }
        }

        cout << result << endl;
    }
    return 0;
}
