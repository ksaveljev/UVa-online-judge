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

vector<int> merge(int k, vector<int> &a, vector<int> &b) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

	vector<int> result;

	for (int i = 0; i < k; i++) {
		q.push({a[i] + b[0], 0});
	}

	while (result.size() < k) {
		int sum = q.top().first;
		int idx = q.top().second;
		q.pop();
		result.push_back(sum);
		if (idx + 1 < k) {
			q.push({sum - b[idx] + b[idx+1], idx + 1});
		}
	}

	return result;
}

int main(void) {
	int k;

	fast_io;

	while (cin >> k) {
		vector<vector<int>> input(k, vector<int>(k));
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				cin >> input[i][j];
			}
			sort(input[i].begin(), input[i].end());
		}

		vector<int> res = input[0];
		for (int i = 1; i < k; i++) {
			res = merge(k, res, input[i]);
		}

		for (int i = 0; i < k; i++) {
			if (i > 0) cout << " ";
			cout << res[i];
		}
		cout << "\n";
	}

    return 0;
}
