#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

int num_length (int num) {
	if (num == 0) return 1;
	return log10(num) + 1;
}

int main (void) {
	vector<int> squares;
	vector< pair<int,int> > results[4];
	int max = 100000000;
	
	int num = 0;
	int i = pow(num,2);
	while (i < max) {
		squares.push_back(i);
		++num;
		i = pow(num,2);
	}
	
	
	for (int j = 0; j < squares.size(); j++) {
		int a, b;
		if (squares[j] < 100) {
			a = squares[j] / 10;
			b = squares[j] % 10;
			if ((a+b)*(a+b) == squares[j]) {
				results[0].push_back(pair<int,int>(a,b));
			}
		} 
		if (squares[j] < 10000) {
			a = squares[j] / 100;
			b = squares[j] % 100;
			if ((a+b)*(a+b) == squares[j]) {
				results[1].push_back(pair<int,int>(a,b));
			}
		}
		if (squares[j] < 1000000) {
			a = squares[j] / 1000;
			b = squares[j] % 1000;
			if ((a+b)*(a+b) == squares[j]) {
				results[2].push_back(pair<int,int>(a,b));
			}
		}
		
		a = squares[j] / 10000;
		b = squares[j] % 10000;
		if ((a+b)*(a+b) == squares[j]) {
			results[3].push_back(pair<int,int>(a,b));
		}
	}
	
	
	int n;
	while (cin >> n) {
		for (int j = 0; j < results[n/2-1].size(); j++) {
			for (int k = 0; k < n/2 - num_length(results[n/2-1][j].first); k++) cout << 0;
			cout << results[n/2-1][j].first;
			for (int k = 0; k < n/2 - num_length(results[n/2-1][j].second); k++) cout << 0;
			cout << results[n/2-1][j].second << endl;
		}
	}
	
	
	return 0;
}