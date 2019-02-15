#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef struct nums_ {
    ll a, b, c, r;
} nums;

bool thetruthisoutthere(const nums &a, const nums &b) {
    if (a.r == b.r) {
        if (a.a == b.a) {
            if (a.b == b.b) {
                return a.c < b.c;
            } else {
                return a.b < b.b;
            }
        } else {
            return a.a < b.a;
        }
    } else {
        return a.r < b.r;
    }
}

int main(void) {
    vector<nums> v;
    ll a, b, c, r;
    ll lim1 = 25600 / 3;
    for (a = 1; a < lim1; a++) {
        ll lim2 = (25600 - a) / 2;
        for (b = a; b < lim2; b++) {
            ll x = a + b;
            ll y = a * b;
            /*
            (a + b + c) * 10000 == a * b * c
            10000 * a + 10000 * b + 10000 * c == a * b * c
            10000 * a + 10000 * b = a * b * c - 10000 * c
            10000 * a + 10000 * b = c * (a * b - 10000)
            10000 * (a + b) = c * (a * b - 10000)
            c = 10000 * (a + b) / (a * b - 10000)
            */
            if (y <= 10000) continue;
            c = 10000 * x / (y - 10000);
            r = x + c;
            if (b > c || r > 25600) continue;
            if (r == y * c / 10000) {
                nums tmp;
                tmp.a = a;
                tmp.b = b;
                tmp.c = c;
                tmp.r = r;
                v.push_back(tmp);
            }
        }
    }

    sort(v.begin(), v.end(), thetruthisoutthere);

    char ch;
    cin >> a >> ch >> b >> c >> ch >> r;
    ll start = a * 100 + b;
    ll end = c * 100 + r;

    for (int i = 0, sz = v.size(); i < sz; i++) {
        if (v[i].r >= start && v[i].r <= end) {
            printf("%lld.%02lld = ", v[i].r / 100, v[i].r % 100);
            printf("%lld.%02lld + %lld.%02lld + %lld.%02lld = ", v[i].a / 100, v[i].a % 100, v[i].b / 100, v[i].b % 100, v[i].c / 100, v[i].c % 100);
            printf("%lld.%02lld * %lld.%02lld * %lld.%02lld\n", v[i].a / 100, v[i].a % 100, v[i].b / 100, v[i].b % 100, v[i].c / 100, v[i].c % 100);
        }
    }


    return 0;
}
