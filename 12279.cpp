#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int n, tmp;
    int case_number = 0;
    int given, supposed;

    while (cin >> n) {
        if (n == 0)
            break;

        case_number++;
        given = supposed = 0;

        while (n--) {
            cin >> tmp;

            if (tmp == 0)
                given++;
            else
                supposed++;
        }

        cout << "Case " << case_number << ": " << (supposed - given) << endl;
    }

    return 0;
}
