#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool theTruthIsOutThere(pair<int,int> a, pair<int,int> b) {
	if (a.second < b.second) {
		return true;
	}
	else if (a.second == b.second) {
		if (a.first > b.first)
			return true;
		else
			return false;
	} else {
		return false;
	}
}

int main (void) {
	string input;
	int counter = 0;
	
	while (getline(cin, input)) {
		if (counter++ > 0) cout << endl;
		
		map<int,int> mfreq;
		vector< pair<int,int> > vfreq;
		
		for (int i = 0; i < input.size(); i++) {
			int c = (int)input[i];
			
			if (mfreq.find(c) == mfreq.end()) {
				mfreq[c] = 1;
			} else {
				mfreq[c]++;
			}
		}
		
		for (map<int,int>::iterator it = mfreq.begin(); it != mfreq.end(); it++) {
			vfreq.push_back(pair<int,int>((*it).first, (*it).second));
		}
		
		sort (vfreq.begin(), vfreq.end(), theTruthIsOutThere);
		
		for (int i = 0; i < vfreq.size(); i++) {
			cout << vfreq[i].first << " " << vfreq[i].second << endl;
		}
	}
	
	return 0;
}