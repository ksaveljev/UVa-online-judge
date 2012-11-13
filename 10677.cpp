#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

vector<int> convert(int number, int base) {
    vector<int> result;

    while (number) {
        result.push_back(number % base);
        number /= base;
    }

    return result;
}

int convert2(vector<int> &converted, int base) {
    int result = 0;

    rep (i, converted.size()) {
        result += converted[i] * pow(base, i);
    }

    return result;
}

int main(void) {
    int n;
    int B1, B2, r1, r2;

    cin >> n;

    while (n--) {
        cin >> B1 >> B2 >> r1 >> r2;

        int result = -1;

        for (int i = r2 - 1; i > r1; i--) {
            vector<int> converted = convert(i, B1);
            int tmp = convert2(converted, B2);

            if (tmp % i == 0) {
                result = i;
                break;
            }
        }

        if (result == -1)
            cout << "Non-existent." << endl;
        else
            cout << result << endl;
    }

    return 0;
}
