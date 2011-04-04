#include <iostream>
#include <string>
using namespace std;

char field[3][3];

int count(char c) {
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			if (field[i][y] == c)
				counter++;
		}
	}
	return counter;
}

bool find_win(char c){
	bool won = false;

	for (int i = 0; i < 3; i++) {
		bool tmp = true;
		for (int y = 0; y < 3; y++) {
			if (field[i][y] != c) {
				tmp = false;
				break;
			}
		}
		if (tmp)
			won = true;

		tmp = true;
		for (int y = 0; y < 3; y++) {
			if (field[y][i] != c) {
				tmp = false;
				break;
			}
		}
		if (tmp)
			won = true;
	}

	if (field[0][0] == c && field[1][1] == c && field[2][2] == c)
		won = true;
	
	if (field[0][2] == c && field[1][1] == c && field[2][0] == c)
		won = true;

	return won;
}

int main(void) {
	int n;
	string input;

	cin >> n;

	while (n--) {
		for (int i = 0; i < 3; i++) {
			cin >> input;
			for (int y = 0, sz = input.size(); y < sz; y++) {
				field[i][y] = input[y];
			}
		}

		int x = count('X');
		int o = count('O');

		bool valid = true;

		if (x - o == 0 || x - o == 1) {
			bool x_won = find_win('X');
			bool o_won = find_win('O');
			if (x_won && o_won) {
				valid = false;
			}
			if (x_won && x == o)
				valid = false;
			if (o_won && x - o == 1)
				valid = false;
		} else {
			valid = false;
		}


		if (valid)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}
