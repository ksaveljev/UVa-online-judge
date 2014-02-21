#include <iostream>
#include <vector>
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

typedef struct _vehicle {
    int initial_position;
    int current_position;
    bool parked;
    _vehicle() : parked(false) {}
} vehicle;

int select_next_vehicle(const vector<vehicle> &vehicles, int pos) {
    int result = -1, diff = 9999999;

    rep (i, vehicles.size()) {
        if (vehicles[i].parked) continue;

        if (vehicles[i].current_position <= pos) {
            if (pos - vehicles[i].current_position < diff) {
                result = i;
                diff = pos - vehicles[i].current_position;
            }
        } else {
            if (20 + pos - vehicles[i].current_position < diff) {
                result = i;
                diff = 20 + pos - vehicles[i].current_position;
            }
        }
    }

    return result;
}

int park_vehicle(vector<vehicle> &vehicles, int index, int pos) {
    int diff;

    if (vehicles[index].current_position <= pos) {
        diff = pos - vehicles[index].current_position;
        vehicles[index].current_position = pos;
    } else {
        diff = 20 + pos - vehicles[index].current_position;
        vehicles[index].current_position = pos;
    }

    vehicles[index].parked = true;

    return diff;
}

void adjust_vehicles(vector<vehicle> &vehicles, int diff) {
    rep (i, vehicles.size()) {
        if (vehicles[i].parked) continue;

        vehicles[i].current_position += diff;
        if (vehicles[i].current_position > 20)
            vehicles[i].current_position -= 20;
    }
}

int main(void) {
    int cases, pos;
    vehicle tmp;

    cin >> cases;

    while (cases--) {
        vector<vehicle> vehicles;
        
        while (cin >> pos) {
            if (pos == 99) break;

            tmp.initial_position = tmp.current_position = pos;
            vehicles.push_back(tmp);
        }

        cin.ignore(100, '\n'); // ignore \n after 99

        while (cin.peek() != '\n' && cin.peek() != -1) {
            cin >> pos;
            cin.ignore(100, '\n');

            int next = select_next_vehicle(vehicles, pos);
            if (next != -1) {
                int diff = park_vehicle(vehicles, next, pos);
                adjust_vehicles(vehicles, diff);
            }
        }

        rep (i, vehicles.size()) {
            cout << "Original position " << vehicles[i].initial_position;
            if (vehicles[i].parked) {
                cout << " parked in " << vehicles[i].current_position << endl;
            } else {
                cout << " did not park" << endl;
            }
        }

        if (cases) cout << endl;
    }

    return 0;
}
