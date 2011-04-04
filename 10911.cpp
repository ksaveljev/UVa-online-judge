#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

struct student {
	string name;
	int x;
	int y;
};

int n;
student students[16];
bool taken[16];
double result;
double current_result;

double mydistance(int a, int b) {
	return sqrt((students[a].x - students[b].x) * (students[a].x - students[b].x) + (students[a].y - students[b].y) * (students[a].y - students[b].y));
}

void solve(int depth) {
	if (depth == n) {
		if (current_result < result)
			result = current_result;
		return;
	}

	int st;

	// grab any available student
	for (int i = 0, sz = 2 * n; i < sz; i++) {
		if (taken[i] == false) {
			st = i;
			taken[i] = true;
			break;
		}
	}

	// go over all available pairs for selected student
	for (int i = 0, sz = 2 * n; i < sz; i++) {
		if (taken[i] == false) {
			taken[i] = true;
			double d = mydistance(st, i);
			current_result += d;
			if (current_result > result) {
				current_result -= d;
				taken[i] = false;
				continue;
			}
			solve(depth + 1);
			current_result -= d;
			taken[i] = false;
		}
	}

	taken[st] = false;
}

int main(void) {
	int cases = 0;

	while (cin >> n) {
		if (n == 0)
			break;

		cases++;
		current_result = 0;
		result = 100000000;

		for (int i = 0; i < 16; i++)
			taken[i] = false;

		for (int i = 0, sz = 2 * n; i < sz; i++) {
			cin >> students[i].name >> students[i].x >> students[i].y;
		}

		solve(0);

		cout << "Case " << cases << ": " << fixed << setprecision(2) << result << endl;
	}

	return 0;
}
