#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <numeric>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

struct D {
    int n;
    string dir;
};

vector<D> parse(const string& input) {
    vector<D> result;

    int n = 0;
    string d = "";
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ',' || input[i] == '.') {
            result.push_back({n , d});
            n = 0;
            d = "";
            if (input[i] == '.') break;
            continue;
        }

        if (input[i] >= '0' && input[i] <= '9') {
            n = n * 10 + int(input[i] - '0');
        } else {
            d += input[i];
        }
    }

    return result;
}

int main(void) {
    string input;
    int count = 0;

    while (getline(cin, input)) {
        if (input == "END") {
            break;
        }

        count++;

        vector<D> directions = parse(input);
        double x = 0, y = 0;
        double diag = sqrt(0.5);

        for (D d : directions) {
            if (d.dir == "N") {
                y += d.n;
            } else if (d.dir == "NE") {
                y += d.n * diag;
                x += d.n * diag;
            } else if (d.dir == "E") {
                x += d.n;
            } else if (d.dir == "SE") {
                y -= d.n * diag;
                x += d.n * diag;
            } else if (d.dir == "S") {
                y -= d.n;
            } else if (d.dir == "SW") {
                y -= d.n * diag;
                x -= d.n * diag;
            } else if (d.dir == "W") {
                x -= d.n;
            } else if (d.dir == "NW") {
                y += d.n * diag;
                x -= d.n * diag;
            }
        }

        cout << fixed << setprecision(3);
        cout << "Map #" << count << "\n";
        cout << "The treasure is located at (" << x << "," << y << ").\n";
        cout << "The distance to the treasure is " << sqrt(x * x + y * y) << ".\n";
        cout << "\n";
    }

    return 0;
}
