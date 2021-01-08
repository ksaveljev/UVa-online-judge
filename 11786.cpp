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
#include <stack>
using namespace std;

int main(void) {
    int t;
    string input;

    cin >> t;

    while (t--) {
        cin >> input;

        stack<int> s;
        int result = 0;

        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '\\') {
                s.push(i);
            } else if (input[i] == '/') {
                if (!s.empty()) {
                    result += i - s.top();
                    s.pop();
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
