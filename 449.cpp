#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

string notes[12][2] = {{"C","B#"},{"C#","Db"},{"D",""},{"D#","Eb"},{"E","Fb"},{"F","E#"},{"F#","Gb"},{"G",""},{"G#","Ab"},{"A",""},{"A#","Bb"},{"B","Cb"}};
string majorScale[12][2][7];

void split_commands(const string& commandLine, vector<string> &commands) {
    stringstream iss(commandLine);
    string command;

    while (getline(iss, command, ';')) {
        commands.push_back(command);
    }
}

void composeMajorScale() {
    int diff[] = {2,2,1,2,2,2,1};

    rep(i, 12) {
        rep(j, 2) {
            if (notes[i][j] == "" || notes[i][j][1] == '#') continue;
            int pos = i;
            
            rep(k, 7) {
                majorScale[i][j][k] = notes[pos][j];
                if (k) {
                    if (majorScale[i][j][k-1][0] == 'G' && notes[pos][j][0] != 'A')
                        majorScale[i][j][k] = notes[pos][!j];
                    if (majorScale[i][j][k-1][0] != 'G' && notes[pos][j][0] != majorScale[i][j][k-1][0]+1)
                        majorScale[i][j][k] = notes[pos][!j];
                }
                pos += diff[k];
                pos %= 12;
            }
        }
    }
}

int translate(const string& gap) {
    int result = 0;

    if (gap == "SECOND") result = 2;
    if (gap == "THIRD") result = 3;
    if (gap == "FOURTH") result = 4;
    if (gap == "FIFTH") result = 5;
    if (gap == "SIXTH") result = 6;
    if (gap == "SEVENTH") result = 7;
    if (gap == "OCTAVE") result = 8;
    
    return result;
}

int main(void) {
    string scale, commandLine;

    composeMajorScale();

    while (getline(cin, scale)) {
        getline(cin, commandLine);

        vector<string> commands;
        split_commands(commandLine, commands);

        cout << "Key of " << scale << endl;

        int x, y;
        rep (i, 12) {
            rep (j, 2) {
                if (notes[i][j] == scale)
                    x = i, y = j;
            }
        }

        rep (c, commands.size()) {
            stringstream iss(commands[c]);
            string note, direction, gap;

            while (iss >> note >> direction >> gap) {
                cout << note << ": ";

                int g = translate(gap) - 1;
                int pos = -1;

                if (direction == "DOWN")
                    g = -g;

                rep (i, 7) {
                    if (majorScale[x][y][i] == note)
                        pos = i;
                }
                if (pos == -1) {
                    cout << "invalid note for this key" << endl;
                } else {
                    cout << direction << " " << gap << " > ";
                    pos = (pos + g + 7) % 7;
                    cout << majorScale[x][y][pos] << endl;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
