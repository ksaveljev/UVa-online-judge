#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

// no Q for playfair cipher
string alphabet = "ABCDEFGHIJKLMNOPRSTUVWXYZ";

string strip_input(string &input) {
    string result = "";

    rep (i, input.size()) {
        if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')
            result += input[i];
    }

    return result;
}

string encode(string &input, map< char, pair<int,int> > m, char field[5][5]) {
    int index = 0, sz = input.size();
    string result = "";
    pair<int,int> pos1, pos2;
    char c1, c2;

    while (true) {
        if (sz - index >= 2) {
            c1 = input[index];
            c2 = input[index+1];

            pos1 = m[c1];

            if (c1 == c2) {
                c2 = 'X';
                index++;
            } else {
                index += 2;
            }

            pos2 = m[c2];
        } else if (sz - index == 1) {
            c1 = input[index];
            c2 = 'X';

            pos1 = m[c1];
            pos2 = m[c2];

            index += 2;
        } else {
            break;
        }

        if (pos1.first == pos2.first) {
            pos1.second++;
            pos2.second++;

            if (pos1.second == 5)
                pos1.second = 0;
            
            if (pos2.second == 5)
                pos2.second = 0;
        } else if (pos1.second == pos2.second) {
            pos1.first++;
            pos2.first++;

            if (pos1.first == 5)
                pos1.first = 0;
            
            if (pos2.first == 5)
                pos2.first = 0;
        } else {
            swap (pos1.second, pos2.second);
        }

        result += field[pos1.first][pos1.second];
        result += field[pos2.first][pos2.second];
    }

    return result;
}

int main(void) {
    char field[5][5];
    int number_of_cases;
    string key_phrase, input;

    cin >> number_of_cases;
    cin.ignore(100, '\n');

    while (number_of_cases--) {
        getline (cin, key_phrase);
        getline (cin, input);

        input = strip_input(input);
        key_phrase = strip_input(key_phrase);

        transform (key_phrase.begin(), key_phrase.end(), key_phrase.begin(), ::toupper);
        transform (input.begin(), input.end(), input.begin(), ::toupper);

        map< char, pair<int,int> > m;
        key_phrase += alphabet;

        int row = 0;
        int col = 0;

        rep (i, key_phrase.size()) {
            if (m.find(key_phrase[i]) == m.end()) {
                field[row][col] = key_phrase[i];
                m[key_phrase[i]] = make_pair(row, col);
                col++;

                if (col == 5) {
                    col = 0;
                    row++;
                }
            }
        }

        cout << encode(input, m, field) << endl;
    }

    return 0;
}
