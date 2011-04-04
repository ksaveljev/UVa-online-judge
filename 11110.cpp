#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

int n;
int sq[100][100];
bool visited[100][100];

bool check(int c) {
	for (int i = 0; i < n; i++) {
		for (int y = 0; y < n; y++) {
			if (sq[i][y] == c)
				return false;
		}
	}
	return true;
}

void fill(int a, int b, int c) {
	pair<int,int> p;
	queue< pair<int,int> > q;

	p = make_pair(a, b);
	q.push(p);

	while (!q.empty()) {
		p = q.front();
		q.pop();

		sq[p.first][p.second] = 0;

		if (p.first - 1 >= 0) {
			if (sq[p.first - 1][p.second] == c && visited[p.first-1][p.second] == false) {
				q.push(make_pair(p.first-1, p.second));
				visited[p.first-1][p.second] = true;
			}
		}

		if (p.second - 1 >= 0) {
			if (sq[p.first][p.second - 1] == c && visited[p.first][p.second-1] == false) {
				q.push(make_pair(p.first, p.second - 1));
				visited[p.first][p.second - 1] = true;
			}
		}

		if (p.first + 1 < n) {
			if (sq[p.first + 1][p.second] == c && visited[p.first+1][p.second] == false)	{
				q.push(make_pair(p.first + 1, p.second));
				visited[p.first + 1][p.second] = true;
			}
		}

		if (p.second + 1 < n) {
			if (sq[p.first][p.second + 1] == c && visited[p.first][p.second+1] == false) {
				q.push(make_pair(p.first, p.second + 1));
				visited[p.first][p.second + 1] = true;
			}
		}
	}
}

int main(void) {
	int x, y;
	string input;

	while (cin >> n) {
		if (n == 0)
			break;

		for (int i = 0; i < n; i++) {
			for (int y = 0; y < n; y++) {
				sq[i][y] = 0;
				visited[i][y] = false;
			}
		}

		int cur = 1;

		getline(cin, input); // \n

		for (int i = 0; i < n - 1; i++) {
			getline(cin, input);
			stringstream ss;
			ss << input;

			while (ss >> x >> y) {
				sq[x-1][y-1] = cur;
			}
			cur++;
		}

		for (int i = 0; i < n; i++) {
			for (int y = 0; y < n; y++) {
				if (sq[i][y] == 0)
					sq[i][y] = cur;
			}
		}

		bool ok = true;

		for (int i = 1; i <= cur; i++) {
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n; b++) {
					if (sq[a][b] == i) {
						fill(a, b, i);
						b = n;
						a = n;
					}
				}
			}
			if (!check(i)) {
				ok = false;
				break;
			}
		}

		if (ok)
			cout << "good" << endl;
		else
			cout << "wrong" << endl;
	}

	return 0;
}
