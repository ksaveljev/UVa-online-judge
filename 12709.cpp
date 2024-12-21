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
    int L, W, H;

    while (cin >> t) {
        if (!t) break;

        int maxH = 0, maxV = 0;
        while (t--) {
            cin >> L >> W >> H;
            int V = L * W * H;

            if (H > maxH || (H == maxH && V > maxV)) {
                maxH = H;
                maxV = V;
            }
        }

        cout << maxV << endl;
    }
    return 0;
}