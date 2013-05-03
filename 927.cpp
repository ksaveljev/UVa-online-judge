#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int number_of_cases;
    int degree, tmp, d, k;

    cin >> number_of_cases;

    while (number_of_cases--) {
        cin >> degree;

        vector<int> coefficients;

        rep (i, degree + 1) {
            cin >> tmp;
            coefficients.push_back(tmp);
        }

        cin >> d >> k;

        int current = 0;
        int counter = 1;

        while (current + counter * d < k) {
            current += counter * d;
            counter++;
        }

        unsigned long long result = 0;
        rep (i, coefficients.size()) {
            result += coefficients[i] * pow(counter, i);
        }

        cout << result << endl;
    }

    return 0;
}
