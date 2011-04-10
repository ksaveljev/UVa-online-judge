#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> forbidden;
vector<int> generated;
vector<int>::iterator it;
map<int,bool> taken;

void generate (int start) {
	int a,b,c,d;
	
	d = start % 10;
	start /= 10;
	c = start % 10;
	start /= 10;
	b = start % 10;
	start /= 10;
	a = start;
	
	generated.push_back ((a + 1 > 9 ? 0 : a + 1) * 1000 + b * 100 + c * 10 + d);
	generated.push_back ((a - 1 < 0 ? 9 : a - 1) * 1000 + b * 100 + c * 10 + d);
	generated.push_back (a * 1000 + (b + 1 > 9 ? 0 : b + 1) * 100 + c * 10 + d);
	generated.push_back (a * 1000 + (b - 1 < 0 ? 9 : b - 1) * 100 + c * 10 + d);
	generated.push_back (a * 1000 + b * 100 + (c + 1 > 9 ? 0 : c + 1) * 10 + d);
	generated.push_back (a * 1000 + b * 100 + (c - 1 < 0 ? 9 : c - 1) * 10 + d);
	generated.push_back (a * 1000 + b * 100 + c * 10 + (d + 1 > 9 ? 0 : d + 1));
	generated.push_back (a * 1000 + b * 100 + c * 10 + (d - 1 < 0 ? 9 : d - 1));
}

int BFS (int start, int end) {
	queue< pair<int,int> > Q;
	pair<int,int> P;
	
	if (start == end)
		return 0;
	
	Q.push (pair<int,int> (start, 0));
	taken[start] = true;
	
	while (!Q.empty()) {
		P = Q.front();
		Q.pop();
		
		generate (P.first);
		
		for (int i = 0; i < generated.size(); i++) {
			if (generated[i] == end) {
				return P.second + 1;
			} else if (taken.find (generated[i]) != taken.end()) {
				continue;
			}
			
			it = find (forbidden.begin(), forbidden.end(), generated[i]);
			if (it == forbidden.end()) {
				Q.push (pair<int,int> (generated[i], P.second + 1));
				taken[generated[i]] = true;
			}
		}
		
		generated.clear();
	}
	
	return -1;
}

int main (void) {
	int cases, n;
	int a,b,c,d;
	int start, end, f;
	
	cin >> cases;
	
	while (cases--) {
		forbidden.clear();
		generated.clear();
		taken.clear();
		
		cin >> a >> b >> c >> d;
		start = a * 1000 + b * 100 + c * 10 + d;
		
		cin >> a >> b >> c >> d;
		end = a * 1000 + b * 100 + c * 10 + d;
		
		cin >> n;
		while (n--) {
			cin >> a >> b >> c >> d;
			f = a * 1000 + b * 100 + c * 10 + d;
			forbidden.push_back (f);
		}

		cout << BFS(start, end) << endl;
	}
	
	return 0;
}
