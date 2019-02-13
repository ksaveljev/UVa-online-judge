#include <iostream>
#include <string>
#include <set>
using namespace std;

struct wordcmp {
    bool operator() (const string& lhs, const string& rhs) const {
        if (lhs.size() == rhs.size())
	    return lhs < rhs;
	else
	    return lhs.size() < rhs.size();
    }
};

int n;
char table[20][20];
bool visited[20][20];
set<string, wordcmp> words;

int dir[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

void add_words(int i, int j, string current_word, char last_c) {
    int ni, nj;
    if (current_word.size() >= 3) {
        words.insert(current_word);
    }

    for (int k = 0; k < 8; k++) {
        ni = i + dir[k][0];
	nj = j + dir[k][1];

	if (ni >= 0 && ni < n && nj >= 0 && nj < n && !visited[ni][nj] && table[ni][nj] > last_c) {
	    visited[ni][nj] = true;
	    add_words(ni, nj, current_word + table[ni][nj], table[ni][nj]);
	    visited[ni][nj] = false;
	}
    }
}

int main(void) {
    char c;
    bool first_output = true;
    int test_cases;

    cin >> test_cases;

    while (test_cases--) {
        cin >> n;
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        cin >> c;
		table[i][j] = c;
		visited[i][j] = false;
	    }
	}

	words.clear();

	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		visited[i][j] = true;
	        add_words(i, j, string(1, table[i][j]), table[i][j]);
		visited[i][j] = false;
	    }
	}

	if (!first_output) cout << endl;

	if (!words.empty()) {
	    for (set<string>::iterator it = words.begin(); it != words.end(); it++) {
	        cout << *it << endl;
	    }
	}

	first_output = false;
    }

    return 0;
}
