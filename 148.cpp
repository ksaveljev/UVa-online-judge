#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

vector<string> dic;
vector<string> goodwords;
map<string,int*> words;
map<string,bool> found;
vector<int*> ref;
string sorted;
vector<string> tosort;
vector<string> taken;
int sentence[26];
stringstream ss;
map<string,bool>::iterator it;

void findAnagrams(int n) {
	for (int i = n; i < goodwords.size(); i++) {
		int* temp = words[goodwords[i]];
		bool good = true;
		for (int j = 0; j < 26; j++) {
			sentence[j] -= temp[j];
			if (sentence[j] < 0) good = false;
		}
		
		if (good) {
			taken.push_back (goodwords[i]);
			
			for (int j = 0; j < 26; j++)
				if (sentence[j] > 0) good = false;
			
			if (!good) {
				findAnagrams (i+1);
			} else {
				ss.str(string());
				ss.clear();
				for (int k = 0; k < taken.size(); k++) {
					if (k > 0) ss << " ";
					ss << taken[k];
				}
				found.insert (pair<string,bool>(ss.str(), true));
			}
			
			taken.pop_back();
		}
		
		for (int j = 0; j < 26; j++) {
			sentence[j] += temp[j];
		}
	}
}

int main (void) {
	string input;
	
	while (cin >> input) {
		if (input == "#") break;
		dic.push_back (input);
		int* temp = new int[26];
		for (int i = 0; i < 26; i++)
			temp[i] = 0;
		ref.push_back (temp);
		for (int i = 0; i < input.size(); i++)
			temp[input[i] - 65] += 1;
		words.insert (pair<string,int*>(input,temp));
	}
	
	
	getline (cin,input);
	
	while (getline(cin,input)) {
		if (input == "#") break;
		
		tosort.clear();
		goodwords.clear();
		found.clear();
		taken.clear();
		ss.str(string());
		ss.clear();	
		for (int i = 0; i < 26; i++) sentence[i] = 0;

		
		
		for (int i = 0; i < input.size(); i++)
			if (input[i] >= 'A' && input[i] <= 'Z')
				sentence[input[i] - 65] += 1;
		
		
		
		ss << input;
		while (ss >> sorted) {
			tosort.push_back (sorted);
		}
		sort (tosort.begin(), tosort.end());
		ss.str(string()); ss.clear();
		for (int i = 0; i < tosort.size(); i++) {
			if (i > 0) ss << " ";
			ss << tosort[i];
		}
		sorted = ss.str();


		
		for (int i = 0; i < dic.size(); i++) {
			int* temp = words[dic[i]];
			bool good = true;
			for (int j = 0; j < 26; j++) {
				if (sentence[j] < temp[j]) {
					good = false;
					break;
				}
			}
			if (good) goodwords.push_back (dic[i]);
		}


		for (int i = 0; i < goodwords.size(); i++)
			findAnagrams(i);
		
		
		for (it = found.begin(); it != found.end(); it++) {
			if ((*it).first != sorted)
				cout << input << " = " << (*it).first << endl;
		}
	}
	
	for (int i = 0; i < ref.size(); i++)
		delete ref[i];
	
	return 0;
}