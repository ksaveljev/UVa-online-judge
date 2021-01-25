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

const int INF = 1e9+7;

int main(void) {
    int n;

    while (cin >> n) {
        vector<int> v(n);
        loop(n) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int result = INF;

        int sum = 0;
        for (int i = 0; i + 1 < v.size(); i += 2) {
            sum += min(abs(v[i+1] - v[i]), 24 - abs(v[i+1] - v[i]));
        }
        result = min(result, sum);

        sum = min(abs(v[0] - v[v.size()-1]), 24 - abs(v[0] - v[v.size()-1]));
        for (int i = 1; i + 1 < v.size(); i += 2) {
            sum += min(abs(v[i+1] - v[i]), 24 - abs(v[i+1] - v[i]));
        }
        result = min(result, sum);

        cout << result << endl;
    }

    return 0;
}
