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
#include <climits>
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

const int maxN = 1e6;
int w[maxN];

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
    bool first = true;

    while (cin >> N) {
        if (N == 0) break;
        if (!first) cout << endl;
        first = false;

        if (N == 1) {
            string tmp;
            cin >> tmp;
            cout << tmp << endl;
            continue;
        }

        string input, tmp;
        int idx = 0;
        int cut = 2;
        loop(N) {
            cin >> tmp;
            if (i > 0) input += cut++;
            input += tmp;

            rep (j, 0, tmp.size()) {
                w[idx + j] = i;
            }
            idx += tmp.size();
            w[idx++] = i;
        }
        input += char(1);

        int n = input.size();
        vector<int> p(n), c(n);
        {
            vector<pair<char,int>> a(n);
            loop(n) a[i] = {input[i], i};

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

            k++;
            c = c_new;
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

        int mid = N / 2 + 1;
        int L = N, R = N;
        vector<int> cnt(N);
        int unique = 0;
        int best = 0;
        vector<int> idxs;
        while (R < n) {
            if (unique < mid) {
                int word = w[p[R]];
                cnt[word]++;
                if (cnt[word] == 1) unique++;
                R++;
            } else if (unique == mid) {
                int current = INT_MAX;
                int pos = L + 1;
                for (int i = L + 1; i < R; i++) {
                    if (lcp[i] < current) {
                        current = lcp[i];
                        pos = i;
                    }
                }

                if (current > best) {
                    best = current;
                    idxs.clear();
                }
                if (current == best) {
                    idxs.push_back(pos);
                }

                int word = w[p[L]];
                cnt[word]--;
                if (cnt[word] == 0) unique--;
                L++;
            }
        }

        if (best == 0) {
            cout << "?" << endl;
        } else {
            string prev = "";
            for (int idx : idxs) {
                string result = input.substr(p[idx], best);
                if (result == prev) continue;
                prev = result;
                cout << result << endl;
            }
        }
    }

    return 0;
}
