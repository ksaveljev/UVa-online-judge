#include <iostream>
#include <string>
using namespace std;

int main (void) {
	string input;
	string result;
	int count = 0;
	
	while (cin >> input) {
		count++;
		if (input == "0") break;
		
		if (count == 1) { 
			result = input; 
			reverse (result.begin(), result.end());
		} else {
			reverse (input.begin(), input.end());
			if (input.size() > result.size())
				swap (input, result);
			
			int remain = 0;
			for (int i = 0; i < input.size(); i++) {
				int temp = input[i] - 48 + result[i] - 48 + remain;
				if (temp > 9) {
					remain = 1;
					temp = temp - 10;
				} else {
					remain = 0;
				}
				result[i] = temp + 48;
			}
			
			for (int i = input.size(); i < result.size(); i++) {
				int temp = result[i] - 48 + remain;
				if (temp > 9) {
					remain = 1;
					temp = temp - 10;
				} else {
					remain = 0;
				}
				result[i] = temp + 48;
			}
			
			if (remain > 0) {
				result += "1";
			}
		}
	}
	
	reverse (result.begin(), result.end());
	
	cout << result << endl;
	
	return 0;
}