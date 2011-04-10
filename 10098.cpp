#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main (void) {
	int n;
	string input;
	char *v;
	
	cin >> n;
	
	while (n--) {
		cin >> input;
		v = new char[input.size()];
		
		for (int i = 0; i < input.size(); i++) {
			v[i] = input[i];
		}
		
		sort(v, v + input.size());
		
		do {
			for (int i = 0; i < input.size(); i++)
				printf("%c", v[i]);
			printf("\n");
		} while (next_permutation(v, v + input.size()));
		
		cout << endl;
	}

	return 0;
}
