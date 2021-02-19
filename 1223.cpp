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
    int t;
    cin >> t;

    while (t--) {
        string input;
        cin >> input;
        input += "$";

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

        int result = 0;
        vector<int> lcp(n);
        k = 0;
        loop(n-1) {
            int pi = c[i];
            int j = p[pi - 1];
            while (input[i+k] == input[j+k]) k++;
            lcp[pi] = k;
            result = max(result, lcp[pi]);
            k = max(k - 1, 0);
        }

        cout << result << endl;
    }

    return 0;
}
