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
    string input;

    while (getline(cin, input)) {
        vector<int> len;
        int counter = 0;
        int start = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '.') {
                counter++;
            } else {
                if (start == 0) {
                    len.push_back(counter);
                } else {
                    if (counter > 0) {
                        len.push_back(counter);
                    }
                }
                counter = 0;
                start = i;
            }
        }
        len.push_back(counter);

        int result = max(0, max(len[0] - 1, len[len.size()-1] - 1));

        for (int i = 1; i < len.size() - 1; i++) {
            result = max(result, (len[i] - 1) / 2);
        }

        cout << result << endl;
    }

    return 0;
}
