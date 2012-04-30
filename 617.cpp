#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef struct _traffic_light {
    double L;
    int G, Y, R;
} traffic_light;

bool is_green(traffic_light &light, int speed) {
    double time = light.L * 3600 / speed;

    time = fmod(time, light.G + light.Y + light.R);

    return time <= light.G + light.Y;
}

bool good_speed(int speed, vector<traffic_light> &lights) {
    rep (i, lights.size()) {
        if (!is_green(lights[i], speed))
            return false;
    }

    return true;
}

int main(void) {
    int n;
    int case_number = 0;

    while (cin >> n) {
        if (n == -1)
            break;

        case_number++;

        traffic_light tmp;
        vector<traffic_light> lights;

        rep (i, n) {
            cin >> tmp.L >> tmp.G >> tmp.Y >> tmp.R;
            lights.push_back(tmp);
        }

        vector<int> result;

        REP (i, 30, 61) {
            if (good_speed(i, lights))
                result.push_back(i);
        }

        cout << "Case " << case_number << ": ";
        if (result.empty()) {
            cout << "No acceptable speeds." << endl;
        } else {
            int prev = result[0];

            cout << result[0];
            bool range = false;

            REP (i, 1, result.size()) {
                if (result[i] - prev == 1) {
                    range = true;
                    prev = result[i];
                } else {
                    if (range) {
                        range = false;
                        cout << "-" << prev;
                    }

                    cout << ", " << result[i];
                    prev = result[i];
                }
            }

            if (range) {
                cout << "-" << prev << endl;
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}
