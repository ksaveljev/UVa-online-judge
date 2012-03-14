#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int accounts[21];

void solve(int n, vector<string> &names) {
    int i, j;

    while (true) {
        for (i = 0; i < n; i++)
            if (accounts[i] > 0)
                break;

        for (j = 0; j < n; j++)
            if (accounts[j] < 0)
                break;

        if (i == n && j == n)
            break;

        int tmp = accounts[i] < (-accounts[j]) ? accounts[i] : (-accounts[j]);

        accounts[i] -= tmp;
        accounts[j] += tmp;

        cout << names[i] << " " << names[j] << " " << tmp << endl;
    }
}

int main(void) {
    int n, t, amount, case_num = 0;
    string input, a, b;
    map<string,int> people;
    vector<string> names;

    while (cin >> n >> t) {
        if (n == 0 && t == 0)
            break;

        case_num++;
        people.clear();
        names.clear();

        for (int i = 0; i < n; i++) {
            cin >> input;
            names.push_back(input);
            people[input] = i;
        }

        for (int i = 0; i < t; i++) {
            cin >> a >> b >> amount;

            if (people.find(a) != people.end () && people.find(b) != people.end()) {
                accounts[people[a]] -= amount;
                accounts[people[b]] += amount;
            }
        }

        cout << "Case #" << case_num << endl;
        solve(n, names);
        cout << endl;
    }

    return 0;
}
