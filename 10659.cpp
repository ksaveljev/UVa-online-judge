#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int fit_line(string &s, int x, int size) {
    int result = 1;
    string tmp;
    deque<string> q;

    istringstream iss(s);
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(q));

    int current_length = 0;

    while (!q.empty()) {
        tmp = q.front();
        q.pop_front();

        if (tmp.size() * size > x) {
            result = -1;
            break;
        }

        // try fitting the word
        if (current_length + tmp.size() * size <= x) {
            current_length += tmp.size() * size;
        } else {
            result++;
            current_length = tmp.size() * size;
        }

        // try fitting a space
        if (!q.empty()) {
            if (current_length + size <= x) {
                current_length += size;
            } else {
                result++;
                current_length = 0;
            }
        }
    }

    return result;
}

bool can_fit(vector<string> &lines, int x, int y, int size) {
    bool result = true;
    int rows = 0, number_of_rows;

    for (int i = 0, sz = lines.size(); i < sz; i++) {
        number_of_rows = fit_line(lines[i], x, size);

        if (number_of_rows == -1) {
            result = false;
            break;
        }

        rows += number_of_rows;
    }

    if (result) {
        result = rows * size <= y;
    }

    return result;
}

int main(void) {
    int n, m, x, y;
    string input;
    vector<string> lines;

    cin >> n;

    while (n--) {
        cin >> m;
        cin.ignore(100, '\n');

        lines.clear();

        while (m--) {
            getline(cin, input);
            lines.push_back(input);
        }

        cin >> x >> y;

        int result = -1;

        for (int i = 8; i < 29; i++) {
            if (can_fit(lines, x, y, i)) {
                result = i;
            } else {
                break;
            }
        }

        if (result == -1) {
            cout << "No solution" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
