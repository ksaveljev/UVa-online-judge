#include <iostream>
using namespace std;

// 2D segment tree
// http://e-maxx.ru/algo/segment_tree

#define MAXN 505

int n, q;
int maximum[4*MAXN][4*MAXN];
int minimum[4*MAXN][4*MAXN];
int input[MAXN][MAXN];

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx) {
            maximum[vx][vy] = input[lx][ly];
            minimum[vx][vy] = input[lx][ly];
        } else {
            maximum[vx][vy] = max(maximum[vx*2][vy], maximum[vx*2+1][vy]);
            minimum[vx][vy] = min(minimum[vx*2][vy], minimum[vx*2+1][vy]);
        }
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        maximum[vx][vy] = max(maximum[vx][vy*2], maximum[vx][vy*2+1]);
        minimum[vx][vy] = min(minimum[vx][vy*2], minimum[vx][vy*2+1]);
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx * 2, lx, mx);
        build_x(vx * 2 + 1, mx + 1, rx);
    }

    build_y(vx, lx, rx, 1, 0, n-1);
}

pair<int,int> query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry)
        return make_pair(-1, 1<<30);
    if (ly == tly && ry == try_)
        return make_pair(maximum[vx][vy], minimum[vx][vy]);
    int tmy = (tly + try_) / 2;
    pair<int,int> r1 = query_y(vx, vy*2, tly, tmy, ly, min(ry, tmy));
    pair<int,int> r2 = query_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
     
    return make_pair(max(r1.first, r2.first), min(r1.second, r2.second));
}

pair<int,int> query_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return make_pair(-1, 1<<30);
    if (lx == tlx && rx == trx)
        return query_y(vx, 1, 0, n-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    pair<int,int> r1 = query_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry);
    pair<int,int> r2 = query_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);

    return make_pair(max(r1.first, r2.first), min(r1.second, r2.second));
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx) {
            maximum[vx][vy] = new_val;
            minimum[vx][vy] = new_val;
        }
        else {
            maximum[vx][vy] = max(maximum[vx*2][vy], maximum[vx*2+1][vy]);
            minimum[vx][vy] = min(minimum[vx*2][vy], minimum[vx*2+1][vy]);
        }
         
    }
    else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
         
        maximum[vx][vy] = max(maximum[vx][vy *2], maximum[vx][vy *2 + 1]);
        minimum[vx][vy] = min(minimum[vx][vy *2], minimum[vx][vy *2 + 1]);
    }
}
 
void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx*2, lx, mx, x, y, new_val);
        else
            update_x(vx*2+1, mx+1, rx, x, y, new_val);
    }

    update_y(vx, lx, rx, 1, 0, n-1, x, y, new_val);
}

int main(void) {
    char cmd;
    int x1, y1, x2, y2;
    int x, y, v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }

    build_x(1, 0, n-1);

    cin >> q;

    while (q--) {
        cin >> cmd;

        if (cmd == 'c') {
            cin >> x >> y >> v;
            x--, y--;
            update_x(1, 0, n-1, x, y, v);
        } else if (cmd == 'q') {
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            pair<int,int> result = query_x(1, 0, n-1, x1, x2, y1, y2);
            cout << result.first << " " << result.second << endl;
        }
    }

    return 0;
}
