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
#include <cstdio>
#include <list>
#include <cassert>
#include <climits>
#include <cassert>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int INF = 1e9+7;

int main(void) {
    int n, m;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        vector<tuple<int,int,int>> edges;

        int a, b, c;
        while (m--) {
            cin >> a >> b >> c;
            --a, --b;
            edges.push_back({a, b, c});
        }

        vector<int> dist(n, -INF);
        dist[0] = 0;

        bool cycle = false;
        for (int i = 0; i < n; i++) {
            cycle = false;
            for (auto [a, b, c] : edges) {
                if (dist[a] > -INF) {
                    if (dist[a] + c > dist[b]) {
                        dist[b] = dist[a] + c;
                        cycle = true;
                    }
                }
            }
        }

        if (cycle) cout << "Unlimited!" << endl;
        else {
            int best = -INF;
            for (int i = 0; i < n; i++) {
                best = max(best, dist[i]);
            }
            cout << best << endl;
        }
    }

    return 0;
}
