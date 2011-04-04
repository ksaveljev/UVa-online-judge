#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool theTruthIsOutThere (pair< int, pair<int,int> > a, pair< int, pair<int,int> > b) {
	if (a.second.first < b.second.first)
		return true;
	else if (a.second.first == b.second.first) {
		if (a.second.second < b.second.second)
			return true;
		else 
			return false;
	} else
		return false;
}

int main (void) {
	vector< pair< int, pair<int,int> > > elephants;
	int weight, iq, counter = 0;
	stack<int> result;
	
	while (cin >> weight >> iq) {
		elephants.push_back (pair< int, pair<int,int> >(counter, pair<int,int>(weight,iq)));
		++counter;
	}
	
	sort (elephants.begin(), elephants.end(), theTruthIsOutThere);
	
	
	int dp[elephants.size()][2];
	for (int i = 0; i < elephants.size(); i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	
	int max[2];
	max[0] = 1;
	max[1] = 0;
	for (int i = 1; i < elephants.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (elephants[i].second.first > elephants[j].second.first && elephants[i].second.second < elephants[j].second.second) {
				if (dp[j][0] + 1 > dp[i][0]) {
					dp[i][0] = dp[j][0] + 1;
					dp[i][1] = j;
					if (dp[i][0] > max[0]) { max[0] = dp[i][0]; max[1] = i; }
				}
			}
		}
	}
	
	
	cout << max[0] << endl;
	for (int i = 0; i < max[0]; i++) {
		result.push( elephants[max[1]].first );
		max[1] = dp[max[1]][1];
	}
	
	while (!result.empty()) {
		cout << result.top() + 1 << endl;
		result.pop();
	}
	
	return 0;
}