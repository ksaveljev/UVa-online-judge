#include <iostream>
#include <string>
using namespace std;

int calc (string word) {
	int counter = 0;
	for (int i = 0; i < word.size(); i++) {
		word[i] = tolower(word[i]);
		if (word[i] >= 'a' && word[i] <= 'z') {
			counter += word[i] - 96;
		}
	}
	
	while (counter > 9) {
		int c = 0;
		while (counter != 0) {
			c += counter % 10;
			counter /= 10;
		}
		counter = c;
	}
	
	return counter;
}

int main (void) {
	string w1, w2;
	double res;
	
	while (getline(cin, w1)) {
		getline(cin, w2);
		
		int a = calc(w1), b = calc(w2);
		
		if (a > b) {
			res = 100.0 * b / a;
		} else {
			res = 100.0 * a / b;
		}
		
		printf("%.2f %%\n", res);
	}
	
	return 0;
}