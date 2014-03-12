#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <map>
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

bool theTruthIsOutThere(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main(void) {
    char c;
    string input;
    vector<string> encoded;
    map<char,int> counter;
    map<char,char> decoded;

    for (c = 'a'; c <= 'z'; c+=1) {
        counter[c] = 0;
    }

    while (getline(cin, input)) {
        if (input == "") {
            break;
        }

        rep (i, sz(input)) {
            c = tolower(input[i]);
            if (c >= 'a' && c <= 'z') {
                counter[c] += 1;
            }
        }
    }

    vector< pair<int,int> > chars;

    for (c = 'a'; c <= 'z'; c += 1) {
        chars.push_back(make_pair(c, counter[c]));
    }

    sort (chars.begin(), chars.end(), theTruthIsOutThere);

    counter.clear();

    for (c = 'a'; c <= 'z'; c+=1) {
        counter[c] = 0;
    }

    while (getline(cin, input)) {
        encoded.push_back(input);

        rep (i, sz(input)) {
            c = tolower(input[i]);
            if (c >= 'a' && c <= 'z') {
                counter[c] += 1;
            }
        }
    }

    vector< pair<int,int> > other_chars;

    for (c = 'a'; c <= 'z'; c += 1) {
        other_chars.push_back(make_pair(c, counter[c]));
    }

    sort (other_chars.begin(), other_chars.end(), theTruthIsOutThere);

    rep (i, sz(other_chars)) {
        decoded[other_chars[i].first] = chars[i].first;
        decoded[toupper(other_chars[i].first)] = toupper(chars[i].first);
    }

    rep (i, sz(encoded)) {
        rep (j, sz(encoded[i])) {
            if (encoded[i][j] >= 'a' && encoded[i][j] <= 'z' || encoded[i][j] >= 'A' && encoded[i][j] <= 'Z') {
                cout << decoded[encoded[i][j]];
            } else {
                cout << encoded[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
