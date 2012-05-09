#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

vector<string> keys;
bool end_of_message;
int current_length;

void map_header_to_keys(string &header, map<string, char> &dic) {
    rep (i, header.size()) {
        dic[keys[i]] = header[i];
    }
}

bool good_key (string &s) {
    rep (i, s.size()) {
        if (s[i] == '0')
            return true;
    }

    return false;
}

void generate_key(int length, string key) {
    if (key.size() == length) {
        if (good_key(key)) {
            keys.push_back(key);
        }

        return;
    }

    generate_key (length, key + '0');
    generate_key (length, key + '1');
}

void generate_keys() {
    REP (i, 1, 8) {
        generate_key (i, "");
    }
}

string decode_message (string &message, map<string, char> &dic) {
    string key;
    int index = 0, sz = message.size();

    while (true) {
        if (current_length == -1) {
            if (sz - index < 3) {
                break;
            }

            current_length = 4 * (message[index] - '0') + 2 * (message[index+1] - '0') + 1 * (message[index+2] - '0');

            index += 3;

            if (current_length == 0) {
                end_of_message = true;
                cout << endl;
                break;
            }
        } else {
            if (sz - index < current_length) {
                break;
            }

            key = message.substr(index, current_length);

            if (good_key(key)) {
                cout << dic[key];
                index += current_length;
            } else {
                index += current_length;
                current_length = -1;
            }

        }
    }

    return message.substr(index);
}

int main(void) {
    string header, message, tmp;

    generate_keys();

    while (getline(cin, header)) {
        map<string, char> dic;
        map_header_to_keys(header, dic);

        end_of_message = false;
        current_length = -1;

        while (getline(cin, tmp)) {
            message += tmp;

            // prints what it can decode at the moment
            // and returns the piece that wasn't decoded
            message = decode_message(message, dic);

            if (end_of_message)
                break;
        }
    }

    return 0;
}
