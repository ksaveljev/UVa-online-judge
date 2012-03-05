#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int t, k, i, result, diff, length;
    string input;

    cin >> t;
    cin.ignore(100, '\n');

    while (t--) {
        cin >> input >> k;

        result = 0;

        for (int len = 0, sz = input.size(); len < sz; len++) {
            length = 0;
            diff = 0;
            int d = 0;

            // using 1 char as center of palindrome
            for (i = len, d = 0; i-d >= 0 && i+d < sz && (input[i-d] == input[i+d] || diff < k); d++) {
                if (input[i-d] != input[i+d])
                    diff++;
            }

            if (1 + (d-1) * 2 > length)
                length = 1 + (d-1) * 2;

            d = 0;
            diff = 0;

            // using 2 chars as center of palindrome
            for (i = len; i-d >= 0 && i+1+d < sz && (input[i-d] == input[i+1+d] || diff < k); d++) {
                if (input[i-d] != input[i+1+d])
                    diff++;
            }

            if (2 + (d-1) * 2 > length)
                length = 2 + (d-1) * 2;

            if (length > result)
                result = length;
        }

        cout << result << endl;
    }

    return 0;
}
