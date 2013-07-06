#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

void generate_codes(int num, int depth, int max_depth, vector<int>& codes) {
    if (depth == max_depth) {
        codes.push_back(num);
        return;
    }

    REPI (i, 1, 9) {
        generate_codes(num * 10 + i, depth + 1, max_depth, codes);
    }
}

pair<int,int> guess_code(int correct, int guess) {
    int correct_count[10], guess_count[10];
    int strong = 0;
    int weak = 0;

    for (int i = 0; i < 10; i++) {
        correct_count[i] = 0;
        guess_count[i] = 0;
    }

    int tmp = correct;
    while (tmp > 0) {
        correct_count[tmp%10]++;
        tmp /= 10;
    }

    while (guess > 0) {
        if (guess % 10 == correct % 10) {
            strong++;
            correct_count[correct % 10]--;
        } else {
            guess_count[guess % 10]++;
        }

        guess /= 10;
        correct /= 10;
    }

    REPI (i, 1, 9) {
        weak += min(correct_count[i], guess_count[i]);
    }

    return make_pair(strong, weak);
}

int main(void) {
    int n, guess, strong, weak;


    cin >> n;

    while (n--) {
        int count = 0;
        cin >> guess >> strong >> weak;

        vector<int> codes;
        generate_codes(0, 0, log10(guess) + 1, codes);

        rep (i, codes.size()) {
            pair<int,int> result = guess_code(codes[i], guess);
            if (result.first == strong && result.second == weak) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
