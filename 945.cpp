#include <iostream>
#include <vector>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int container_size(const vector<int> &container) {
    int result = 0;

    rep (i, container.size())
        result += container[i];

    return result;
}

int main(void) {
    bool first = true;
    int c, cw[9], p, pkg;

    while (cin >> c) {
        if (first) first = false;
        else cout << endl;

        bool done = false;
        vector<int> containers[c];
        vector<int> unused;
        rep (i, c) cin >> cw[i];

        cin >> p;

        rep (i, p) {
            cin >> pkg;

            if (done) {
                unused.push_back(pkg);
                continue;
            }

            vector<int> candidates;

            int lowest = -1;
            rep (i, c) {
                if (lowest == -1 || containers[i].size() < lowest) {
                    lowest = containers[i].size();
                    candidates.clear();
                    candidates.push_back(i);
                } else if (containers[i].size() == lowest) {
                    candidates.push_back(i);
                }
            }

            int highest = -1;
            int reduced_container_index;
            rep (i, candidates.size()) {
                if (highest == -1 || cw[candidates[i]] - container_size(containers[candidates[i]]) > highest) {
                    highest = cw[candidates[i]] - container_size(containers[candidates[i]]);
                    reduced_container_index = candidates[i];
                }
            }

            if (pkg > cw[reduced_container_index] - container_size(containers[reduced_container_index])) {
                unused.push_back(pkg);
                done = true;
            } else {
                containers[reduced_container_index].push_back(pkg);
            }
        }

        int max_height = -1;
        rep (i, c) {
            if (max_height == -1 || containers[i].size() > max_height)
                max_height = containers[i].size();
        }

        int cargo_weight = 0;

        while (max_height > 0) {
            rep (i, c) {
                if (i > 0) cout << " ";

                if (containers[i].size() < max_height) { 
                    cout << ":";
                } else {
                    cargo_weight += containers[i].back();
                    cout << containers[i].back();
                    containers[i].pop_back();
                }
            }
            cout << endl;

            max_height--;
        }

        int line_length = 1;
        line_length += 2 * (c - 1);

        rep (i, line_length) cout << '=';
        cout << endl;

        rep (i, c) {
            if (i > 0) cout << " ";
            cout << i + 1;
        }
        cout << endl;

        cout << endl;

        int unused_weight = 0;
        rep (i, c) {
            unused_weight += cw[i];
        }
        unused_weight -= cargo_weight;

        cout << "cargo weight: " << cargo_weight << endl;
        cout << "unused weight: " << unused_weight << endl;
        cout << "unloaded weight: " << container_size(unused) << endl;
    }

    return 0;
}
