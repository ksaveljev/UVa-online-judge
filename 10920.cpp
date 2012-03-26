#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

enum direction {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
};

pair<int,int> compute_position(int sz, long long p) {
    int x, y;
    direction dir;

    // starting position where 1 is
    x = y = sz / 2 + 1;
    // starting direction is top
    dir = TOP;
    
    if (p == 1) {
        return make_pair(x, y);
    }

    int increment = 1;
    int count = 2;
    long long current = 1;

    while (true) {
        if (current + increment >= p) {
            increment = p - current;
        }

        count--;
        current += increment;

        switch (dir) {
            case TOP:
                x += increment;
                dir = LEFT;
                break;
            case BOTTOM:
                x -= increment;
                dir = RIGHT;
                break;
            case LEFT:
                y -= increment;
                dir = BOTTOM;
                break;
            case RIGHT:
                y += increment;
                dir = TOP;
                break;
        }

        if (count == 0) {
            increment++;
            count = 2;
        }

        if (current == p)
            break;
    }

    return make_pair(x, y);
}

int main(void) {
    int sz;
    long long p;

    while (cin >> sz >> p) {
        if (sz == 0 && p == 0)
            break;

        pair<int,int> result = compute_position(sz, p);

        cout << "Line = " << result.first << ", column = " << result.second << "." << endl;
    }

    return 0;
}
