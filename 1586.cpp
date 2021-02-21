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
    string input;
    map<char,double> m;
    int t;
    cin >> t;

    m['C'] = 12.01;
    m['H'] = 1.008;
    m['O'] = 16.00;
    m['N'] = 14.01;

    while (t--) {
        cin >> input;

        int i = 0;
        double result = 0;
        while (i < input.size()) {
            char x = input[i];
            i++;

            if (i < input.size()) {
                if (input[i] >= '0' && input[i] <= '9') {
                    int d = 0;
                    while (i < input.size() && input[i] >= '0' && input[i] <= '9') {
                        d = d * 10 + (input[i] - '0');
                        i++;
                    }
                    result += d * m[x];
                } else {
                    result += m[x];
                }
            } else {
                result += m[x];
            }
        }

        cout << fixed << setprecision(3) << result << endl;
    }

    return 0;
}
