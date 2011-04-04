#include <iostream>
#include <string>
using namespace std;

struct winner {
	string name;
	double price;
	int match;
	winner() : name(""), price(0.0), match(-1) {}
};

int main(void) {
	int n, p, match;
	double price;
	int counter = 0;
	string input, name;

	while (cin >> n >> p) {
		if (n == 0 && p == 0)
			break;

		if (counter > 0)
			cout << endl;
		counter++;

		winner best;

		getline(cin, input); // \n
		while (n--)
			getline(cin, input);

		while (p--) {
			getline(cin, name);
			cin >> price >> match;
			getline(cin, input); // \n
			for (int i = 0; i < match; i++)
				getline(cin, input);

			if (match > best.match) {
				best.name = name;
				best.price = price;
				best.match = match;
			} else if (match == best.match) {
				if (price < best.price) {
					best.name = name;
					best.price = price;
					best.match = match;
				}
			}
		}

		cout << "RFP #" << counter << endl;
		cout << best.name << endl;
	}

	return 0;
}
