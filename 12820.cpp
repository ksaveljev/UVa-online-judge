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
    int n;
    int T = 0;
    string input;

    while (cin >> n) {
        T++;
        goog(T);

        int result = 0;
        while (n--) {
            cin >> input;

            set<char> s;
            map<char,int> m;

            for (char& c: input) {
                s.insert(c);
                m[c]++;
            }

            set<int> x;
            for (auto [k, v]: m) {
                x.insert(v);
            }

            if (s.size() > 1 && s.size() == x.size()) {
                result++;
            }
        }

        cout << result << endl;
    }

    return 0;
}
