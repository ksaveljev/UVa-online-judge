#include <iostream>
#include <string>
using namespace std;

long long pow(int a, int b) {
    long long result = 1;

    while (b--)
        result *= a;

    return result;
}

long long calculate_result(string &input, int start) {
    long long result = 0;

    if (start == input.size() - 1) {
        switch (input[start]) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
        }
    }

    switch (input[start]) {
        case 'A':
            result = calculate_result(input, start + 1);
            break;
        case 'C':
            result = pow(4, input.size() - start - 1) + calculate_result(input, start + 1);
            break;
        case 'G':
            result = 2 * pow(4, input.size() - start - 1) + calculate_result(input, start + 1);
            break;
        case 'T':
            result = 3 * pow(4, input.size() - start - 1) + calculate_result(input, start + 1);
            break;
    }

    return result;
}

int main(void) {
    int t;
    string input;

    cin >> t;
    cin.ignore(100, '\n');

    for (int i = 0; i < t; i++) {
        getline(cin, input);

        cout << "Case " << i+1 << ": (" << input.size() << ":" << calculate_result(input, 0) << ")" << endl;
    }

    return 0;
}
