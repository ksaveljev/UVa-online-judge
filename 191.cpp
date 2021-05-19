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
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

struct P {
    ll x, y;

    void read() {
        cin >> x >> y;
    }

    P operator -(const P& other) const {
        return { x - other.x, y - other.y };
    }

    ll operator *(const P& other) const {
        return x * other.y - y * other.x;
    }

    ll triangle(const P& a, const P& b) const {
        return (a - *this) * (b - *this);
    }

    bool operator ==(const P& other) const {
        return x == other.x && y == other.y;
    }

    bool operator !=(const P& other) const {
        return !(*this == other);
    }
};

bool segment_contains(const P& a, const P& b, const P& c) {
    if (a.triangle(b, c) != 0) {
        return false;
    }

    if (c.x < min(a.x, b.x) || c.x > max(a.x, b.x) || c.y < min(a.y, b.y) || c.y > max(a.y, b.y)) {
        return false;
    }

    return true;
}

bool intersect(const P& a, const P& b, const P& c, const P& d) {
    if (a == b && c == d) {
        if (a != c) {
            return false;
        }
    } else if (a == b) {
        if (!segment_contains(c, d, a)) {
            return false;
        }
    } else if (c == d) {
        if (!segment_contains(a, b, c)) {
            return false;
        }
    } else if ((b - a) * (d - c) == 0) {
        if (max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y)) {
            return false;
        }

        if (min(a.x, b.x) > max(c.x, d.x) || min(a.y, b.y) > max(c.y, d.y)) {
            return false;
        }
    } else {
        ll s1 = a.triangle(c, b);
        ll s2 = a.triangle(d, b);

        if ((s1 < 0 && s2 < 0) || (s1 > 0 && s2 > 0)) {
            return false;
        }

        ll s3 = c.triangle(a, d);
        ll s4 = c.triangle(b, d);

        if ((s3 < 0 && s4 < 0) || (s3 > 0 && s4 > 0)) {
            return false;
        }
    }

    return true;
}

bool inside(int xleft, int xright, int ytop, int ybottom, const P& x) {
    return x.x >= xleft && x.x <= xright && x.y >= ybottom && x.y <= ytop;
}

int main(void) {
    int n;
    cin >> n;

    int xleft, xright, ytop, ybottom;

    while (n--) {
        P start, end;
        start.read(), end.read();
        cin >> xleft >> ytop >> xright >> ybottom;

        if (xright < xleft) swap (xright, xleft);
        if (ytop < ybottom) swap (ytop, ybottom);

        P a = { xleft, ytop };
        P b = { xright, ytop };
        P c = { xright, ybottom };
        P d = { xleft, ybottom };

        if (inside(xleft, xright, ytop, ybottom, start) || intersect(a, b, start, end) || intersect(b, c, start, end) || intersect(c, d, start, end) || intersect(d, a, start, end)) {
            cout << "T\n";
        } else {
            cout << "F\n";
        }
    }

    return 0;
}
