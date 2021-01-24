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
    string input;

    cin >> t;

    rep(T, 0, t) {
        goog(T+1);
        int result = -1;

        cin >> input;

        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '>') {
                result = max(result, 1);
            } else if (input[i] == '<') {
                int len = 1;
                if (i + 1 < input.size() && (input[i+1] == '-' || input[i+1] == '=')) {
                    i++;
                    len = 2;
                    while (i + 1 < input.size() && input[i+1] == input[i]) {
                        len++;
                        i++;
                    }
                }
                result = max(result, len);
            } else if (input[i] == '-' || input[i] == '=') {
                int len = 1;
                while (i + 1 < input.size() && input[i+1] == input[i]) {
                    len++;
                    i++;
                }
                if (i + 1 < input.size() && input[i+1] == '>') {
                    len++;
                    i++;
                    result = max(result, len);
                }
            }
        }

        cout << result << endl;
    }
    return 0;
}
