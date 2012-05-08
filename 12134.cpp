#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

string construct_format_string(set<char> &format, set<char> &forbidden) {
    string all = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    if (format.empty()) {
        rep (i, all.size()) {
            if (forbidden.find(all[i]) == forbidden.end()) {
                format.insert(all[i]);
                break;
            }
        }
    } else if (forbidden.empty()) {
        char c = *(format.rbegin());

        rep (i, all.size()) {
            if (all[i] < c)
                format.insert(all[i]);
        }
    } else {
        char c = *(format.rbegin());

        rep (i, all.size()) {
            if (all[i] < c && forbidden.find(all[i]) == forbidden.end())
                format.insert(all[i]);
        }
    }

    string result = "";

    for (set<char>::iterator it = format.begin(); it != format.end(); it++)
        result += *it;

    return result;
}

int main(void) {
    int n, case_number = 0;
    string a, b;

    while (cin >> n) {
        if (n == 0)
            break;

        case_number++;

        bool ok = true;
        set<char> forbidden, format;

        rep (i, n) {
            cin >> a >> b;

            a = string(a.begin() + 1, a.begin() + a.size() - 1);
            b = string(b.begin() + 1, b.begin() + b.size() - 1);

            if (a.compare(0, b.size(), b) == 0) {
                rep (i, b.size()) {
                    format.insert(b[i]);
                }

                if (a.size() > b.size()) {
                    forbidden.insert(a[b.size()]);
                }
            } else {
                ok = false;
            }
        }

        vector<char> diff;
        back_insert_iterator< vector<char> > bi(diff);
        set_intersection(format.begin(), format.end(), forbidden.begin(), forbidden.end(), bi);

        if (!diff.empty())
            ok = false;


        string result = construct_format_string(format, forbidden);

        if (result.empty())
            ok = false;

        if (ok) {
            cout << "Case " << case_number << ": [" << result << "]" << endl;
        } else {
            cout << "Case " << case_number << ": I_AM_UNDONE" << endl;
        }
    }

    return 0;
}
