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
    int n;
    string input;

    while (cin >> n) {
        if (n == 0) break;
        getline(cin, input); // \n
        getline(cin, input);

        while (n < 0) {
            n += 26;
        }
        while (n > 25) {
            n -= 26;
        }

        for (char& c : input) {
            if (c >= 'a' && c <= 'z') {
                int x = c - 'a';
                x += n;
                if (x > 25) x -= 26;
                cout << char('a' + x);
            } else if (c >= 'A' && c <= 'Z') {
                int x = c - 'A';
                x += n;
                if (x > 25) x -= 26;
                cout << char('A' + x);
            } else {
                cout << c;
            }
        }
        cout << endl;
    }

    return 0;
}
