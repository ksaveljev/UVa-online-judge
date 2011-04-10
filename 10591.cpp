#include <iostream>
#include <map>
#include <vector>
using namespace std;

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
	int n;
	int tmp;
	int next;
	int cases;
	map<int,bool> m;
	map<int,bool> visited;
	vector<int> history;

	cin >> cases;

	m[1] = true; // 1 is a happy number

	for (int y = 0; y < cases; y++) {
		cin >> n;
		tmp = n;
		visited[tmp] = true;
		while (true) {
			next = calc(tmp);
			if (m.find(next) != m.end()) {
				m[n] = m[next];
				for (int i = 0, sz = history.size(); i < sz; i++)
					m[history[i]] = m[next];
				history.clear();
				break;
			} else if (visited[next] == true) {
				m[n] = false;
				for (int i = 0, sz = history.size(); i < sz; i++)
					m[history[i]] = false;
				history.clear();
				break;
			} else {
				tmp = next;
				history.push_back(tmp);
				visited[tmp] = true;
			}
		}

		cout << "Case #" << y+1 << ": " << n << " is ";
		
		if (m[n]) {
			cout << "a Happy";
		} else {
			cout << "an Unhappy";
		}

		cout << " number." << endl;
	}

	return 0;
}
