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

const int maxN = 1e6+1e5;
const int maxK = 21;
int w[maxN];
int start[1005];
int st[maxN][maxK];
int llog[maxN];

void count_sort(vector<int> &p, vector<int> &c) {
    int n = p.size();

    vector<int> cnt(n);
    for (auto x : c) {
        cnt[x]++;
    }

    vector<int> pos(n);
    pos[0] = 0;
    rep (i, 1, n) pos[i] = pos[i-1] + cnt[i-1];

    vector<int> p_new(n);
    for (auto x : p) {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }

    p = p_new;
}

int main(void) {
    fast_io;
    int t;
    cin >> t;

    llog[1] = 0;
    rep(i, 2, maxN) llog[i] = llog[i/2] + 1;

    while (t--) {
        int N;
        cin >> N;

        string input;
        string tmp;
        int idx = 0;
        loop(N) {
            start[i] = idx;
            cin >> tmp;
            if (i > 0) input += "$";
            input += tmp;
            rep (j, 0, tmp.size()) {
                w[idx+j] = i;
            }
            idx+=tmp.size();
            w[idx++]=i;
        }
        input += "#";

        int n = input.size();
        vector<int> p(n), c(n);
        {
            vector<pair<char,int>> a(n);
            loop(n) a[i] = { input[i], i };

            sort(a.begin(), a.end());

            loop(n) p[i] = a[i].second;

            c[p[0]] = 0;
            rep(i, 1, n) {
                if (a[i].first == a[i-1].first) {
                    c[p[i]] = c[p[i-1]];
                } else {
                    c[p[i]] = c[p[i-1]] + 1;
                }
            }
        }

        int k = 0;
        while ((1<<k) < n) {
            loop(n) p[i] = (p[i] - (1<<k) + n) % n;

            count_sort(p, c);

            vector<int> c_new(n);
            c_new[p[0]] = 0;
            rep (i, 1, n) {
                pair<int,int> prev = { c[p[i-1]], c[(p[i-1] + (1<<k)) % n] };
                pair<int,int> now = { c[p[i]], c[(p[i] + (1<<k)) % n] };
                if (prev == now) {
                    c_new[p[i]] = c_new[p[i-1]];
                } else {
                    c_new[p[i]] = c_new[p[i-1]] + 1;
                }
            }

            c = c_new;
            k++;
        }

        vector<int> lcp(n);
        k = 0;
        loop(n-1) {
            int pi = c[i];
            int j = p[pi - 1];
            while (input[i+k] == input[j+k]) k++;
            lcp[pi] = k;
            k = max(k-1, 0);
        }

        loop(n) {
            st[i][0] = lcp[i];
        }

        rep(j, 1, maxK) {
            for (int i = 0; i + (1<<j) <= n; i++) {
                st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
            }
        }

        vector<pair<int,int>> v(N);
        loop(N) {
            v[i] = {c[start[i]], i};
        }
        sort(v.begin(), v.end());

        vector<int> len(N, 1);
        rep (i, 1, N) {
            int L = v[i-1].first;
            int R = v[i].first;

            int j = llog[R - (L+1) + 1];
            int d = min(st[L+1][j], st[R - (1<<j) + 1][j]);
            len[v[i-1].second] = max(len[v[i-1].second], d+1);
            len[v[i].second] = max(len[v[i].second], d+1);
        }

        int result = 0;
        for (auto x : len) result += x;
        cout << result << endl;
    }

    return 0;
}
