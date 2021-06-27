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

    for (int scenario = 1; scenario <= t; scenario++) {
        if (scenario > 1) cout << "\n";

        int n;
        cin >> n;

        string input;
        map<string,int> cities;

        loop (n) {
            cin >> input;
            cities[input] = i;
        }

        int m;
        cin >> m;

        string a, b;
        int c;
        vector<tuple<int,int,int>> edges;

        loop (m) {
            cin >> a >> b >> c;
            edges.push_back({cities[a], cities[b], c});
        }

        int q;
        cin >> q;
        vector<int> qq(q);

        loop (q) {
            cin >> qq[i];
        }

        int mm = *max_element(qq.begin(), qq.end());
        mm++;
        mm++;

        vector<vector<int>> dist(n, vector<int>(mm, INF));
        loop (mm) {
            dist[0][i] = 0;
        }

        for (int j = 0; j < mm; j++) {
            for (int i = 0; i < n - 1; i++) {
                for (auto [a, b, c] : edges) {
                    dist[b][j+1] = min(dist[b][j], dist[b][j+1]);
                    if (dist[a][j] < INF) {
                        dist[b][j+1] = min(dist[b][j+1], dist[a][j] + c);
                    }
                }
            }
        }

        cout << "Scenario #" << scenario << "\n";
        for (auto x : qq) {
            if (dist[n-1][x+1] < INF) {
                cout << "Total cost of flight(s) is $" << dist[n-1][x+1] << "\n";
            } else {
                cout << "No satisfactory flights\n";
            }
        }
    }

    return 0;
}
