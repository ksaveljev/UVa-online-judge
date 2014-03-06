#include <iostream>
#include <queue>
#include <string>
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

int H, W;
char field[202][202];
bool taken[202][202];
char hex_chars[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
string convert[16] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
char decode[6] = {'W','A','K','J','S','D'};

void fill(int x, int y, char replace) {
    char c = field[x][y];
    pair<int,int> tmp = make_pair(x, y);
    queue< pair<int,int> > q;

    rep (i, 202) rep (j, 202) taken[i][j] = false;

    q.push(tmp);
    taken[x][y] = true;
    field[x][y] = replace;

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        if (tmp.first - 1 >= 0 && !taken[tmp.first-1][tmp.second] && field[tmp.first-1][tmp.second] == c) {
            taken[tmp.first-1][tmp.second] = true;
            field[tmp.first-1][tmp.second] = replace;
            q.push(make_pair(tmp.first-1, tmp.second));
        }

        if (tmp.first + 1 < H && !taken[tmp.first+1][tmp.second] && field[tmp.first+1][tmp.second] == c) {
            taken[tmp.first+1][tmp.second] = true;
            field[tmp.first+1][tmp.second] = replace;
            q.push(make_pair(tmp.first+1, tmp.second));
        }

        if (tmp.second - 1 >= 0 && !taken[tmp.first][tmp.second-1] && field[tmp.first][tmp.second-1] == c) {
            taken[tmp.first][tmp.second-1] = true;
            field[tmp.first][tmp.second-1] = replace;
            q.push(make_pair(tmp.first, tmp.second-1));
        }

        if (tmp.second + 1 < 4 * W && !taken[tmp.first][tmp.second+1] && field[tmp.first][tmp.second+1] == c) {
            taken[tmp.first][tmp.second+1] = true;
            field[tmp.first][tmp.second+1] = replace;
            q.push(make_pair(tmp.first, tmp.second+1));
        }
    }
}

void fill_background() {
    rep (i, H) {
        rep (j, 4 * W) {
            if (i == 0 || i == H - 1 || j == 0 || j == 4 * W - 1) {
                if (field[i][j] == '0')
                    fill (i, j, '.');
            }
        }
    }
}

pair<int,int> find_next_hieroglyph() {
    pair<int,int> result = make_pair(-1, -1);

    rep (i, H) {
        rep (j, 4 * W) {
            if (field[i][j] == '1') {
                result = make_pair(i, j);
                i = j = 100000;
            }
        }
    }

    return result;
}

int main(void) {
    int index;
    char c;
    int case_number = 0;

    while (cin >> H >> W) {
        if (H == 0 && W == 0) break;

        case_number++;

        rep (i, 202) rep (j, 202) field[i][j] = '0';

        rep (i, H) {
            index = 0;

            rep (j, W) {
                cin >> c;

                rep (k, 16) {
                    if (hex_chars[k] == c) {
                        rep (n, 4) {
                            field[i][index++] = convert[k][n];
                        }
                    }
                }
            }
        }

        fill_background();

        string result = "";
        pair<int,int> hieroglyph_location;

        while (true) {
            hieroglyph_location = find_next_hieroglyph();

            if (hieroglyph_location.first == -1) break;

            fill(hieroglyph_location.first, hieroglyph_location.second, '.');

            int counter = 0;

            rep (i, H) {
                rep (j, 4 * W) {
                    if (field[i][j] != '0') continue;

                    if (i - 1 >= 0 && field[i-1][j] == '.') {
                        counter++;
                        fill(i, j, '.');
                    } else if (i + 1 < H && field[i+1][j] == '.') {
                        counter++;
                        fill(i, j, '.');
                    } else if (j - 1 >= 0 && field[i][j-1] == '.') {
                        counter++;
                        fill(i, j, '.');
                    } else if (j + 1 < 4 * W && field[i][j+1] == '.') {
                        counter++;
                        fill(i, j, '.');
                    }
                }
            }

            result += decode[counter];
        }

        sort (result.begin(), result.end());

        cout << "Case " << case_number << ": " << result << endl;
    }

    return 0;
}
