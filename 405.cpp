#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef struct _routing_table {
    string mta;
    string country;
    string admd;
    string prmd;
    string organization;
} routing_table;

map<string,bool> visited;

pair<int,string> send_message(routing_table &msg, map< string, vector<routing_table> > &mta) {
    visited[msg.mta] = true;

    for (int i = 0, sz = mta[msg.mta].size(); i < sz; i++) {
        bool ok = true;

        if (mta[msg.mta][i].country != "*" && mta[msg.mta][i].country != msg.country)
            ok = false;

        if (mta[msg.mta][i].admd != "*" && mta[msg.mta][i].admd != msg.admd)
            ok = false;

        if (mta[msg.mta][i].prmd != "*" && mta[msg.mta][i].prmd != msg.prmd)
            ok = false;

        if (mta[msg.mta][i].organization != "*" && mta[msg.mta][i].organization != msg.organization)
            ok = false;

        if (ok) {
            if (mta[msg.mta][i].mta == msg.mta) {
                return make_pair(0, msg.mta);
            } else if (visited[mta[msg.mta][i].mta]) {
                return make_pair(-2, mta[msg.mta][i].mta);
            } else {
                msg.mta = mta[msg.mta][i].mta;
                return send_message(msg, mta);
            }
        }
    }

    return make_pair(-1, msg.mta);
}

int main(void) {
    int m, n, case_num = 0;
    string name;
    routing_table tmp;

    while (cin >> m) {
        case_num++;
        map< string, vector<routing_table> > mta;

        while (m--) {
            cin >> name >> n;

            while (n--) {
                cin >> tmp.mta >> tmp.country >> tmp.admd >> tmp.prmd >> tmp.organization;

                mta[name].push_back(tmp);
            }
        }

        cin >> n;

        cout << "Scenario # " << case_num << endl;

        for (int i = 0; i < n; i++) {
            cin >> tmp.mta >> tmp.country >> tmp.admd >> tmp.prmd >> tmp.organization;

            visited.clear();
            pair<int,string> result = send_message(tmp, mta);

            switch (result.first) {
                case 0:
                    cout << i+1 << " -- delivered to " << result.second << endl;
                    break;
                case -1:
                    cout << i+1 << " -- unable to route at " << result.second << endl;
                    break;
                case -2:
                    cout << i+1 << " -- circular routing detected by " << result.second << endl;
                    break;
            }
        }

        cout << endl;
    }

    return 0;
}
