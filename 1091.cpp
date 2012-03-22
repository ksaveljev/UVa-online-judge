#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int readings[150];
int transformed[25];

bool is_good_reading(int m, pair<int,int> &low, pair<int,int> &high) {
    bool result = true;

    if ((m+1) % 6 != 0)
        return false;

    rep (i, m) {
        if (low.first <= readings[i] && readings[i] <= low.second || high.first <= readings[i] && readings[i] <= high.second)
            continue;

        result = false;
        break;
    }

    return result;
}

int map_to_character(int num) {
    int result;

    switch (num) {
        case 1:
            result = 0;
            break;
        case 17:
            result = 1;
            break;
        case 9:
            result = 2;
            break;
        case 24:
            result = 3;
            break;
        case 5:
            result = 4;
            break;
        case 20:
            result = 5;
            break;
        case 12:
            result = 6;
            break;
        case 3:
            result = 7;
            break;
        case 18:
            result = 8;
            break;
        case 16:
            result = 9;
            break;
        case 4:
            result = 10;
            break;
        case 6:
            result = 110;
            break;
        default:
            result = -1;
            break;
    }

    return result;
}

int decode(int pos, pair<int,int> &low, pair<int,int> &high) {
    int num = 0;

    REP (i, pos, pos+5) {
        if (low.first <= readings[i] && readings[i] <= low.second) {
            num <<= 1;
        } else {
            num = (num << 1) + 1;
        }
    }

    return map_to_character(num);
}

bool transform_readings(int m, pair<int,int> &low, pair<int,int> &high) {
    bool ok = true;
    int counter = 0;

    for (int i = 0; i < m; i += 6) {
        int character = decode(i, low, high);
        if (character == -1) {
            ok = false;
            break;
        }

        transformed[counter] = character;
        counter++;

        if (i + 5 < m) {
            if (readings[i+5] < low.first || readings[i+5] > low.second) {
                ok = false;
                break;
            }
        }
    }

    return ok;
}

int count_c(int m) {
    int n = (m+1)/6 - 4;
    int sum = 0;

    rep (i, n) {
        sum += ((n - i - 1) % 10 + 1) * transformed[i+1];
    }

    return sum % 11;
}

int count_k(int m, int c) {
    int n = (m+1)/6 - 4;
    int sum = 0;

    rep (i, n) {
        sum += ((n - i) % 9 + 1) * transformed[i+1];
    }

    sum += (0 % 9 + 1) * c;

    return sum % 11;
}

void print_code(int m) {
    REP (i, 1, (m+1)/6-3) {
        if (transformed[i] == 10)
            cout << "-";
        else
            cout << transformed[i];
    }
    cout << endl;
}

int main(void) {
    int m, case_num = 0;

    while (cin >> m) {
        if (m == 0)
            break;

        case_num++;

        cout << "Case " << case_num << ": ";

        int lowest = 201;
        int highest = 0;

        rep (i, m) {
            cin >> readings[i];

            if (readings[i] > highest)
                highest = readings[i];

            if (readings[i] < lowest)
                lowest = readings[i];
        }

        pair<int,int> low = make_pair(lowest, int(lowest / 0.95));
        pair<int,int> high = make_pair(int(highest / 1.05), highest);

        if (!is_good_reading(m, low, high)) {
            cout << "bad code" << endl;
            continue;
        }

        if (transform_readings(m, low, high) && transformed[0] == 110 && transformed[(m+1)/6 - 1] == 110) {
            int c = count_c(m);
            int k = count_k(m, c);

            if (transformed[(m+1)/6 - 3] != c) {
                cout << "bad C" << endl;
            } else if (transformed[(m+1)/6 - 2] != k) {
                cout << "bad K" << endl;
            } else {
                print_code(m);
            }
        } else {
            reverse(readings, readings + m);

            if (transform_readings(m, low, high) && transformed[0] == 110 && transformed[(m+1)/6 - 1] == 110) {
                int c = count_c(m);
                int k = count_k(m, c);

                if (transformed[(m+1)/6 - 3] != c) {
                    cout << "bad C" << endl;
                } else if (transformed[(m+1)/6 - 2] != k) {
                    cout << "bad K" << endl;
                } else {
                    print_code(m);
                }
            } else {
                cout << "bad code" << endl;
            }
        }
    }

    return 0;
}
