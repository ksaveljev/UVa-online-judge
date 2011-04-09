#include <iostream>
#include <string>
#include <queue>
using namespace std;

char sky[100][100];
int total;

struct pos {
	int r;
	int c;
};

void remove_object(int r, int c, int max_r, int max_c) {
	pos tmp;
	tmp.r = r;
	tmp.c = c;
	sky[r][c] = '.';
	queue<pos> q;

	q.push(tmp);

	while (!q.empty()) {
		tmp = q.front();
		q.pop();

		r = tmp.r;
		c = tmp.c;

		total--;

		
		if (r > 0) {
			if (sky[r-1][c] == '*') {
				tmp.r = r-1;
				tmp.c = c;
				q.push(tmp);
				sky[tmp.r][tmp.c] = '.';
			}
		}

		if (c > 0) {
			if (sky[r][c-1] == '*') {
				tmp.r = r;
				tmp.c = c-1;
				q.push(tmp);
				sky[tmp.r][tmp.c] = '.';
			}
		}

		if (r < max_r - 1) {
			if (sky[r+1][c] == '*') {
				tmp.r = r+1;
				tmp.c = c;
				q.push(tmp);
				sky[tmp.r][tmp.c] = '.';
			}
		}

		if (c < max_c - 1) {
			if (sky[r][c+1] == '*') {
				tmp.r = r;
				tmp.c = c+1;
				q.push(tmp);
				sky[tmp.r][tmp.c] = '.';
			}
		}

		if (r > 0 && c > 0) {
			if (sky[r-1][c-1] == '*') {
				tmp.r = r-1;
				tmp.c = c-1;
				q.push(tmp);
				sky[tmp.r][tmp.c] = '.';
			}
		}

		if (r < max_r - 1 && c < max_c - 1) {
			if (sky[r+1][c+1] == '*') {
				tmp.r = r+1;
				tmp.c = c+1;
				q.push(tmp);
				sky[tmp.r][tmp.c] = '.';
			}
		}

		if (r > 0 && c < max_c - 1) {
			if (sky[r-1][c+1] == '*') {
				tmp.r = r-1;
				tmp.c = c+1;
				q.push(tmp);
				sky[tmp.r][tmp.c] = '.';
			}
		}

		if (r < max_r - 1 && c > 0) {
			if (sky[r+1][c-1] == '*') {
				tmp.r = r+1;
				tmp.c = c-1;
				q.push(tmp);
				sky[tmp.r][tmp.c] = '.';
			}
		}
	}
}

void check_star(int r, int c, int max_r, int max_c) {
	bool good_star = true;

	if (r > 0) {
		if (sky[r-1][c] == '*') {
			remove_object(r, c, max_r, max_c);
		}
	}

	if (c > 0) {
		if (sky[r][c-1] == '*') {
			remove_object(r, c, max_r, max_c);
		}
	}

	if (r < max_r - 1) {
		if (sky[r+1][c] == '*')
			remove_object(r, c, max_r, max_c);
	}

	if (c < max_c - 1) {
		if (sky[r][c+1] == '*')
			remove_object(r, c, max_r, max_c);
	}

	if (r > 0 && c > 0) {
		if (sky[r-1][c-1] == '*')
			remove_object(r, c, max_r, max_c);
	}

	if (r < max_r - 1 && c < max_c - 1) {
		if (sky[r+1][c+1] == '*')
			remove_object(r, c, max_r, max_c);
	}

	if (r > 0 && c < max_c - 1) {
		if (sky[r-1][c+1] == '*')
			remove_object(r, c, max_r, max_c);
	}

	if (r < max_r - 1 && c > 0) {
		if (sky[r+1][c-1] == '*')
			remove_object(r, c, max_r, max_c);
	}
}

int main(void) {
	int r, c;
	string input;

	while (cin >> r >> c) {
		if (r == 0 && c == 0)
			break;

		total = 0;

		for (int i = 0; i < r; i++) {
			cin >> input;
			for (int y = 0; y < c; y++) {
				sky[i][y] = input[y];
				if (input[y] == '*')
					total++;
			}
		}

		for (int i = 0; i < r; i++) {
			for (int y = 0; y < c; y++) {
				if (sky[i][y] == '*') {
					check_star(i, y, r, c);
				}
			}
		}

		cout << total << endl;
	}

	return 0;
}
