#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

char **board1, **board2;
bool visited[4][4];
set<string> words1, words2;
int pos[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool is_vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

void find_words(char** board, set<string> &words, string s, int row, int col, int vowels, int consonants) {
    if (vowels > 2 || consonants > 2) {
        return;
    }
    if (vowels + consonants == 4) {
        words.insert(s);
        return;
    }

    int next_row, next_col;

    for (int i = 0; i < 8; i++) {
        next_row = row + pos[i][0];
        next_col = col + pos[i][1];

        if (next_row >= 0 && next_row < 4 && next_col >= 0 && next_col < 4 && !visited[next_row][next_col]) {
            visited[next_row][next_col] = true;
            bool b = is_vowel(board[next_row][next_col]);
            find_words(board, words, s + board[next_row][next_col], next_row, next_col, b ? vowels + 1 : vowels, b ? consonants : consonants + 1);
            visited[next_row][next_col] = false;
        }
    }
}

int main(void) {
    char c;
    bool first = true;

    board1 = new char*[4];
    board2 = new char*[4];

    for (int i = 0; i < 4; i++) {
        board1[i] = new char[4];
        board2[i] = new char[4];
    }

    while (cin >> c) {
        if (c == '#') break;

        if (!first) cout << endl;
        first = false;

        words1.clear();
        words2.clear();

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                visited[i][j] = false;

        board1[0][0] = c;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == 0 && j == 0) continue;
                cin >> board1[i][j];
            }

            for (int j = 0; j < 4; j++) {
                cin >> board2[i][j];
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                visited[i][j] = true;
                bool b = is_vowel(board1[i][j]);
                find_words(board1, words1, string(1, board1[i][j]), i, j, b ? 1 : 0, b ? 0 : 1);
                b = is_vowel(board2[i][j]);
                find_words(board2, words2, string(1, board2[i][j]), i, j, b ? 1 : 0, b ? 0 : 1);
                visited[i][j] = false;
            }
        }

        set<string> result;
        set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(), inserter(result, result.begin()));

        if (result.empty()) {
            cout << "There are no common words for this pair of boggle boards." << endl;
        } else {
            for (set<string>::iterator it = result.begin(); it != result.end(); it++) {
                cout << *it << endl;
            }
        }

    }


    return 0;
}
