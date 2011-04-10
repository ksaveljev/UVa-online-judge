#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef pair<int,int> ipair;

int cases, m, n, k;
char buf[50][50];
map<string,ipair> words;

void add_word(string &str, int row, int col) {
	if (words.find(str) == words.end()) {
		words[str] = pair<int,int>(row, col);
	}
}

void add_words(int row, int col) {
	string current_word = "";
	// going up
	for (int i = row; i >= 0; i--) {
		current_word += buf[i][col];
		add_word(current_word, row, col);
	}
	
	current_word = "";
	// going up right
	for (int i = row, y = col; i >= 0 && y < n; i--, y++) {
		current_word += buf[i][y];
		add_word(current_word, row, col);
	}
	
	current_word = "";
	// going right
	for (int i = col; i < n; i++) {
		current_word += buf[row][i];
		add_word(current_word, row, col);
	}
	
	current_word = "";
	// going down right
	for (int i = row, y = col; i < m && y < n; i++, y++) {
		current_word += buf[i][y];
		add_word(current_word, row, col);
	}
	
	current_word = "";
	// going down
	for (int i = row; i < m; i++) {
		current_word += buf[i][col];
		add_word(current_word, row, col);
	}
	
	current_word = "";
	// going down left
	for (int i = row, y = col; i < m && y >= 0; i++, y--) {
		current_word += buf[i][y];
		add_word(current_word, row, col);
	}
	
	current_word = "";
	// going left
	for (int i = col; i >= 0; i--) {
		current_word += buf[row][i];
		add_word(current_word, row, col);
	}
	
	current_word = "";
	// going up left
	for (int i = row, y = col; i >= 0 && y >= 0; i--, y--) {
		current_word += buf[i][y];
		add_word(current_word, row, col);
	}
}

void precalculate() {
	for (int i = 0; i < m; i++)
		for (int y = 0; y < n; y++)
			add_words(i, y);
}

int main(void) {
	string input;
	
	cin >> cases;
	
	while (cases--) {
		cin >> m >> n;
		
		words.clear();
		
		for (int i = 0; i < m; i++) {
			cin >> input;
			for (int y = 0; y < n; y++)
				buf[i][y] = tolower(input[y]);
		}
		
		
		precalculate();
		
		
		cin >> k;
		
		while (k--) {
			cin >> input;
			
			for (int i = 0, sz = input.size(); i < sz; i++)
				input[i] = tolower(input[i]);
			
			ipair result = words[input];
			cout << result.first + 1 << " " << result.second + 1 << endl;
		}
		
		if (cases)
			cout << endl;
	}	
	
	return 0;
}
