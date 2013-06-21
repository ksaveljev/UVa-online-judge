#include <iostream>
#include <algorithm>
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
} item;

bool theTruthIsOutThere(const item& a, const item& b) {
    return 1.0 * a.value / a.weight > 1.0 * b.value / b.weight;
}

int t, n, g;
item* items;
int best_result;

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
        if (value > best_result) {
            best_result = value;
        }
        return;
    }

    if (max_bound <= best_result) {
        return;
    }

    if (items[index].weight <= weight) {
        solve(value + items[index].value, weight - items[index].weight, find_max_bound(value + items[index].value, weight - items[index].weight, index + 1), index + 1);
    }

    solve(value, weight, find_max_bound(value, weight, index + 1), index + 1);
}

int main(void) {
    cin >> t;

    while (t--) {
        cin >> n;

        items = new item[n];

        rep (i, n) {
            cin >> items[i].value >> items[i].weight;
        }

        sort(items, items + n, theTruthIsOutThere);

        cin >> g;

        int value = 0;

        rep (i, g) {
            int weight;
            best_result = 0;

            cin >> weight;

            solve(0, weight, find_max_bound(0, weight, 0), 0);

            value += best_result;
        }

        cout << value << endl;

        delete [] items;
    }

    return 0;
}
