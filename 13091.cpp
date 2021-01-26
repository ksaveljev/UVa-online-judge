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
#define goog(tno) cout << "Case " << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(void) {
    int t;
    cin >> t;
    string input;

    rep (T, 0, t) {
        int lc, fc;
        bool rev = false;
        goog(T+1);

        getline(cin, input); // \n

        rep (i, 0, 5) {
            getline(cin, input);
            rep (j, 0, input.size()) {
                if (input[j] == '|') {
                    lc = j;
                } else if (input[j] == '>') {
                    fc = j;
                    rev = false;
                } else if (input[j] == '<') {
                    fc = j;
                    rev = true;
                }
            }
        }

        if ((!rev && fc < lc) || (rev && fc > lc)) {
            cout << "Thik Ball" << endl;
        } else {
            cout << "No Ball" << endl;
        }
    }
    return 0;
}
