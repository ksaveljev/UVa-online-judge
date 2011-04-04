#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int,int> pos;

int main(void) {
	int m;
	string input;
	vector<pos> ones;
	vector<pos> threes;

	while (cin >> m) {
		ones.clear();
		threes.clear();

		for (int i = 0; i < m; i++) {
			cin >> input;
			for (int y = 0, sz = input.size(); y < sz; y++) {
				if (input[y] == '1')
					ones.push_back(make_pair(i,y));
				else if (input[y] == '3')
					threes.push_back(make_pair(i,y));
			}
		}

		int result = -1;
		for (int i = 0, sz = ones.size(); i < sz; i++) {
			int max = -1;
			for (int y = 0, sz2 = threes.size(); y < sz2; y++) {
				int tmp = abs(ones[i].first - threes[y].first) + abs(ones[i].second - threes[y].second);
				if (max == -1)
					max = tmp;
				else if (tmp < max)
					max = tmp;
			}
			if (result == -1)
				result = max;
			else if (max > result)
				result = max;
		}

		cout << result << endl;
	}

	return 0;
}
