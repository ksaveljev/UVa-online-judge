#include <bits/stdc++.h>
using namespace std;

int main () {
	int *tbl;
	tbl = (int*)malloc(sizeof(int)*1000000);

	tbl[1] = 1;

	for (int i = 2; i < 1000000; i++)
    {
		int temp = i;
		int counter = 1;
		while (temp > 1)
		{
			if (temp < 1000000 && tbl[temp] > 0)
            {
				counter += tbl[temp] - 1;
				break;
            }
			counter++;
			if (temp % 2 == 0)
				temp /= 2;
			else
				temp = temp * 3 + 1;
		}
		tbl[i] = counter;
	}

	int a, b;

	while (cin >> a >> b)
	{
		cout << a << " " << b << " ";
		if (a > b)
            swap(a,b);
		int maks = 0;
		for (int i = a; i <= b; i++)
            max(maks, tbl[i]);
		cout << maks << endl;
	}
	free(tbl);
	return 0;
}
