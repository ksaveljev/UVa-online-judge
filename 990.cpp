#include <iostream>
#include <algorithm>
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

typedef struct _item {
    int value;
    int weight;
    int original_index;
} item;

typedef struct _result {
    int value;
    vector<int> taken;
} result;

int t, w, n;
item* items;
bool* taken;
result best_result;

bool theTruthIsOutThere(const item& a, const item& b) {
    return 1.0 * a.value / a.weight > 1.0 * b.value / b.weight;
}

bool trustNoOne(int a, int b) {
    return items[a].original_index < items[b].original_index;
}

int find_max_bound(int value, int weight, int index) {
    while (index < n && weight > 0) {
        if (items[index].weight <= weight) {
            value += items[index].value;
            weight -= items[index].weight;
        } else {
            value += int((1.0 * items[index].value / items[index].weight) * weight);
            weight = 0;
        }

        index++;
    }

    return value;
}

void solve(int value, int weight, int max_bound, int index) {
    if (index == n) {
        if (value > best_result.value) {
            best_result.value = value;
            best_result.taken.clear();
            rep (i, n) {
                if (taken[i]) {
                    best_result.taken.push_back(i);
                }
            }
        }

        return;
    }

    if (max_bound <= best_result.value) {
        return;
    }

    if (items[index].weight <= weight) {
        taken[index] = true;
        solve(value + items[index].value, weight - items[index].weight, find_max_bound(value + items[index].value, weight - items[index].weight, index + 1), index + 1);
        taken[index] = false;
    }

    solve(value, weight, find_max_bound(value, weight, index + 1), index + 1);
}

int main(void) {
    bool first = true;

    while (cin >> t >> w >> n) {
        if (!first) {
            cout << endl;
        }
        first = false;

        items = new item[n];
        taken = new bool[n];

        best_result.value = 0;

        rep (i, n) {
            taken[i] = false;

            cin >> items[i].weight >> items[i].value;
            items[i].original_index = i;

            // descent w*d and ascent 2w*d
            items[i].weight = 3 * w * items[i].weight;
        }

        sort(items, items + n, theTruthIsOutThere);

        solve(0, t, find_max_bound(0, t, 0), 0);

        sort(best_result.taken.begin(), best_result.taken.end(), trustNoOne);

        cout << best_result.value << endl;
        cout << best_result.taken.size() << endl;
        rep (i, best_result.taken.size()) {
            int index = best_result.taken[i];
            cout << items[index].weight / (3 * w) << " " << items[index].value << endl;
        }

        delete [] taken;
        delete [] items;
    }

    return 0;
}
