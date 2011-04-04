#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
	int h, m;
	char c;
	int h_a = 360 / 12;
	int m_a = 360 / 60;

	while (cin >> h >> c >> m) {
		if (h == 0 && m == 0)
			break;

		int a_m = m * m_a;
		double a_h = h * h_a + a_m * 30.0 / 360;

		double result = a_h - a_m;
		if (result < 0)
			result *= -1;
		result = ((360 - result < result) && (360 - result >= 0)) ? 360 - result : result;

		//cout << result << endl;
		printf("%.3f\n", result);
	}

	return 0;
}
