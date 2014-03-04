#include <iostream>
#include <vector>
#include <set>
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

struct weigh_in {
    set<int> left;
    set<int> right;
    char result;
};

bool can_be_false_coin(int coin, const vector<weigh_in> &weigh_ins) {
    bool result = false;

    rep (i, sz(weigh_ins)) {
        if (weigh_ins[i].left.find(coin) != weigh_ins[i].left.end()) {
            if (weigh_ins[i].result == '=') return false;
            else result = true;
        } else if (weigh_ins[i].right.find(coin) != weigh_ins[i].right.end()) {
            if (weigh_ins[i].result == '=') return false;
            else result = true;
        } else {
            if (weigh_ins[i].result != '=') return false;
        }
    }

    return result;
}

int main(void) {
    int cases, N, K, P, coin;

    cin >> cases;

    while (cases--) {
        cin >> N >> K;

        vector<weigh_in> weigh_ins;
        set<int> coins_used;

        while (K--) {
            cin >> P;
            
            weigh_in tmp;

            rep (i, P) {
                cin >> coin;
                coins_used.insert(coin);
                tmp.left.insert(coin);
            }

            rep (i, P) {
                cin >> coin;
                coins_used.insert(coin);
                tmp.right.insert(coin);
            }

            cin >> tmp.result;

            weigh_ins.push_back(tmp);
        }

        vector<int> suspects;
        REPI (i, 1, N) {
            if (can_be_false_coin(i, weigh_ins))
                suspects.push_back(i);
        }

        if (suspects.empty()) {
            REPI (i, 1, N) {
                if (coins_used.find(i) == coins_used.end())
                    suspects.push_back(i);
            }
        }

        if (suspects.size() == 1) cout << suspects[0] << endl;
        else cout << 0 << endl;

        if (cases) cout << endl;
    }

    return 0;
}
