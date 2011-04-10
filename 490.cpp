#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void) {
	int counter = 0;
	int max_len = 0;
	char all[100][100];
	char input[100];
	
	for (int i = 0; i < 100; i++)
		memset(all[i], ' ', 100);
	
	while (cin.getline(input, 256)) {
		int len = strlen(input);
		if (len > max_len)
			max_len = len;
			
		for (int i = 0; i < len; i++) {
			all[counter][i] = input[i];
		}
		
		counter++;
	}
	
	for (int i = 0; i < max_len; i++) {
		for (int y = counter - 1; y >= 0; y--) {
			cout << all[y][i];
		}
		cout << endl;
	}
	
	return 0;
}
