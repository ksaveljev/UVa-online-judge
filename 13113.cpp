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
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int A, B;
        cin >> A >> B;

        vector<pair<double,int>> candidates(A);

        loop(A) {
            candidates[i].second = i + 1;
        }

        double V;
        double total = 0;
        vector<double> p(A);
        while (B--) {
            loop(A) {
                cin >> p[i];
            }
            cin >> V;
            total += V;

            loop(A) {
                candidates[i].first += V * p[i];
            }
        }

        sort(candidates.begin(), candidates.end());

        if (candidates[A-1].first >= total * 50.1) {
            cout << fixed << setprecision(0) << candidates[A-1].second << " " << candidates[A-1].first / 100 << endl;
        } else {
            cout << fixed << setprecision(0) << candidates[A-1].second << " " << candidates[A-1].first / 100 << endl;
            cout << fixed << setprecision(0) << candidates[A-2].second << " " << candidates[A-2].first / 100 << endl;
        }

        if (t) cout << endl;
    }
    return 0;
}
