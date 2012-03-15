#include <iostream>
#include <vector>
using namespace std;

typedef struct _piece piece;

bool field[100][100];
bool tmp_field[100][100];
int colors[100][100];

struct _piece {
    bool p[100][100];
    bool taken;
    int w, h;

    _piece() : taken(false) {
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                p[i][j] = false;
    }

    void initialize(int minx, int miny, int maxx, int maxy, int color) {
        w = maxx - minx + 1;
        h = maxy - miny + 1;

        for (int i = minx; i <= maxx; i++) {
            for (int j = miny; j <= maxy; j++) {
                if (!field[i][j] || colors[i][j] != color)
                    continue;

                p[i - minx][j - miny] = true;
            }
        }
    }

    bool is_same(piece &other) {
        if (w != other.w || h != other.h)
            return false;

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (p[i][j] != other.p[i][j])
                    return false;
            }
        }

        return true;
    }

    void rotate() {
        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
                tmp_field[i][j] = p[i][j];

        swap(w, h);

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                p[i][j] = tmp_field[j][w-1-i];
            }
        }
    }

    void reverse() {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h/2; j++) {
                swap(p[i][j], p[i][h-1-j]);
            }
        }
    }

    void output() {
        cout << "DEBUG" << endl;
        cout << "W: " << w << " H: " << h << endl;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++)
                cout << p[i][j];
            cout << endl;
        }
        cout << "DEBUGEND" << endl;
    }
};

void clear_field() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            field[i][j] = false;
            colors[i][j] = -1;
        }
    }
}

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void fill(int w, int h, int W, int H, int color, int &minx, int &miny, int &maxx, int &maxy) {
    colors[w][h] = color;

    minx = min(w, minx);
    miny = min(h, miny);
    maxx = max(w, maxx);
    maxy = max(h, maxy);

    for (int i = 0; i < 4; i++) {
        int nextx = w + dx[i], nexty = h + dy[i];

        if (nextx == -1 || nextx == W || nexty == -1 || nexty == H || !field[nextx][nexty] || colors[nextx][nexty] != -1)
            continue;

        fill(nextx, nexty, W, H, color, minx, miny, maxx, maxy);
    }
}

bool are_similar(piece &a, piece &b) {
    bool result = false;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            b.rotate();

            if (a.is_same(b))
                result = true;
        }

        b.reverse();
    }

    return result;
}

bool same_board(vector<piece> &a, vector<piece> &b) {
    if (a.size() != b.size())
        return false;

    for (int i = 0, sz = a.size(); i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (b[j].taken)
                continue;

            if (are_similar(a[i], b[j])) {
                a[i].taken = true;
                b[j].taken = true;
                break;
            }
        }

        if (!a[i].taken)
            return false;
    }

    return true;
}

int main(void) {
    int number_of_test_cases, W, H, n, x, y;

    cin >> number_of_test_cases;

    while (number_of_test_cases--) {
        cin >> W >> H >> n;

        vector<piece> pieces[2];

        for (int i = 0; i < 2; i++) {
            clear_field();

            for (int j = 0; j < n; j++) {
                cin >> x >> y;
                field[x][y] = true;
            }

            int color = 0;
            for (int w = 0; w < W; w++) {
                for (int h = 0; h < H; h++) {
                    if (!field[w][h] || colors[w][h] != -1)
                        continue;

                    int minx = w, miny = h, maxx = w, maxy = h;
                    fill(w, h, W, H, color, minx, miny, maxx, maxy);
                    piece tmp;
                    tmp.initialize(minx, miny, maxx, maxy, color);
                    pieces[i].push_back(tmp);
                    color++;
                }
            }
        }

        if (same_board(pieces[0], pieces[1]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
