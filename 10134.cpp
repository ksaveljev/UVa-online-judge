#include <iostream>
#include <string>
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

int main(void) {
    int n;
    string input;

    cin >> n;
    cin.ignore(100, '\n');
    getline(cin, input); // empty line

    while (n--) {
        int bait = 0;
        int fish = 0;
        int bait_instructions = 0;
        int fish_instructions = 0;
        int since_last_fish_instructions = 0;

        while (getline(cin, input)) {
            if (input == "") break;

            if (bait == 3 && input == "bait")
                input = "lunch";

            if (bait == 0 && input == "fish")
                input = "lunch";

            if (input == "bait") {
                bait_instructions++;
                if (bait_instructions == 2) {
                    bait++;
                    bait_instructions = 0;
                }

                if (fish > 0) {
                    since_last_fish_instructions++;
                }
            } else if (input == "fish") {
                if (fish == 0) {
                    bait--;
                    fish++;
                } else {
                    since_last_fish_instructions++;
                    fish_instructions++;

                    if (fish_instructions >= 3) {
                        if (since_last_fish_instructions >= 7) {
                            fish_instructions = 0;
                            since_last_fish_instructions = 0;
                            bait--;
                            fish++;
                        }
                    }
                }
            } else if (input == "lunch") {
                if (fish > 0) {
                    since_last_fish_instructions++;
                }
            }
        }

        cout << fish << endl;

        if (n > 0)
            cout << endl;
    }

    return 0;
}
