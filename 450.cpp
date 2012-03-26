#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

class person_data {
    string data;

public:

    friend istream &operator>>(istream &is, person_data &p) {
        getline(is, p.data, ',');
        return is;
    }

    operator string() const { return data; }
};

bool theTruthIsOutThere(const vector<string> &a, const vector<string> &b) {
    return a[2] < b[2];
}

void print_person_data(vector<string> &p) {
    cout << "----------------------------------------" << endl;
    cout << p[0] << " " << p[1] << " " << p[2] << endl;
    cout << p[3] << endl;
    cout << "Department: " << p[7] << endl;
    cout << "Home Phone: " << p[4] << endl;;
    cout << "Work Phone: " << p[5] << endl;
    cout << "Campus Box: " << p[6] << endl;
}

int main(void) {
    int n;
    string department, tmp;
    vector< vector<string> > people;

    cin >> n;
    cin.ignore(100, '\n');

    while (n--) {
        getline(cin, department);

        while (getline(cin, tmp)) {
            if (tmp.empty()) {
                break;
            }

            vector<string> v;
            istringstream iss(tmp);
            copy(istream_iterator<person_data>(iss), istream_iterator<person_data>(), back_inserter(v));

            v.push_back(department);
            people.push_back(v);
        }
    }

    sort (people.begin(), people.end(), theTruthIsOutThere);

    rep (i, people.size()) {
        print_person_data(people[i]);
    }

    return 0;
}
