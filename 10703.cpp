#include <iostream>
#include <algorithm>
using namespace std;

void clear_board(char** board) {
	for (int i = 0; i < 500; i++)
		for (int y = 0; y < 500; y++)
			board[i][y] = ' ';
}

int main(void) {
	int w, h, n;
	int x1, y1, x2, y2;
	char** board;
	char c;

	board = new char*[500];
	for (int i = 0; i < 500; i++)
		board[i] = new char[500];
	
	
	while (cin >> w >> h >> n) {
		if (w == 0 && h == 0 && n == 0)
			break;

		clear_board(board);
		cin.get(c); // \n

		while (cin.peek() != '\n') {
			cin >> x1 >> y1 >> x2 >> y2;
			x1--;
			y1--;
			x2--;
			y2--;
			if (x1 > x2) {
				swap(x1, x2);
				swap(y1, y2);
			}

			if (y1 > y2) {
				int tmpx1 = x1;
				int tmpy1 = y2;
				int tmpx2 = x2;
				int tmpy2 = y1;
				x1 = tmpx1;
				x2 = tmpx2;
				y1 = tmpy1;
				y2 = tmpy2;
			}

			for (int i = x1; i <= x2; i++) {
				for (int y = y1; y <= y2; y++) {
					board[i][y] = 'x';
				}
			}
			cin.get(c); // \n
		}

		int result = 0;

		for (int i = 0; i < w; i++) {
			for (int y = 0; y < h; y++) {
				if (board[i][y] == ' ')
					result++;
			}
		}

		if (result == 0)
			cout << "There is no empty spots." << endl;
		else if (result == 1)
			cout << "There is one empty spot." << endl;
		else
			cout << "There are " << result << " empty spots." << endl;
	}

	
	for (int i = 0; i < 500; i++)
		delete [] board[i];
	
	delete [] board;

	return 0;
}
