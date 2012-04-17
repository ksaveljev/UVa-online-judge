#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int boxes[7];

    while (true) {
        int result = 0;
        bool end = true;

        REP (i, 1, 7) {
            cin >> boxes[i];
            if (boxes[i] != 0)
                end = false;
        }

        if (end)
            break;

        result += boxes[6];
        boxes[6] = 0;

        while (boxes[5] > 0) {
            result++;
            boxes[5]--;

            int one_remaining = 11;

            int taken = min(one_remaining, boxes[1]);
            boxes[1] -= taken;
        }

        while (boxes[4] > 0) {
            result++;
            boxes[4]--;

            int two_remaining = 5;
            int one_remaining = 20;

            int taken = min(two_remaining, boxes[2]);

            boxes[2] -= taken;
            one_remaining -= 4 * taken;

            taken = min(one_remaining, boxes[1]);
            boxes[1] -= taken;
        }

        while (boxes[3] > 0) {
            result++;
            int three_reamining = 4;
            int two_remaining = 9;
            int one_remaining = 36;

            int taken = min(three_reamining, boxes[3]);

            boxes[3] -= taken;
            
            switch (taken) {
                case 1:
                    two_remaining = 5;
                    one_remaining -= 9;
                    break;
                case 2:
                    two_remaining = 3;
                    one_remaining -= 18;
                    break;
                case 3:
                    two_remaining = 1;
                    one_remaining -= 27;
                    break;
                case 4:
                    two_remaining = 0;
                    one_remaining = 0;
                    break;
            }

            taken = min(two_remaining, boxes[2]);
            boxes[2] -= taken;

            one_remaining -= taken * 4;

            taken = min(one_remaining, boxes[1]);
            boxes[1] -= taken;
        }

        while (boxes[2] > 0) {
            result++;
            int two_remaining = 9;
            int one_remaining = 36;

            int taken = min(two_remaining, boxes[2]);
            boxes[2] -= taken;

            one_remaining -= taken * 4;

            taken = min(one_remaining, boxes[1]);
            boxes[1] -= taken;
        }

        while (boxes[1] > 0) {
            result++;
            int one_remaining = 36;

            int taken = min(one_remaining, boxes[1]);
            boxes[1] -= taken;
        }

        cout << result << endl;
    }

    return 0;
}
