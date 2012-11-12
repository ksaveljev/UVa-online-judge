#include <iostream>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int T, R, H, tmp;
    int tp[20], rp[20], hp[20]; // prices
    vector<int> tr[20], rh[20], ht[20]; // dependencies

    while (cin >> T >> R >> H) {
        rep (i, 20) {
            tr[i].clear();
            rh[i].clear();
            ht[i].clear();
        }

        rep (i, T) {
            cin >> tp[i];
            rep (j, R) {
                cin >> tmp;
                tr[i].push_back(tmp);
            }
        }

        rep (i, R) {
            cin >> rp[i];
            rep (j, H) {
                cin >> tmp;
                rh[i].push_back(tmp);
            }
        }

        rep (i, H) {
            cin >> hp[i];
            rep (j, T) {
                cin >> tmp;
                ht[i].push_back(tmp);
            }
        }

        int result = -1;
        int solution[3];

        rep (i, T) {
            rep (j, R) {
                if (tr[i][j] == 1)
                    continue;

                rep (k, H) {
                    if (rh[j][k] == 1 || ht[k][i] == 1)
                        continue;

                    if (result == -1) {
                        result = tp[i] + rp[j] + hp[k];
                        solution[0] = i;
                        solution[1] = j;
                        solution[2] = k;
                    } else {
                        if (tp[i] + rp[j] + hp[k] < result) {
                            result = tp[i] + rp[j] + hp[k];
                            solution[0] = i;
                            solution[1] = j;
                            solution[2] = k;
                        }
                    }
                }
            }
        }

        if (result == -1)
            cout << "Don't get married!" << endl;
        else {
            cout << solution[0] << " " << solution[1] << " " << solution[2] << ":" << result << endl;
        }
    }

    return 0;
}
