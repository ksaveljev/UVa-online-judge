#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main (void) {
	int n, money, a;
	string name, friends;
	vector<string> names;
	int count = 0;
	
	while (cin >> n) {
		names.clear();
		map<string, int> group;
		for (int i = 0; i < n; i++) {
			cin >> name;
			group[name] = 0;
			names.push_back(name);
		}
		
		for (int i = 0; i < n; i++) {
			cin >> name >> money >> a;
			if (a > 0) {
				group[name] += money % a;
				group[name] -= money;
				for (int j = 0; j < a; j++) {
					cin >> friends;
					group[friends] += money / a;
				}
			}
		}
		
		if (count > 0)
			cout << endl;
		
		for (int i = 0; i < names.size(); i++) {
			cout << names[i] << " " << group[names[i]] << endl;
		}
		
		count++;
	}
	
	
	return 0;
}