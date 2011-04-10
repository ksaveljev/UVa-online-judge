#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main(void) {
	int step, mod;

	while (cin >> step >> mod) {
		printf("%10d%10d", step, mod);
		if (gcd(step, mod) == 1) {
			printf("    Good Choice\n\n");
		} else {
			printf("    Bad Choice\n\n");
		}
	}

	return 0;
}
