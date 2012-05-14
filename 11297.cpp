#include <iostream>
#include <climits>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

/*
 * 2D Segment Tree implementation adapted
 * from http://e-maxx.ru/algo/segment_tree
 */

#define MAXN 505

int n, m;
pair<int,int> t[4*MAXN][4*MAXN];
int input[MAXN][MAXN];

void build_y (int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx) {
            t[vx][vy] = make_pair(input[lx][ly], input[lx][ly]);
        } else {
            t[vx][vy].first = min(t[vx*2][vy].first, t[vx*2+1][vy].first);
            t[vx][vy].second = max(t[vx*2][vy].second, t[vx*2+1][vy].second);
        }
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy * 2, ly, my);
        build_y(vx, lx, rx, vy * 2 + 1, my+1, ry);

        t[vx][vy].first = min(t[vx][vy*2].first, t[vx][vy*2+1].first);
        t[vx][vy].second = max(t[vx][vy*2].second, t[vx][vy*2+1].second);
    }
}

void build_x (int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x (vx * 2, lx, mx);
        build_x (vx * 2 + 1, mx + 1, rx);
    }

    build_y(vx, lx, rx, 1, 0, m-1);
}

pair<int,int> query_y (int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry)
        return make_pair(INT_MAX, INT_MIN);

    if (ly == tly && try_ == ry)
        return t[vx][vy];

    int tmy = (tly + try_) / 2;

    pair<int,int> a, b;

    a = query_y(vx, vy*2, tly, tmy, ly, min(ry, tmy));
    b = query_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);

    return make_pair(min(a.first, b.first), max(a.second, b.second));
}

pair<int,int> query_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return make_pair(INT_MAX, INT_MIN);

    if (lx == tlx && trx == rx)
        return query_y(vx, 1, 0, m-1, ly, ry);

    int tmx = (tlx + trx) / 2;

    pair<int,int> a, b;

    a = query_x(vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry);
    b = query_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);

    return make_pair(min(a.first, b.first), max(a.second, b.second));
}

void update_y (int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx) {
            t[vx][vy].first = new_val;
            t[vx][vy].second = new_val;
        } else {
            t[vx][vy].first = min(t[vx*2][vy].first, t[vx*2+1][vy].first);
            t[vx][vy].second = max(t[vx*2][vy].second, t[vx*2+1][vy].second);
        }
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);

        t[vx][vy].first = min(t[vx][vy*2].first, t[vx][vy*2+1].first);
        t[vx][vy].second = max(t[vx][vy*2].second, t[vx][vy*2+1].second);
    }
}

void update_x (int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;

        if (x <= mx)
            update_x(vx*2, lx, mx, x, y, new_val);
        else
            update_x(vx*2+1, mx+1, rx, x, y, new_val);
    }

    update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
}

int main(void) {
    int q, x1, y1, x2, y2, v;
    char command;
    pair<int,int> result;

    cin >> n >> m;

    rep (i, n)
        rep (j, m)
            cin >> input[i][j];

    build_x(1, 0, n-1);

    cin >> q;

    while (q--) {
        cin >> command;

        switch (command) {
            case 'q':
                cin >> x1 >> y1 >> x2 >> y2;
                --x1, --y1, --x2, --y2;
                result = query_x(1, 0, n-1, x1, x2, y1, y2);
                cout << result.second << " " << result.first << endl;
                break;
            case 'c':
                cin >> x1 >> y1 >> v;
                --x1, --y1;
                update_x(1, 0, n-1, x1, y1, v);
                break;
        }
    }

    return 0;
}
