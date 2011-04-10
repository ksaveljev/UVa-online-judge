#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct num {
	int happy; // 0 - unknown, 1 - happy, -1 - unhappy
	int steps;

	num() : happy(0) {}
};

int calc(int n) {
	int tmp;
	int result = 0;

	while (n > 0) {
		tmp = n % 10;
		n /= 10;
		result += tmp * tmp;
	}

	return result;
}

int main(void) {
	int next;
	int tmp;
	bool first = true;
	int s, e;
	vector<int> history;
	bool *visited = new bool[100000];
	num *numbers = new num[100000];

	memset(visited, false, sizeof(bool)*100000);

	numbers[1].happy = 1;
	numbers[1].steps = 1;
	visited[1] = true;

	for (int i = 2; i < 100000; i++) {
		tmp = i;
		while (true) {
			next = calc(tmp);
			if (numbers[next].happy != 0) { // already have data for the node
				if (numbers[next].happy == 1) { // happy number
					numbers[i].happy = 1;
					numbers[i].steps = numbers[next].steps + history.size() + 1;
					for (int y = 0, sz = history.size(); y < sz; y++) {
						numbers[history[y]].happy = 1;
						numbers[history[y]].steps = numbers[i].steps - 1 - y;
					}
					history.clear();
				} else { // unhappy number
					numbers[i].happy = -1;
					for (int y = 0, sz = history.size(); y < sz; y++) {
						numbers[history[y]].happy = -1;
					}
					history.clear();
				}
				break;
			} else if (visited[next] == true) { // we are in unhappy number loop
				numbers[i].happy = -1;
				for (int y = 0, sz = history.size(); y < sz; y++) {
					numbers[history[y]].happy = -1;
				}
				history.clear();
				break;
			} else {
				tmp = next;
				visited[tmp] = true;
				history.push_back(tmp);
			}
		}
	}

	while (cin >> s >> e) {
		if (!first)
			cout << endl;

		for (int i = s; i <= e; i++) {
			if (numbers[i].happy != 1)
				continue;

			cout << i << " " << numbers[i].steps << endl;
		}
		first = false;
	}
	
	delete [] numbers;
	delete [] visited;

	return 0;
}
