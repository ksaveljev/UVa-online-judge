#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main (void) {
	int n;
	map<int,int> occurance;
	map<int,int>::iterator it;
	vector<int> filter;
	
	while (cin >> n) {
		it = occurance.find (n);
		if (it == occurance.end()) {
			filter.push_back(n);
			occurance.insert(pair<int,int>(n,1));
		} else {
			it->second += 1;
		}
	}
	
	for (int i = 0; i < filter.size(); i++) {
		cout << filter[i] << " " << occurance[filter[i]] << endl;
	}
	
	return 0;
}