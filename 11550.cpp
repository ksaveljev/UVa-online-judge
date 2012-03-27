#include <iostream>
#include <set>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int t, n, m;
    int matrix[8][28];

    cin >> t;

    while (t--) {
        cin >> n >> m;

        int count[28] = { 0 };

        rep (i, n) {
            rep (j, m) {
                cin >> matrix[i][j];
                
                if (matrix[i][j] == 1) {
                    count[j]++;
                }
            }
        }

        bool ok = true;

        rep (i, m) {
            if (count[i] == 2)
                continue;

            ok = false;
            break;
        }


        if (ok) {
            set< pair<int,int> > s;

            rep (i, m) {
                pair<int,int> tmp = make_pair(-1, -1);

                rep (j, n) {
                    if (matrix[j][i] == 0)
                        continue;

                    if (tmp.first == -1) {
                        tmp.first = j;
                    } else {
                        tmp.second = j;
                    }
                }

                s.insert(tmp);
            }

            ok = s.size() == m;
        }

        cout << (ok ? "Yes" : "No") << endl;
    }

    return 0;
}
