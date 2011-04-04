#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(void) {
	char c;
	int prev_h = 0, prev_m = 0, prev_s = 0, prev_speed = 0;
	int h, m, s, speed;
	double result = 0;

	while (cin >> h >> c >> m >> c >> s) {
		if (cin.peek() == ' ') {
			cin >> speed;
			result += ((h * 3600 + m * 60 + s) - (prev_h * 3600 + prev_m * 60 + prev_s)) * prev_speed / 3600.0;
			prev_h = h;
			prev_m = m;
			prev_s = s;
			prev_speed = speed;
		} else {
			result += ((h * 3600 + m * 60 + s) - (prev_h * 3600 + prev_m * 60 + prev_s)) * prev_speed / 3600.0;
			prev_h = h;
			prev_m = m;
			prev_s = s;
			printf("%d%d:%d%d:%d%d %.2f km\n", h / 10, h % 10, m / 10, m % 10, s / 10, s % 10, result);
		}
	}

	return 0;
}
