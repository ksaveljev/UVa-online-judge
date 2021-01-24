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
#include <sstream>
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

vector<string> words(string& x) {
    stringstream ss(x);
    string s;
    vector<string> result;
    while (ss >> s) {
        result.push_back(s);
    }
    return result;
}

int main(void) {
    string a, b;

    while (getline(cin, a)) {
        getline(cin, b);
        vector<string> va = words(a);
        vector<string> vb = words(b);

        if (va.size() != vb.size()) {
            cout << "no" << endl;
            continue;
        }

        bool ok = true;
        for (int i = 0; i < va.size(); i++) {
            if (va[i][0] != vb[i][0]) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
    }

    return 0;
}
