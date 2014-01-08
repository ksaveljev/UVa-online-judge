#include <iostream>
#include <string>
#include <set>
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

set<char> possible_child_rh(char rh_p1, char rh_p2) {
    set<char> result;

    if (rh_p1 == '-' && rh_p2 == '-') {
        result.insert('-');
    } else {
        result.insert('-');
        result.insert('+');
    }

    return result;
}

set<char> possible_parent_rh(char rh_p, char rh_ch) {
    set<char> result;

    if (rh_p == '-' && rh_ch == '+') {
        result.insert('+');
    } else {
        result.insert('-');
        result.insert('+');
    }

    return result;
}

set<string> possible_parent_blood_types(string &p1, string &ch) {
    set<string> result;

    if (p1 == "A") {
        if (ch == "A") {
            result.insert("A");
            result.insert("AB");
            result.insert("B");
            result.insert("O");
        } else if (ch == "AB") {
            result.insert("AB");
            result.insert("B");
        } else if (ch == "B") {
            result.insert("AB");
            result.insert("B");
        } else if (ch == "O") {
            result.insert("B");
            result.insert("O");
            result.insert("A");
        }
    } else if (p1 == "AB") {
        if (ch == "A") {
            result.insert("A");
            result.insert("O");
            result.insert("B");
            result.insert("AB");
        } else if (ch == "AB") {
            result.insert("A");
            result.insert("B");
            result.insert("AB");
        } else if (ch == "B") {
            result.insert("A");
            result.insert("B");
            result.insert("AB");
            result.insert("O");
        } else if (ch == "O") {
            // nothing
        }
    } else if (p1 == "B") {
        if (ch == "A") {
            result.insert("A");
            result.insert("AB");
        } else if (ch == "AB") {
            result.insert("A");
            result.insert("AB");
        } else if (ch == "B") {
            result.insert("A");
            result.insert("B");
            result.insert("AB");
            result.insert("O");
        } else if (ch == "O") {
            result.insert("A");
            result.insert("B");
            result.insert("O");
        }
    } else if (p1 == "O") {
        if (ch == "A") {
            result.insert("A");
            result.insert("AB");
        } else if (ch == "AB") {
            // nothing
        } else if (ch == "B") {
            result.insert("AB");
            result.insert("B");
        } else if (ch == "O") {
            result.insert("A");
            result.insert("B");
            result.insert("O");
        }
    }

    return result;
}

set<string> possible_child_blood_types(string &p1, string &p2) {
    set<string> result;

    if (p1 == "A" && p2 == "A") {
        result.insert("A");
        result.insert("O");
    } else if (p1 == "A" && p2 == "B" || p1 == "B" && p2 == "A") {
        result.insert("A");
        result.insert("B");
        result.insert("AB");
        result.insert("O");
    } else if (p1 == "A" && p2 == "AB" || p1 == "AB" && p2 == "A") {
        result.insert("A");
        result.insert("B");
        result.insert("AB");
    } else if (p1 == "A" && p2 == "O" || p1 == "O" && p2 == "A") {
        result.insert("A");
        result.insert("O");
    } else if (p1 == "B" && p2 == "AB" || p1 == "AB" && p2 == "B") {
        result.insert("A");
        result.insert("B");
        result.insert("AB");
    } else if (p1 == "B" && p2 == "B") {
        result.insert("B");
        result.insert("O");
    } else if (p1 == "B" && p2 == "O" || p1 == "O" && p2 == "B") {
        result.insert("B");
        result.insert("O");
    } else if (p1 == "AB" && p2 == "AB") {
        result.insert("A");
        result.insert("AB");
        result.insert("B");
    } else if (p1 == "AB" && p2 == "O" || p1 == "O" && p2 == "AB") {
        result.insert("A");
        result.insert("B");
    } else if (p1 == "O" && p2 == "O") {
        result.insert("O");
    }

    return result;
}

string build_result(set<string> &bt, set<char> &rh) {
    string result;

    if (bt.empty()) {
        result = "IMPOSSIBLE";
    } else {
        if (bt.size() > 1 || rh.size() > 1) {
            set<string> all;

            result += "{";

            for (set<string>::iterator it1 = bt.begin(); it1 != bt.end(); it1++) {
                for (set<char>::iterator it2 = rh.begin(); it2 != rh.end(); it2++) {
                    all.insert(*it1 + *it2);
                }
            }

            for (set<string>::iterator it = all.begin(); it != all.end(); it++) {
                if (it != all.begin()) result += ", ";

                result += *it;
            }

            result += "}";
        } else {
            result = *bt.begin() + *rh.begin();
        }
    }

    return result;
}

int main(void) {
    string p1, p2, ch;
    int case_number = 0;

    while (cin >> p1 >> p2 >> ch) {
        if (p1 + p2 + ch == "END")
            break;

        case_number++;
        cout << "Case " << case_number << ": ";

        if (p1 == "?") {
            string parent_alleles = p2.substr(0, p2.size()-1);
            char rh_p = p2[p2.size()-1];

            string child_alleles = ch.substr(0, ch.size()-1);
            char rh_ch = ch[ch.size()-1];

            set<string> blood_types = possible_parent_blood_types(parent_alleles, child_alleles);
            set<char> rh = possible_parent_rh(rh_p, rh_ch);

            cout << build_result(blood_types, rh) << " " << p2 << " " << ch << endl;
        } else if (p2 == "?") {
            string parent_alleles = p1.substr(0, p1.size()-1);
            char rh_p = p1[p1.size()-1];

            string child_alleles = ch.substr(0, ch.size()-1);
            char rh_ch = ch[ch.size()-1];

            set<string> blood_types = possible_parent_blood_types(parent_alleles, child_alleles);
            set<char> rh = possible_parent_rh(rh_p, rh_ch);

            cout << p1 << " " << build_result(blood_types, rh) << " " << ch << endl;
        } else if (ch == "?") {
            string parent_alleles1 = p1.substr(0, p1.size()-1);
            char rh_p1 = p1[p1.size()-1];

            string parent_alleles2 = p2.substr(0, p2.size()-1);
            char rh_p2 = p2[p2.size()-1];

            set<string> blood_types = possible_child_blood_types(parent_alleles1, parent_alleles2);
            set<char> rh = possible_child_rh(rh_p1, rh_p2);

            cout << p1 << " " << p2 << " " << build_result(blood_types, rh) << endl;
        }
    }

    return 0;
}
