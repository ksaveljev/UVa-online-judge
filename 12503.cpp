#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int numberOfCases, n, commandNumber;
    string command;

    cin >> numberOfCases;

    while (numberOfCases--) {
        cin >> n;

        cin.ignore(100, '\n');

        vector<int> commands;
        int position = 0;

        while (n--) {
            cin >> command;

            if (command == "LEFT") {
                commands.push_back(-1);
                position--;
            } else if (command == "RIGHT") {
                commands.push_back(1);
                position++;
            } else if (command == "SAME") {
                cin >> command; // get "AS"
                cin >> commandNumber;
                commands.push_back(commands[commandNumber-1]);
                position += commands[commandNumber-1];
            }
        }

        cout << position << endl;
    }

    return 0;
}
