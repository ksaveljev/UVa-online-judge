#include <iostream>
using namespace std;

int main (void) {
	char field[102][102];
	int x, y;
	char c;
	int counter = 0;
	int pos[][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
	
	while (cin >> x >> y) {
		if (x == 0 && y == 0) break;
		
		for (int i = 0; i < 102; i++)
			for (int j = 0; j < 102; j++)
				field[i][j] = '0';

		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				cin >> c;
				if (c == '*') field[i][j] = c;
			}
		}
		
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				if (field[i][j] == '*') {
					for (int k = 0; k < 8; k++) {
						if (field[i + pos[k][0]][j + pos[k][1]] != '*')
							field[i + pos[k][0]][j + pos[k][1]] += 1;
					}
				}
			}
		}
		
		if (counter > 0) cout << endl;
		++counter;
		cout << "Field #" << counter << ":" << endl;
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				cout << field[i][j];
			}
			cout << endl;
		}
	}
	
	
	return 0;
}