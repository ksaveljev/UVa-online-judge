#include <iostream>
#include <string>
#include <vector>
#include <map>
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

bool is_dna(string s) {
    return s == "A" || s == "B" || s == "C" || s == "D";
}

bool theTruthIsOutThere(const pair<string,string> &a, const pair<string,string> &b) {
    return a.first < b.first;
}

int main(void) {
    int n;
    bool first = true;
    string input;

    while (cin >> n) {
        if (first) first = false; else cout << endl;

        map<string,string> assignments;
        vector<string> first, second;

        rep (i, n) {
            cin >> input;
            first.push_back(input);
        }

        rep (i, n) {
            cin >> input;
            second.push_back(input);
        }

        bool ok = true;

        while (true) {
            bool changed = false;

            rep (i, n) {
                bool dna1 = is_dna(first[i]);
                bool dna2 = is_dna(second[i]);

                if (dna1 && dna2) {
                    if (first[i] != second[i]) {
                        ok = false;
                        break;
                    }
                } else if (!dna1 && dna2) {
                    if (assignments.find(first[i]) == assignments.end()) {
                        assignments[first[i]] = second[i];
                        changed = true;
                    } else {
                        if (assignments[first[i]] != second[i]) {
                            ok = false;
                            break;
                        }
                    }
                } else if (dna1 && !dna2) {
                    if (assignments.find(second[i]) == assignments.end()) {
                        assignments[second[i]] = first[i];
                        changed = true;
                    } else {
                        if (assignments[second[i]] != first[i]) {
                            ok = false;
                            break;
                        }
                    }
                } else if (!dna1 && !dna2) {
                    if (first[i] != second[i]) {
                        if (assignments.find(first[i]) == assignments.end() && assignments.find(second[i]) != assignments.end()) {
                            assignments[first[i]] = assignments[second[i]];
                            changed = true;
                        } else if (assignments.find(first[i]) != assignments.end() && assignments.find(second[i]) == assignments.end()) {
                            assignments[second[i]] = assignments[first[i]];
                            changed = true;
                        } else if (assignments.find(first[i]) != assignments.end() && assignments.find(second[i]) != assignments.end()) {
                            if (assignments[first[i]] != assignments[second[i]]) {
                                ok = false;
                                break;
                            }
                        }
                    }
                }
            }

            if (!changed) break;
        }

        if (ok) {
            vector< pair<string, string> > result;

            for (map<string,string>::iterator it = assignments.begin(); it != assignments.end(); it++) {
                result.push_back(make_pair(it->first, it->second));
            }

            sort(result.begin(), result.end(), theTruthIsOutThere);

            cout << "YES" << endl;
            
            rep (i, result.size()) {
                cout << result[i].first << " " << result[i].second << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
