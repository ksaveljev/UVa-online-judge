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
#include <deque>
#include <cassert>
using namespace std;

int main(void) {
    int t;
    string a, b;

    cin >> t;

    while (t--) {
        cin >> a >> b;

        deque<char> A, B, FA, FB;
        for (int i = 0; i < a.size(); i++) {
            A.push_back(a[i]);
        }
        for (int i = 0; i < b.size(); i++) {
            B.push_back(b[i]);
        }

        int winner = -1;
        for (int i = 0; i < 1000; i++) {
            char aa = A.front();
            A.pop_front();
            char bb = B.front();
            B.pop_front();

            FA.push_front(aa);
            FB.push_front(bb);

            if (aa == bb) {
                int r = random() / 141 % 2;
                if (r == 0) {
                    // Jane
                    cout << "Snap! for Jane: ";
                    while (!FB.empty()) {
                        FA.push_front(FB.back());
                        FB.pop_back();
                    }
                    for (int i = 0; i < FA.size(); i++) {
                        cout << FA[i];
                    }
                    cout << endl;
                } else if (r == 1) {
                    // John
                    cout << "Snap! for John: ";
                    while (!FA.empty()) {
                        FB.push_front(FA.back());
                        FA.pop_back();
                    }
                    for (int i = 0; i < FB.size(); i++) {
                        cout << FB[i];
                    }
                    cout << endl;
                } else {
                    assert(false);
                }
            }

            if (A.empty() && FA.empty()) {
                // John wins
                winner = 1;
                break;
            } else if (B.empty() && FB.empty()) {
                // Jane wins
                winner = 0;
                break;
            }

            if (A.empty()) {
                while (!FA.empty()) {
                    A.push_front(FA.front());
                    FA.pop_front();
                }
            }

            if (B.empty()) {
                while (!FB.empty()) {
                    B.push_front(FB.front());
                    FB.pop_front();
                }
            }
        }

        if (winner == -1) {
            cout << "Keeps going and going ..." << endl;
        } else if (winner == 0) {
            cout << "Jane wins." << endl;
        } else {
            cout << "John wins." << endl;
        }
        if (t) cout << endl;
    }

    return 0;
}
