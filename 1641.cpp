#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
    int h, w;
    char tmp;

    while (cin >> h >> w) {
        int seg = 0;
        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> tmp;
                if (tmp == '/' || tmp == '\\') {
                    seg++;
                }
                if (seg % 2 == 1) {
                    count += 2;
                }
            }
        }
        cout << count / 2 << endl;
    }

    return 0;
}
