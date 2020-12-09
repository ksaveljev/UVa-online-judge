#include <iostream>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

bool dp[21][201];

int main(void) {
    int cases, k, price;
    int money, count;

    cin >> cases;

    while (cases--) {
        cin >> money >> count;

        rep (i, 21) rep (j, 201) dp[i][j] = false;
        dp[0][0] = true;

        vector< vector<int> > garments(count);
        rep (i, count) {
            cin >> k;
            while (k--) {
                cin >> price;
                garments[i].push_back(price);
            }
        }

        for (int i = 1; i <= count; i++) {
            for (int j = 0; j <= 201; j++) {
                if (dp[i-1][j]) {
                    for (int k = 0; k < garments[i-1].size(); k++) {
                        if (j + garments[i-1][k] < 201) {
                            dp[i][j + garments[i-1][k]] = true;
                        }
                    }
                }
            }
        }

        int result = -1;
        for (int i = money; i >= 0; i--) {
            if (dp[count][i]) {
                result = i;
                break;
            }
        }

        if (result == -1) {
            cout << "no solution" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
