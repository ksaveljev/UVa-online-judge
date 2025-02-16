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

ll LIMIT = 2147483647;

int main(void) {
	int t;
	ll n;
	ll total_length = 0;
	ll seq_length = 0;

	vector<ll> lengths;
	lengths.push_back(0);
	for (int i = 1; ; i++) {
		int len = (int)log10(i) + 1;
		seq_length += len;
		total_length += seq_length;
		lengths.push_back(seq_length + lengths.back());
		if (total_length > LIMIT) {
			break;
		}
	}

	cin >> t;
	while (t--) {
		cin >> n;
		auto it = lower_bound(lengths.begin(), lengths.end(), n);
		it--;
		n = n - (*it);

		n--;

		int len = 1;
		int current = 9;

		while (n >= current * len) {
			n -= current * len;
			len++;
			current *= 10;
		}

		int start = pow(10, len-1);
		int num = start + int(n / len);
		int idx = n % len;

		cout << to_string(num)[idx] << endl;
	}

    return 0;
}
