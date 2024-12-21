#include <iostream>
#include <cstring>
using namespace std;

using ll = long long;

ll product[3][3];
ll tmp[3][3];

using ll = long long;

const int mod = 1e9 + 9;

int main(void) {
    ll n;

    while (cin >> n) {
	if (n == 0) break;

	//      [0]        [0]        [0]    [1 * Tn-1 + 1 * Tn-2 + 1 * Tn-3]           [1 1 1]
	// Tn-1 [0] + Tn-2 [0] + Tn-3 [0] =  [1 * Tn-1 + 0 * Tn-2 + 0 * Tn-3]  =>  M =  [1 0 0]
	//      [0]        [0]        [0] =  [0 * Tn-1 + 1 * Tn-2 + 0 * Tn-3]           [0 1 0]
	
	ll trib[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
	memset(product, 0, sizeof(product));
	for (int i = 0; i < 3; i++)
	    product[i][i] = 1;

	n--;
	while (n > 0) {
	    if (n & 1) {
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < 3; i++)
		    for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
			    tmp[i][k] = (tmp[i][k] + product[i][j] * trib[j][k]) % mod;

		for (int i = 0; i < 3; i++)
		    for (int j = 0; j < 3; j++)
			product[i][j] = tmp[i][j];
	    }

	    memset(tmp, 0, sizeof(tmp));
	    for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		    for (int k = 0; k < 3; k++)
			tmp[i][k] = (tmp[i][k] + trib[i][j] * trib[j][k]) % mod;

	    for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		    trib[i][j] = tmp[i][j];

	    n /= 2;
	}

	//           [2]       p[0][0]       p[0][1]       p[0][2]
	// product * [1] = 2 * p[1][0] + 1 * p[1][1] + 0 * p[1][2]
	//           [0]       p[2][0]       p[2][1]       p[2][2]
	
	cout << (2 * product[2][0] + product[2][1]) % mod << '\n';
    } 

    return 0;
}
