#include <iostream>
#include <string>
#include <map>
using namespace std;

string nums = "2ABC3DEF4GHI5JKL6MNO7PQRS8TUV9WXYZ";

int main(void) {
	string input;
	map<char,int> m;

	int cur = 0;
	for (int i = 0, sz = nums.size(); i < sz; i++) {
		if (nums[i] >= '2' && nums[i] <= '9') {
			cur = nums[i] - '0';
		} else {
			m[nums[i]] = cur;
		}	
	}

	while (cin >> input) {
		for (int i = 0, sz = input.size(); i < sz; i++) {
			if (m.find(input[i]) == m.end()) {
				cout << input[i];
			} else {
				cout << m[input[i]];
			}
		}
		cout << endl;
	}

	return 0;
}
