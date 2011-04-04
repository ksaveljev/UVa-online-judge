#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector< pair<int,int> > off;

bool badWay(int x, int y) {
	for (int i = 0; i < off.size(); i++) {
		if (off[i].first == x && off[i].second == y)
			return true;
	}
	return false;
}

int main (void) {
	int x, y;
	int a, b;
	string p, moves;
	bool lost = false;
	
	cin >> x >> y;
	
	while (cin >> a >> b >> p) {
		cin >> moves;
		lost = false;
		
		for (int i = 0; i < moves.size(); i++) {
			if (moves[i] == 'R') {
				if (p == "N") p = "E";
				else if (p == "W") p = "N";
				else if (p == "E") p = "S";
				else if (p == "S") p = "W";
			} else if (moves[i] == 'L') {
				if (p == "N") p = "W";
				else if (p == "W") p = "S";
				else if (p == "E") p = "N";
				else if (p == "S") p = "E";
			} else if (moves[i] == 'F') {
				if (p == "N") {
					if (badWay(a, b) && b + 1 > y) {
						// do nothing
					} else {
						b++;
						if (b > y) {
							cout << a << " " << b - 1 << " " << p << " LOST" << endl;
							off.push_back(pair<int,int>(a, b-1));
							lost = true;
							break;
						}
					}
				} else if (p == "E") {
					if (badWay(a, b) && a + 1 > x) {
						// do nothing
					} else {
						a++;
						if (a > x) {
							cout << a - 1 << " " << b << " " << p << " LOST" << endl;
							off.push_back(pair<int,int>(a-1, b));
							lost = true;
							break;
						}
					}
				} else if (p == "S") {
					if (badWay(a, b) && b - 1 < 0) {
						// do nothing
					} else {
						b--;
						if (b < 0) {
							cout << a << " " << b + 1 << " " << p << " LOST" << endl;
							off.push_back(pair<int,int>(a, b+1));
							lost = true;
							break;
						}
					}
				} else if (p == "W") {
					if (badWay(a, b) && a - 1 < 0) {
						// do nothing
					} else {
						a--;
						if (a < 0) {
							cout << a+1 << " " << b << " " << p << " LOST" << endl;
							off.push_back(pair<int,int>(a+1, b));
							lost = true;
							break;
						}
					}
				}
			}
		}
		
		if (!lost)
			cout << a << " " << b << " " << p << endl;
	}
	
	return 0;
}