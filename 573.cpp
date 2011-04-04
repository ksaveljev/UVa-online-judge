#include <iostream>
using namespace std;

int main(void) {
	double h, u, d, f;
	double cur_h;
	int day;
	bool result;

	while (cin >> h >> u >> d >> f) {
		if (h == 0)
			break;

		f = f * u / 100.0;
		cur_h = 0;
		day = 0;
		
		while (true) {
			day++;
			cur_h += u;
			u -= f;
			if (u < 0)
				u = 0;
			if (cur_h > h) {
				result = true;
				break;
			}
			cur_h -= d;
			if (cur_h < 0) {
				result = false;
				break;
			}
		}

		cout << (result ? "success" : "failure") << " on day " << day << endl;
	}


	return 0;
}
