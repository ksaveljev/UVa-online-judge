#include <iostream>
using namespace std;

int endian_swap(int i) {
	return((i&0xff)<<24)+((i&0xff00)<<8)+((i&0xff0000)>>8)+((i>>24)&0xff);
}

int main(void) {
	int n;

	while (cin >> n) {
		cout << n << " converts to " << endian_swap(n) << endl;
	}

	return 0;
}
