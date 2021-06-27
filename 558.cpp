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
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> dist(n, INF);
        vector<tuple<int,int,int>> edges(m);

        int a, b, c;
        for (auto& x : edges) {
            cin >> a >> b >> c;
            x = {a, b, c};
        }

        dist[0] = 0;

        int flag;
        for (int i = 0; i < n; i++) {
            flag = -1;
            for (auto [a, b, c] : edges) {
                if (dist[a] < INF) {
                    if (dist[a] + c < dist[b]) {
                        dist[b] = dist[a] + c;
                        flag = a;
                    }
                }
            }
        }

        if (flag == -1) {
            cout << "not possible\n";
        } else {
            cout << "possible\n";
        }
    }

    return 0;
}
