#include <iostream>
#include <string>
using namespace std;

int s;
string n;

string nums[5] =
{" -     -  -     -  -  -  -  - ",
 "| |  |  |  || ||  |    || || |",
 "       -  -  -  -  -     -  - ",
 "| |  ||    |  |  || |  || |  |",
 " -     -  -     -  -     -  - "};

void print_level(int level) {
	int num;
	for (int i = 0, sz = n.size(); i < sz; i++) {
		num = n[i] - '0';
		
		for (int y = 0; y < 3; y++) {
			if (level % 2 == 0) {
				if (y % 2 == 0) {
					cout << nums[level][3 * num + y];
				} else {
					for (int z = 0; z < s; z++)
						cout << nums[level][3 * num + y];
				}
			} else {
				if (y % 2 == 0) {
					cout << nums[level][3 * num + y];
				} else {
					for (int z = 0; z < s; z++)
						cout << nums[level][3 * num + y];
				}
			}
		}


		// there has to be exactly one column of blanks between two digits.
		if (i < sz - 1)
			cout << " ";
	}
	cout << endl;
}

int main(void) {
	while (cin >> s >> n) {
		if (s == 0 && n == "0")
			break;

		// for each level of string nums[5]
		for (int i = 0; i < 5; i++) {
			if (i % 2 == 0) {
				print_level(i);
			} else {
				for (int y = 0; y < s; y++)
					print_level(i);
			}
		}
		
		cout << endl;
	}

	return 0;
}
