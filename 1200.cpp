#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    int t;
    string input;
    vector< pair<int,bool> > left, right;
    
    cin >> t;
    getline(cin, input); // \n after t

    while (t--) {
        getline(cin, input);

        int tmp = -1;
        bool negative = false;
        bool eq_sign = false;
        left.clear();
        right.clear();

        for (int i = 0, sz = input.size(); i < sz; i++) {
            if (input[i] >= '0' && input[i] <= '9') {
                if (tmp == -1)
                    tmp = 0;
                tmp = tmp * 10 + (input[i] - '0');
            } else if (input[i] == 'x') {
                if (tmp == -1) {
                    tmp = 1;
                }

                if (negative)
                    tmp *= -1;

                if (!eq_sign) {
                    left.push_back(make_pair(tmp, true));
                } else {
                    right.push_back(make_pair(tmp, true));
                }

                tmp = -1;
                negative = false;
            } else if (input[i] == '=') {
                if (tmp != -1) {
                    if (negative)
                        tmp *= -1;

                    if (!eq_sign)
                        left.push_back(make_pair(tmp, false));
                    else
                        right.push_back(make_pair(tmp, false));
                }

                tmp = -1;
                eq_sign = true;
                negative = false;
            } else if (input[i] == '-' || input[i] == '+') {
                if (tmp != -1) {
                    if (negative)
                        tmp *= -1;

                    if (!eq_sign)
                        left.push_back(make_pair(tmp, false));
                    else
                        right.push_back(make_pair(tmp, false));
                }

                tmp = -1;
                if (input[i] == '-')
                    negative = true;
                else
                    negative = false;
            }
        }

        if (tmp != -1) {
            if (negative)
                tmp *= -1;

            if (!eq_sign)
                left.push_back(make_pair(tmp, false));
            else
                right.push_back(make_pair(tmp, false));
        }


        int left_num = 0, right_num = 0, left_x = 0, right_x = 0;

        for (int i = 0, sz = left.size(); i < sz; i++) {
            if (left[i].second) {
                left_x += left[i].first;
            } else {
                left_num += left[i].first;
            }
        }

        for (int i = 0, sz = right.size(); i < sz; i++) {
            if (right[i].second) {
                right_x += right[i].first;
            } else {
                right_num += right[i].first;
            }
        }

        left_x = left_x - right_x;
        right_num = right_num - left_num;

        if (left_x == 0) {
            if (right_num == 0)
                cout << "IDENTITY" << endl;
            else
                cout << "IMPOSSIBLE" << endl;
        } else {
            int result = floor(right_num * 1.0 / left_x);
            if (result == 0)
                result *= 0;
            cout << result << endl;
        }
    }

    return 0;
}
