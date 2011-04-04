#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
using namespace std;

vector<char> c;
multimap<char,char> dep;
vector<char> cur;
bool *taken;
pair<multimap<char,char>::iterator,multimap<char,char>::iterator> it;
vector<char>::iterator vit;

bool notBad (char a) {
	it = dep.equal_range(a);
	for (multimap<char,char>::iterator i = it.first; i != it.second; i++) {
		vit = find (cur.begin(), cur.end(), (*i).second);
		if (vit != cur.end())
			return false;
	}
	
	return true;
}

void doStuff(int n) {
	if (n < c.size()) {
		for (int i = 0; i < c.size(); i++) {
			if (taken[i] == false && notBad(c[i])) {
				cur.push_back(c[i]);
				taken[i] = true;
				doStuff(n+1);
				cur.pop_back();
				taken[i] = false;
			}
		}
	} else {
		for (int i = 0; i < cur.size(); i++)
			cout << cur[i];
		cout << endl;
	}
}

int main (void) {
	string input;
	int count = 0;
	
	while (getline(cin, input)) {
		count++;
		c.clear();
		dep.clear();
		
		stringstream ss, sss;
		ss << input;
		char temp, a, b;
		
		while (ss >> temp) c.push_back(temp);
		sort (c.begin(), c.end());
		
		taken = new bool[c.size()];
		for (int i = 0; i < c.size(); i++) taken[i] = false;
		
		getline(cin, input);
		
		
		sss.str("");
		sss << input;
		while (sss >> a >> b) dep.insert(pair<char,char>(a,b));
		
		if (count > 1) cout << endl;
		doStuff(0);
		
		delete taken;
	}
	
	return 0;
}