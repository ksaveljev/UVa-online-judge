#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

int main (void) {
	string input;
	map<int,string> accounts;
	map<int,int> sums;
	int account;
	vector< pair<int,int> > buf;
	int n = 0;
	
	while (getline(cin, input)) {
		account = (input[0] - 48) * 100 + (input[1] - 48) * 10 + (input[2] - 48);
		if (account == 0) break;
		accounts[account] = input.substr(3);
		sums[account] = 0;
	}
	
	int last = -1;
	long count = 0;
	
	while (getline(cin, input)) {
		stringstream ss;
		long transaction, sum;
		
		account = (input[3] - 48) * 100 + (input[4] - 48) * 10 + input[5] - 48;
		transaction = (input[0] - 48) * 100 + (input[1] - 48) * 10 + input[2] - 48;
		input = input.substr(6);
		
		ss << input;
		ss >> sum;
		
		
		if (transaction == 0) break;
		
		if (last == -1)
			last = transaction;
		
		if (transaction != last) {
			if (count != 0) {
				if (n > 0) cout << endl;
				n++;
				cout << "*** Transaction " << last << " is out of balance ***" << endl;
				cout << "BUFSIZE == " << buf.size() << endl;
				for (int i = 0; i < buf.size(); i++) {
					cout << buf[i].first << " " << accounts[buf[i].first];
					for (int j = 0; j < 30 - accounts[buf[i].first].size(); j++) cout << " ";
					cout << " ";
					
					stringstream sstemp;
					string temp;
					
					if (sums[buf[i].first] < 0) {
						sstemp << "-";
						sums[buf[i].first] = -sums[buf[i].first];
					}
					
					sstemp << sums[buf[i].first] / 100 << "." << (sums[buf[i].first] % 100) / 10 << sums[buf[i].first] % 10;
					temp = sstemp.str();
					
					for (int j = 0; j < 10 - temp.size(); j++) cout << " ";
					cout << temp << endl;
					
					//cout << " " << setw(7) << sums[buf[i].first] / 100 << "." << abs((sums[buf[i].first] % 100) / 10) << abs(sums[buf[i].first] % 10) << endl;;
					//printf(" %10.2f\n", temp);
				}
				
				//double temp = count * 1.0 / 100;
				//if (temp < 0) temp = -temp;
				//temp = -temp;
				//count = -count;
				if (count < 0) count = -count;
				cout << 999 << " Out of Balance                 ";
				
				stringstream sstemp;
				string temp;
				
				if (count < 0) {
					sstemp << "-";
					count = -count;
				}
				sstemp << count / 100 << "." << (count % 100) / 10 << count % 10;
				temp = sstemp.str();
				
				for (int j = 0; j < 10 - temp.size(); j++) cout << " ";
				cout << temp << endl; 
				
				//cout << setw(7) << count / 100 << "." << abs((count % 100) / 10) << abs(count % 10) << endl;
				//printf("%10.2f\n", temp);
			}
			
			last = transaction;
			count = 0;
			for (int j = 0; j < buf.size(); j++)
				sums[buf[j].first] = 0;
			
			buf.clear();
		}
		
		count += sum;
		if (sums[account] > 0) sums[account] += sum;
		else {
			sums[account] = sum;
			buf.push_back( pair<int,int>(account, sum) );
		}
	}
	
	return 0;
}