#include <iostream>
#include <queue>
using namespace std;

int main (void) {
	int tbl[20][200];
	int sum[20][200];
	int x, y;
	int best[2];
	queue<int> path;
	
	while (cin >> x >> y) {
		// read the table
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++) 
				cin >> tbl[i][j];
		
		// prepare the sum array
		for (int i = 0; i < x; i++)
			sum[i][y-1] = tbl[i][y-1];
		
		// dynamic programming magic
		for (int j = y - 2; j >= 0; j--) {
			for (int i = 0; i < x; i++) {
				long a = sum[(i + x - 1) % x][j+1], b = sum[i][j+1], c = sum[(i + x + 1) % x][j+1];
				sum[i][j] = min(a, min(b, c)) + tbl[i][j];
			}
		}
		
		// find the minimum
		int min = sum[0][0];
		best[0] = 0;
		best[1] = 0;
		for (int i = 1; i < x; i++) {
			if (sum[i][0] < min) {
				min = sum[i][0];
				best[0] = i;
			}
		}
		
		// track the lexicographical path
		path.push(best[0]);
		for (int j = 1; j < y; j++) {
			long a = sum[best[0]][j-1] - tbl[best[0]][j-1];
			int m = x + 1;
			if (sum[(x + best[0] - 1) % x][j] == a) {
				if ((x + best[0] - 1) % x < m) {
					m = (x + best[0] - 1) % x;
				}
			}
			if (sum[(x + best[0] + 1) % x][j] == a) {
				if ((x + best[0] + 1) % x < m) {
					m = (x + best[0] + 1) % x;
				}
			}
			if (sum[best[0]][j] == a) {
				if (best[0] < m) {
					m = best[0];
				}
			}
			best[0] = m;
			path.push(m);
		}
		
		// print out the path and the minimum result
		int c = 0;
		while (!path.empty()) {
			if (c > 0) cout << " ";
			c++;
			cout << path.front() + 1;
			path.pop();
		}
		cout << endl << min << endl;
	}
	
	return 0;
}