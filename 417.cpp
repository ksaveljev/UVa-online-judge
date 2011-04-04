#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string,int> m;
int counter = 1;

void generate(string s, int n) {
	if (s.size() == n) {
		m[s] = counter;
		counter++;
		return;
	}
	
	char last;
	if (s.size() == 0) {
		last = 'a';
	} else {
		last = s[s.size() - 1] + 1;
	}

	for (char i = last; i <= 'z'; i++) {
		generate(s + i, n);
	}
}

int main(void) {
	string input;

	for (int i = 1; i <= 5; i++)
		generate("", i);

	while (cin >> input)
		cout << m[input] << endl;

	return 0;
}
