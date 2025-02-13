#include <iostream>
#include <iterator>
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

vector<int> primes;

void precalc() {
	primes.push_back(2);

	for (int i = 3; i <= 1000000; i+=2) {
		bool ok = true;
		for (int j = 3; j <= sqrt(i); j++) {
			if (i % j == 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			primes.push_back(i);
		}
	}
}

int main(void) {
	int n;

	precalc();

	int case_number = 0;
	while (cin >> n) {
		if (n == 0) break;
		case_number++;

		unsigned long long result = 0;

		for (auto prime_it = primes.begin(); prime_it != primes.end(); prime_it++) {
			if (*prime_it >= n) {
				break;
			}

			int target = n - *prime_it;
			auto it = upper_bound(primes.begin(), prime_it, target);
			int elements = distance(primes.begin(), it);
			result += elements;
		}

		cout << "Case " << case_number << ": " << result << "\n";
	}

    return 0;
}
