#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool theTruthIsOutThere(const pair<double,double> &a, const pair<double, double> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

int main(void) {
    int n;
    double l, w;
    double p, r;

    while (cin >> n >> l >> w) {
        double halfw = w / 2.0;
        vector< pair<double, double> > sprinkles;
        for (int i = 0; i < n; i++) {
            cin >> p >> r;
            if (r < halfw) continue;
            double tmp = sqrt(r*r - halfw*halfw);
            sprinkles.push_back(make_pair(p - tmp, p + tmp));
        }
        sort(sprinkles.begin(), sprinkles.end(), theTruthIsOutThere);

        /*
        for (int i = 0, sz = sprinkles.size(); i < sz; i++) {
            cout << sprinkles[i].first << " " << sprinkles[i].second << endl;
        }
        cout << "-----------------" << endl;
        */

        int result = 0;
        double cur = 0;

        for (int i = 0, sz = sprinkles.size(); i < sz; i++) {
            if (cur >= l) break;

            if (sprinkles[i].first <= cur) {
                result++;

                for (int j = i+1; j < sz; j++) {
                    if (sprinkles[j].first <= cur && sprinkles[j].second > sprinkles[i].second) {
                        i = j;
                    } else if (sprinkles[j].first > cur) {
                        break;
                    }
                }

                cur = sprinkles[i].second;
            } else {
                result = -1;
                break;
            }
        }

        if (cur < l) result = -1;

        cout << result << endl;
    }

    return 0;
}
