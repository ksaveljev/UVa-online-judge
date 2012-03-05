#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
    int cases, tmp, k, count;
    vector<int> cuts;
    string input;
    set<int> cuts_made;
    set<int>::const_iterator it;

    cin >> cases;

    while (cases--) {
        cin >> k;

        count = 0;
        cuts.clear();
        cuts_made.clear();

        for (int i = 0; i < k; i++) {
            cin >> tmp;
            cuts.push_back(tmp);
        }

        cin.ignore(100, '\n');

        getline(cin, input);

        for (int i = 0, sz = cuts.size(); i < sz; i++) {
            int min = 0;
            int max = input.size();

            for (it = cuts_made.begin(); it != cuts_made.end(); it++) {
                if (*it == cuts[i]) {
                    min = *it;
                    max = *it;
                    break;
                } else if (*it < cuts[i]) {
                    min = *it;
                } else if (*it > cuts[i]) {
                    max = *it;
                    break;
                }
            }

            cuts_made.insert(cuts[i]);

            set<char> a, b;
            vector<char> result;

            for (int j = min; j < cuts[i]; j++) {
                a.insert(input[j]);
            }

            for (int j = cuts[i]; j < max; j++) {
                b.insert(input[j]);
            }

            back_insert_iterator< vector<char> > bi(result);
            set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), bi);

            count += result.size();
        }

        cout << count << endl;
    }

    return 0;
}
