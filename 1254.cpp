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

const int maxL = 1e6;
int w[maxL];
pair<string,int> words[20001];

void count_sort(vector<int> &p, vector<int> &c) {
    int n = p.size();
    vector<int> cnt(n);

    for (auto x : c) {
        cnt[x]++;
    }

    vector<int> pos(n);
    pos[0] = 0;
    rep (i, 1, n) {
        pos[i] = pos[i-1] + cnt[i-1];
    }

    vector<int> p_new(n);
    for (auto x : p) {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }

    p = p_new;
}

int main(void) {
    int N;
    cin >> N;

    int idx = 0;
    string q, input;

    loop(N) {
        cin >> words[i].first;
        words[i].second = i;
    }

    auto prepare = [](pair<string,int> &a, pair<string,int> &b) {
        if (a.first.size() == b.first.size()) {
            if (a.first == b.first) {
                return a.second < b.second;
            }

            return a.first < b.first;
        }

        return a.first.size() < b.first.size();
    };

    sort(words, words + N, prepare);

    loop(N) {
        if (i > 0) input += "$";
        input += words[i].first;
        for (int j = 0; j < words[i].first.size(); j++) {
            w[idx + j] = i;
        }
        idx += words[i].first.size();
        w[idx++] = -1;
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
        rep (i, 1, n) {
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
        k = max(k - 1, 0);
    }

    int Q;
    cin >> Q;

    auto findMatch = [&input](int a, string q) {
        int n = q.size();
        loop(n) {
            if (input[a+i] < q[i]) return true;
            if (input[a+i] > q[i]) return false;
        }
        return false;
    };

    while (Q--) {
        cin >> q;

        auto x = lower_bound(p.begin(), p.end(), q, findMatch) - p.begin();

        if (input.substr(p[x], q.size()) != q) {
            cout << -1 << endl;
            continue;
        }

        set<int> s;
        s.insert(w[p[x]]);
        int idx = x + 1;
        while (lcp[idx] >= q.size()) {
            s.insert(w[p[idx]]);
            idx++;
        }

        vector<int> v(s.begin(), s.end());
        sort(v.begin(), v.end());

        int limit = min(int(v.size()), 10);
        loop(limit) {
            if (i > 0) cout << " ";
            cout << words[v[i]].second + 1;
        }
        cout << endl;
    }

    return 0;
}
