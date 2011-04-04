#include <iostream>
using namespace std;

struct num {
	num() : i(0), v(0), x(0), l(0), c(0) {}
	int i, v, x, l, c;
};

int main(void) {
	num nums[101]; 
	int n;

	nums[1].i = 1;
	nums[2].i = 2;
	nums[3].i = 3;
	nums[4].i = 1;
	nums[4].v = 1;
	nums[5].v = 1;
	nums[6].i = 1;
	nums[6].v = 1;
	nums[7].i = 2;
	nums[7].v = 1;
	nums[8].i = 3;
	nums[8].v = 1;
	nums[9].i = 1;
	nums[9].x = 1;
	nums[10].x = 1;
	nums[20].x = 2;
	nums[30].x = 3;
	nums[40].x = 1;
	nums[40].l = 1;
	nums[50].l = 1;
	nums[60].x = 1;
	nums[60].l = 1;
	nums[70].x = 2;
	nums[70].l = 1;
	nums[80].x = 3;
	nums[80].l = 1;
	nums[90].x = 1;
	nums[90].c = 1;
	nums[100].c = 1;

	num result[101];

	for (int i = 1; i < 101; i++) {
		if (i < 10) {
			result[i].i += result[i-1].i + nums[i].i;
			result[i].v += result[i-1].v + nums[i].v;
			result[i].x += result[i-1].x + nums[i].x;
			result[i].l += result[i-1].l + nums[i].l;
			result[i].c += result[i-1].c + nums[i].c;
		} else if (i < 100) {
			int tmp = (i / 10) * 10;

			result[i].i += result[i-1].i + nums[tmp].i;
			result[i].v += result[i-1].v + nums[tmp].v;
			result[i].x += result[i-1].x + nums[tmp].x;
			result[i].l += result[i-1].l + nums[tmp].l;
			result[i].c += result[i-1].c + nums[tmp].c;
			
			if (i - tmp > 0) {
				result[i].i += nums[i-tmp].i;
				result[i].v += nums[i-tmp].v;
				result[i].x += nums[i-tmp].x;
				result[i].l += nums[i-tmp].l;
				result[i].c += nums[i-tmp].c;
			}
		} else {
			result[i].i += result[i-1].i + nums[i].i;
			result[i].v += result[i-1].v + nums[i].v;
			result[i].x += result[i-1].x + nums[i].x;
			result[i].l += result[i-1].l + nums[i].l;
			result[i].c += result[i-1].c + nums[i].c;
		}
	}

	while (cin >> n) {
		if (n == 0)
			break;

		cout << n << ": " << result[n].i << " i, " << result[n].v << " v, " << result[n].x << " x, " << result[n].l << " l, " << result[n].c << " c" << endl;
	}

	return 0;
}
