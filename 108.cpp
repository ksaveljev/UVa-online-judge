#include <iostream>
#include <limits>
using namespace std;

int main (void) {
	int n, a, b, c, d, e, res;
	int dp[101][101], input[100][100];
	
	while (cin >> n) {
		// reading input data
		for (a = 0; a < n ; a++)
			for (b = 0; b < n; b++)
				cin >> input[a][b];	
		
		// setting top row and left column to 0 (needed for dp)
		for (a = 0; a < n+1; a++) { dp[0][a] = 0; dp[a][0] = 0; }
		
		// calculating all sums using dp
		for (a = 1; a < n+1; a++)
			for (b = 1; b < n+1; b++)
				dp[a][b] = dp[a-1][b] + dp[a][b-1] - dp[a-1][b-1] + input[a-1][b-1];
		
		
		// setting result to maximum minimum
		res = INT_MIN;
		
		// brute force: N^4; just checking all possible rectangles 
		// there can be and finding their sum using dp...
		for (a = 1; a < n+1; a++)
			for (b = 1; b < n+1; b++)
				for (c = a-1; c >= 0; c--)
					for (d = b-1; d >= 0; d--)
						if (dp[a][b] + dp[c][d] - dp[a][d] - dp[c][b] > res) res = dp[a][b] + dp[c][d] - dp[a][d] - dp[c][b];

		
		cout << res << endl;
	}
	
	return 0;
}