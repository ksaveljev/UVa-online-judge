#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    char c;
    int cases, number_of_rules, number_of_queries, n;
    string input;
    map<char,string> rules;

    cin >> cases;

    while (cases--) {
        cin >> number_of_rules;
        getline(cin, input); // \n after number_of_rules

        rules.clear();

        while (number_of_rules--) {
            c = cin.get();

            cin.get(); // -
            cin.get(); // >

            getline(cin, input);

            rules[c] = input;
        }

        cin >> number_of_queries;
        getline(cin, input); // \n after number_of_queries

        while (number_of_queries--) {
            cin >> input >> c >> n;
            unsigned long long counter[128];

            for (int i = 0; i < 128; i++)
                counter[i] = 0;

            for (int i = 0, sz = input.size(); i < sz; i++) {
                counter[input[i]]++;
            }

            vector< pair<char,unsigned long long> > all;

            while (n--) {
                all.clear();

                for (int i = 0; i < 128; i++) {
                    if (counter[i] > 0) {
                        if (rules.find(i) != rules.end()) {
                            all.push_back(make_pair(i, counter[i]));
                            counter[i] = 0;
                        }
                    }
                }

                for (int i = 0, sz = all.size(); i < sz; i++) {
                    for (int j = 0, sz2 = rules[all[i].first].size(); j < sz2; j++) {
                        counter[rules[all[i].first][j]] += all[i].second;
                    }
                }
            }

            cout << counter[c] << endl;
        }
    }

    return 0;
}
