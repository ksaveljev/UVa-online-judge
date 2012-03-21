#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int minimum(int k, int *front, int *right) {
    int result = 0;
    bool front_taken[8] = { false };
    bool right_taken[8] = { false };

    rep(i, k) {
        rep(j, k) {
            if (front[i] == right[j] && !front_taken[i] && !right_taken[j]) {
                result += front[i];
                front_taken[i] = true;
                right_taken[j] = true;
            }
        }
    }

    rep(i, k) {
        if (!front_taken[i])
            result += front[i];
        if (!right_taken[i])
            result += right[i];
    }

    return result;
}

int maximum(int k, int *front, int *right) {
    int result = 0;

    rep(i, k)
        rep(j, k)
            result += min(front[i], right[j]);

    return result;
}

int main(void) {
    int cases, k;
    int front[8], right[8];

    cin >> cases;

    while (cases--) {
        cin >> k;

        rep(i,k) cin >> front[i];
        rep(i,k) cin >> right[i];

        pair<int,int> result = make_pair(minimum(k, front, right), maximum(k, front, right));

        cout << "Matty needs at least " << result.first << " blocks, and can add at most " << result.second - result.first << " extra blocks." << endl;
    }

    return 0;
}
