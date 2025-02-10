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
	int n, r, diver;

	while (cin >> n >> r) {
		vector<bool> v(n+1, false);
		for (int i = 0; i < r; i++) {
			cin >> diver;
			v[diver] = true;
		}

		if (n == r) {
			cout << "*" << "\n";
			continue;
		}

		for (int i = 1; i <= n; i++) {
			if (!v[i]) {
				cout << i << " ";
			}
		}
		cout << "\n";
	}
    return 0;
}
