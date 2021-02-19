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

void count_sort(vector<int> &p, vector<int> &c) {
    int n = p.size();
    vector<int> cnt(n);

    for (auto x : c) {
        cnt[x]++;
    }

    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++) {
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
    string a, b;
    bool first = true;

    while (cin >> a >> b) {
        if (!first) cout << endl;
        first = false;

        string input = a + "$" + b + "#";
        int n = input.size();

        vector<int> p(n), c(n);
        {
            vector<pair<char,int>> a(n);
            loop(n) a[i] = { input[i], i };

            sort(a.begin(), a.end());

            loop(n) p[i] = a[i].second;

            c[p[0]] = 0;
            for (int i = 1; i < n; i++) {
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
            for (int i = 1; i < n; i++) {
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
        for (int i = 0; i < n - 1; i++) {
            int pi = c[i];
            int j = p[pi - 1];
            while (input[i+k] == input[j+k]) k++;
            lcp[pi] = k;
            k = max(k - 1, 0);
        }

        int result = 0;
        set<string> out;
        for (int i = 1; i < n; i++) {
            if ((p[i] < a.size() && p[i-1] > a.size()) || (p[i] > a.size() && p[i-1] < a.size())) {
                if (lcp[i] > result) {
                    result = lcp[i];
                    out.clear();
                    out.insert(input.substr(p[i], lcp[i]));
                } else if (lcp[i] == result) {
                    out.insert(input.substr(p[i], lcp[i]));
                }
            }
        }

        if (result == 0) {
            cout << "No common sequence." << endl;
        } else {
            for (auto x : out)
                cout << x << endl;
        }
    }

    return 0;
}
