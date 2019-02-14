#include <iostream>
using namespace std;

int distance_to(int area, int office) {
    int r = abs(area / 5 - office / 5);
    int c = abs(area % 5 - office % 5);
    return r + c;
}

int main(void) {
    int city[25], sum, best, offices[5], result[5];
    int t, n, row, column, dist;

    cin >> t;

    while (t--) {
        best = -1;

        for (int i = 0; i < 25; i++)
            city[i] = 0;

        cin >> n;
        while (n--) {
            cin >> row >> column;
            cin >> city[row*5 + column];
        }

        for (offices[0] = 0; offices[0] < 21; offices[0]++) {
            for (offices[1] = offices[0] + 1; offices[1] < 22; offices[1]++) {
                for (offices[2] = offices[1] + 1; offices[2] < 23; offices[2]++) {
                    for (offices[3] = offices[2] + 1; offices[3] < 24; offices[3]++) {
                        for (offices[4] = offices[3] + 1; offices[4] < 25; offices[4]++) {

                            sum = 0;
                            for (int i = 0; i < 25; i++) {
                                if (city[i] == 0) continue;
                                dist = city[i] * distance_to(i, offices[0]);
                                dist = min(dist, city[i] * distance_to(i, offices[1]));
                                dist = min(dist, city[i] * distance_to(i, offices[2]));
                                dist = min(dist, city[i] * distance_to(i, offices[3]));
                                dist = min(dist, city[i] * distance_to(i, offices[4]));
                                sum += dist;
                            }
                            if (best == -1 || sum < best) {
                                best = sum;
                                for (int i = 0; i < 5; i++) {
                                    result[i] = offices[i];
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}
