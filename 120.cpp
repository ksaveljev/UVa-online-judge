#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main (void) {
	int p[50];
	int n, a;
	string input;
	vector<int> output;
	
	while (getline(cin, input)) {
		output.clear();
		
		stringstream ss;
		ss << input;
		
		n = 0;
		while (ss >> a) {
			p[n] = a;
			n++;
		}
		
		int good = 0;
		int pos;
		while (good != n) {
			int max = p[0];
			pos = 0;
			for (int i = 0; i < n - good; i++) {
				if (p[i] > max) {
					max = p[i];
					pos = i;
				}
			}
			
			if (pos == n - 1 - good) {
				good++;
				continue;
			}
			
			if (pos == 0) {
				output.push_back(good + 1);
				reverse(p, p + (n - good));
				good++;
			} else {
				output.push_back(n - pos);
				reverse(p, p + pos + 1);
				
				output.push_back(good + 1);
				reverse(p, p + (n - good));
				
				good++;
			}
			
			bool done = true;
			for (int i = 1; i < n; i++) {
				if (p[i] < p[i-1]) {
					done = false;
					break;
				}
			}
			
			if (done)
				break;
		}
		
		cout << input << endl;
		
		int c = 0;
		for (int i = 0; i < output.size(); i++) {
			if (c > 0) cout << " ";
			cout << output[i];
			c++;
		}
		
		if (c > 0) cout << " ";
		cout << "0" << endl;
	}
	
	
	return 0;
}