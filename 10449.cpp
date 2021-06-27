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
int dist[201];
int busyness[201];
tuple<int,int,int> roads[200000];

int main(void) {
    int n;
    int counter = 0;

    while (cin >> n) {
        counter++;
        cout << "Set #" << counter << "\n";

        for (int i = 0; i < n; i++) {
            dist[i] = INF;
        }

        for (int i = 0; i < n; i++) {
            cin >> busyness[i];
        }

        int r;
        cin >> r;

        int a, b, c;
        for (int i = 0; i < r; i++) {
            cin >> a >> b;
            --a, --b;
            c = busyness[b] - busyness[a];
            c = c * c * c;
            roads[i] = {a, b, c};
        }

        dist[0] = 0;

        if (n > 0) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < r; j++) {
                    auto [a, b, c] = roads[j];
                    if (dist[a] < INF) {
                        if (dist[a] + c < dist[b]) {
                            dist[b] = dist[a] + c;
                        }
                    }
                }
            }

            for (int j = 0; j < r; j++) {
                auto [a, b, c] = roads[j];
                if (dist[a] < INF) {
                    if (dist[a] + c < dist[b]) {
                        dist[b] = -INF;
                    }
                }
            }
        }

        int q;
        cin >> q;

        int x;
        while (q--) {
            cin >> x, --x;
            if (dist[x] < 3 || dist[x] == INF) cout << "?\n";
            else cout << dist[x] << "\n";
        }
    }


    return 0;
}
