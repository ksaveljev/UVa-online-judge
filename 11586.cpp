#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;

int main(void) {
    int n;
    string input;

    cin >> n;
    cin.ignore(100, '\n');

    while (n--) {
        getline(cin, input);

        vector<string> pieces;

        istringstream iss(input);
        copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(pieces));

        int sz = pieces.size();
        bool taken[sz];

        if (sz == 1) {
            cout << "NO LOOP" << endl;
            continue;
        }

        for (int i = 0; i < sz; i++)
            taken[i] = false;

        taken[0] = true;
        char first = pieces[0][0], last = pieces[0][1];
        int count = 1;

        while (true) {
            bool action_taken = false;

            for (int i = 0; i < sz; i++) {
                if (taken[i])
                    continue;

                if (pieces[i][0] == 'F' && last == 'M' || pieces[i][0] == 'M' && last == 'F') {
                    taken[i] = true;
                    action_taken = true;
                    last = pieces[i][1];
                    count++;
                }
            }

            if (!action_taken)
                break;
        }

        bool result = true;

        if (count != sz || first == last)
            result = false;

        if (result)
            cout << "LOOP" << endl;
        else
            cout << "NO LOOP" << endl;
    }

    return 0;
}
