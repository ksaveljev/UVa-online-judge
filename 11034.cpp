#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define LEFT 1
#define RIGHT 2

int main(void) {
	int cases;
	int L, M;
	int len;
	string side;
	queue<int> left, right;

	cin >> cases;

	while (cases--) {
		cin >> L >> M;

		L *= 100;

		while (!left.empty())
			left.pop();
		while (!right.empty())
			right.pop();


		while (M--) {
			cin >> len >> side;

			if (side == "left") {
				left.push(len);
			} else if (side == "right") {
				right.push(len);
			}
		}

		int state = LEFT;
		int result = 0;
		len = 0;

		while (!left.empty() || !right.empty()) {
			result++;
			if (state == LEFT) {
				len = 0;
				while (!left.empty()) {
					if (len + left.front() > L) {
						break;
					}
					len += left.front();
					left.pop();
				}
				state = RIGHT;
			} else {
				len = 0;
				while (!right.empty()) {
					if (len + right.front() > L) {
						break;
					}
					len += right.front();
					right.pop();
				}
				state = LEFT;
			}
		}

		cout << result << endl;
	}

	return 0;
};
