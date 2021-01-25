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
    int flag = 0;

    while (true) {
        vector<int> x;

        while (cin >> input) {
            if (input == "~") {
                return 0;
            }

            if (input == "#")
                break;

            if (input == "0") {
                flag = 1;
            } else if (input == "00") {
                flag = 0;
            } else {
                loop(input.size() - 2) {
                    x.push_back(flag);
                }
            }
        }

        int result = 0;
        for (int i : x) {
            if (i == 1) {
                result = (result << 1) | 1;
            } else {
                result <<= 1;
            }
        }
        cout << result << endl;
    }
    return 0;
}
