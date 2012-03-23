#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

bool good_widths(vector<int> readings, double separator) {
    int lowest = 201, highest = 0;

    rep (i, readings.size()) {
        if (readings[i] < separator) {
            readings[i] *= 2;
        }

        if (readings[i] < lowest)
            lowest = readings[i];

        if (readings[i] > highest)
            highest = readings[i];
    }

    return lowest >= 95.0 * highest / 105.0;
}

int map_to_character(int number) {
    int result = -1;
    int encoded[] = { 0b00001, 0b10001, 0b01001, 0b11000, 0b00101, 0b10100, 0b01100, 0b00011, 0b10010, 0b10000, 0b00100, 0b00110 };

    rep (i, 12) {
        if (number == encoded[i]) {
            result = i;
            break;
        }
    }

    return result;
}

int decode(vector<int> &readings, int pos, double separator) {
    int num = 0;

    for (int i = pos; i < pos + 5; i++) {
        if (readings[i] < separator) {
            num <<= 1;
        } else {
            num = (num << 1) + 1;
        }
    }

    return map_to_character(num);
}

bool transform(vector<int> &readings, double separator, vector<int> &transformed) {
    int start_stop_count = 0;

    for (int i = 0, sz = readings.size(); i < sz; i += 6) {
        int character = decode(readings, i, separator);

        if (character == -1)
            return false;

        if (character == 11) {
            start_stop_count++;
        }

        transformed.push_back(character);

        // separator bar should be narrow
        if (i+5 < readings.size() && readings[i+5] >= separator) {
            return false;
        }
    }

    return start_stop_count == 2 && transformed[0] == 11 && transformed[transformed.size()-1] == 11;
}

bool checkC(vector<int> &transformed, int c) {
    int expected = 0;
    int n = transformed.size() - 4;

    for (int i = 1, sz = transformed.size() - 3; i < sz; i++) {
        expected += ((n - i) % 10 + 1) * transformed[i];
    }

    return expected % 11 == c;
}

bool checkK(vector<int> &transformed, int c, int k) {
    int expected = 0;
    int n = transformed.size() - 4;

    for (int i = 1, sz = transformed.size() - 3; i < sz; i++) {
        expected += ((n - i + 1) % 9 + 1) * transformed[i];
    }

    expected += c;

    return expected % 11 == k;
}

void print_code(vector<int> &transformed) {
    for (int i = 1, sz = transformed.size() - 3; i < sz; i++) {
        if (transformed[i] == 10)
            cout << "-";
        else
            cout << transformed[i];
    }

    cout << endl;
}

int main(void) {
    int m, tmp, lowest, case_number = 0;;

    while (cin >> m) {
        if (m == 0)
            break;

        cout << "Case " << ++case_number << ": ";

        lowest = 201;
        vector<int> readings;

        rep (i, m) {
            cin >> tmp;
            readings.push_back(tmp);

            if (tmp < lowest)
                lowest = tmp;
        }

        if ((m + 1) % 6 != 0 || (m+1)/6 < 5) {
            cout << "bad code" << endl;
            continue;
        }

        double separator = lowest * 1.5;

        if (!good_widths(readings, separator)) {
            cout << "bad code" << endl;
            continue;
        }

        // if second bar is wide then it cannot be
        // the start/stop character, we reverse input
        if (readings[1] >= separator) {
            reverse (readings.begin(), readings.end());
        }

        vector<int> transformed;

        if (transform(readings, separator, transformed)) {
            int c = transformed[transformed.size()-3];
            int k = transformed[transformed.size()-2];

            if (!checkC(transformed, c)) {
                cout << "bad C" << endl;
            } else if (!checkK(transformed, c, k)) {
                cout << "bad K" << endl;
            } else {
                print_code(transformed);
            }
        } else {
            cout << "bad code" << endl;
        }
    }

    return 0;
}
