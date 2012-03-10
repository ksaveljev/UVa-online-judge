#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int n, result;

    while (cin >> n) {
        if (n == 0)
            break;

        result = log2(n);
        cout << result << endl;
    }

    return 0;
}
