#include <iostream>
#include <cstring>
using namespace std;

using ll = long long;

int main(void) {
    int n, m;

    while (cin >> n >> m) {
	int mod = 1 << m;
	
	ll product[2][2] = {{1, 0}, {0, 1}};
	ll fib[2][2] = {{1, 1}, {1, 0}};
	ll tmp[2][2];

	while (n) {
	    if (n & 1) {
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < 2; i++)
		    for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
			    tmp[i][k] = (tmp[i][k] + product[i][j] * fib[j][k]) % mod;

		for (int i = 0; i < 2; i++)
		    for (int j = 0; j < 2; j++)
			product[i][j] = tmp[i][j];
	    }

	    memset(tmp, 0, sizeof(tmp));
	    for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		    for (int k = 0; k < 2; k++)
			tmp[i][k] = (tmp[i][k] + fib[i][j] * fib[j][k]) % mod;

	    for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		    fib[i][j] = tmp[i][j];

	    n /= 2;

	}

	cout << product[0][1] << endl;
    }

    return 0;
}
