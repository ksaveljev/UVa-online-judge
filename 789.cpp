#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main(void) {
    char c;
    int line_number = 0;
    string input;
    map< string, set<int> > m;
    set<string> words;

    getline(cin, input); // one char

    c = input[0];

    while (getline(cin, input)) {
        stringstream ss;

        for (int i = 0, sz = input.size(); i < sz; i++) {
            if (input[i] >= 'A' && input[i] <= 'Z')
                continue;

            input[i] = ' ';
        }

        ss << input;
        line_number++;

        while (ss >> input) {
            if (input[0] == c) {
                words.insert(input);

                if (m.find(input) == m.end()) {
                    set<int> s;
                    s.insert(line_number);
                    m[input] = s;
                } else {
                    m[input].insert(line_number);
                }
            }
        }
    }

    for (set<string>::iterator it1 = words.begin(); it1 != words.end(); it1++) {
        cout << *it1;

        for (set<int>::iterator it2 = m[*it1].begin(); it2 != m[*it1].end(); it2++) {
            cout << " " << *it2;
        }

        cout << endl;
    }

    return 0;
}
