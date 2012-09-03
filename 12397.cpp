#include <iostream>
#include <string>
#include <map>
using namespace std;

string int2roman(int n) {
	string roman;
	string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	string thousands[] = {"", "M", "MM", "MMM"};

	int o = n % 10;
	n /= 10;
	int t = n % 10;
	n /= 10;
	int h = n % 10;
	n /= 10;
	int th = n % 10;

	roman += thousands[th] + hundreds[h] + tens[t] + ones[o];

	return roman;
}

int main(void) {
	int input;
	map<int,string> m;
    map<char,int> counters;

    counters['I'] = 1;
    counters['V'] = 2;
    counters['X'] = 2;
    counters['L'] = 2;
    counters['C'] = 2;
    counters['D'] = 3;
    counters['M'] = 4;

	for (int i = 1; i < 4000; i++) {
		string roman = int2roman(i);
		m[i] = roman;
	}

	while (cin >> input) {
        int result = 0;

        for (int i = 0, sz = m[input].size(); i < sz; i++) {
            result += counters[m[input][i]];
        }

        cout << result << endl;
	}

	return 0;
}
