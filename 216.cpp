#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include <iomanip>
using namespace std;

vector< pair<int,int> > computers;
vector<int> taken;
vector<int> best;
bool ctaken[10];
long minimum = 1<<24;

bool theTruthIsOutThere (pair<int,int> a, pair<int,int> b) {
	if (a.first < b.first) return true;
	return false;
}

void connect(int n) {
	if (n == computers.size()) {
		long distance = 0;
		for (int i = 1; i < computers.size(); i++) {
			distance += (computers[taken[i]].first - computers[taken[i-1]].first)*(computers[taken[i]].first - computers[taken[i-1]].first) + (computers[taken[i]].second - computers[taken[i-1]].second)*(computers[taken[i]].second - computers[taken[i-1]].second);
		}
		if (distance < minimum) {
			minimum = distance;
			best.clear();
			for (int i = 0; i < computers.size(); i++)
				best.push_back (taken[i]);
		}
	} else {
		for (int i = 0; i < computers.size(); i++) {
			if (ctaken[i] == false) {
				taken.push_back (i);
				ctaken[i] = true;
				connect (n+1);
				ctaken[i] = false;
				taken.pop_back();
			}
		}
	}
}

int main (void) {
	unsigned int counter = 0;
	int n;
	int x, y;
	
	while (cin >> n) {
		if (!n) break;
		
		++counter;
		minimum = 1<<24;
		taken.clear();
		computers.clear();
		best.clear();
		memset (ctaken, false, sizeof(bool)*10);
		
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			computers.push_back (pair<int,int>(x,y));
		}
		
		sort (computers.begin(), computers.end(), theTruthIsOutThere);
		
		connect(0);
		
		cout << "**********************************************************" << endl;
		cout << "Network #" << counter << endl;
		double sum = 0, temp = 0;
		for (int i = 1; i < best.size(); i++) {
			temp = 16.0 + sqrt((computers[best[i-1]].first - computers[best[i]].first)*(computers[best[i-1]].first - computers[best[i]].first)*1.0 + (computers[best[i-1]].second - computers[best[i]].second)*(computers[best[i-1]].second - computers[best[i]].second)*1.0);
			sum += temp;
			cout << "Cable requirement to connect (" << computers[best[i-1]].first << "," << computers[best[i-1]].second << ") to (" << computers[best[i]].first << "," << computers[best[i]].second << ") is " << fixed << setprecision(2) << temp << " feet." << endl;
		}
		cout << "Number of feet of cable required is " << fixed << setprecision(2) << sum << "." << endl;
	}
	
	return 0;
}