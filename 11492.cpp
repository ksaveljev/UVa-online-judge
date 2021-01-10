#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

const int INF = 1e9+7;
int m;
string start, finish;
map<string, vector<pair<string,string>>> lang;
map<pair<string,char>, int> dist;

int main(void) {
    while (cin >> m) {
        if (m == 0) break;
        cin >> start >> finish;

        lang.clear();
        dist.clear();

        string a, b, c;
        while (m--) {
            cin >> a >> b >> c;
            lang[a].push_back({b, c});
            lang[b].push_back({a, c});
        }

        priority_queue<tuple<int,string,char>, vector<tuple<int,string,char>>, greater<tuple<int,string,char>>> q;
        q.push({0, start, ' '});
        while (!q.empty()) {
            auto [d, l, ch] = q.top();
            q.pop();

            if (dist.find({l, ch}) != dist.end() && dist[{l, ch}] < d) continue;

            for (auto [nl, w] : lang[l]) {
                if (w[0] == ch) continue;

                if (dist.find({nl, w[0]}) == dist.end() || d + w.size() < dist[{nl, w[0]}]) {
                    dist[{nl, w[0]}] = d + w.size();
                    q.push({d + w.size(), nl, w[0]});
                }
            }
        }

        int best = INF;
        for (char x = 'a'; x <= 'z'; x++) {
            if (dist.find({finish, x}) != dist.end()) {
                best = min(best, dist[{finish, x}]);
            }
        }

        if (best == INF) {
            cout << "impossivel" << endl;
        } else {
            cout << best << endl;
        }
    }

    return 0;
}
