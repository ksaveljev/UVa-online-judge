#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct segment {
	double r;
	double x1, y1, x2, y2;
};

bool theTruthIsOutThere(const segment& a, const segment& b) {
	return a.x1 < b.x1 ? true : false;
}

int main(void) {
	int n, nl;
	int counter;
	segment tmp;
	vector<segment> v;
	vector<double> x;

	cin >> n;

	while (n--) {
		v.clear();
		x.clear();

		cin >> nl;

		while (nl--) {
			cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2 >> tmp.r;
			x.push_back(tmp.x1);
			x.push_back(tmp.x2);
			if (tmp.x1 > tmp.x2) {
				swap(tmp.x1, tmp.x2);
				swap(tmp.y1, tmp.y2);
			}
			v.push_back(tmp);
		}

		sort(x.begin(), x.end());
		sort(v.begin(), v.end(), theTruthIsOutThere);

		cout << x.size() + 1 << endl;

		for (int i = 0, sz = x.size(); i < sz; i++) {
			if (i == 0) {
				printf("-inf %.3f 1.000\n", x[i]);
				continue;
			} 

			double result = 1.0;
			for (int y = 0, sz2 = v.size(); y < sz2; y++) {
				if(v[y].x1 <= x[i-1] && v[y].x2 >= x[i])
					result *= v[y].r;
			}
			printf("%.3f %.3f %.3f\n", x[i-1], x[i], result);

			if (i == sz-1) {
				printf("%.3f +inf 1.000\n", x[i]);
			}
		}

		if (n)
			cout << endl;
	}

	return 0;
}
