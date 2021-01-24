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
        int prio = 1;
        int freq;
        string name;
        map<string,int> m;
        priority_queue<tuple<int,int,string>, vector<tuple<int,int,string>>, greater<tuple<int,int,string>>> q;

        int n, k;
        cin >> n >> k;
        while (n--) {
            cin >> name >> freq;
            m[name] = freq;
            q.push({freq, prio, name});
            prio++;
        }

        while (k--) {
            auto [t, p, n] = q.top();
            q.pop();

            cout << t << " " << n << endl;
            q.push({t + m[n], p, n});
        }
    }

    return 0;
}
