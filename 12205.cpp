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

const int maxN = 1e4;
vector<pair<int,int>> calls(maxN);

int main(void) {
    int tmp;
    int n, m;

    while (cin >> n >> m) {
        if (!(n|m)) break;

        loop(n) {
            cin >> tmp >> tmp >> calls[i].first >> calls[i].second;
        }

        int s, d;
        while (m--) {
            cin >> s >> d;
            int result = 0;

            loop(n) {
                if ((calls[i].first < s + d) && (calls[i].first + calls[i].second > s)) {
                    result++;
                }
            }

            cout << result << endl;
        }
    }

    return 0;
}
