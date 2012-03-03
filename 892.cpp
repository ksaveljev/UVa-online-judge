#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string input;
    string hyp = "";

    while (getline(cin, input)) {
        if (input == "#")
            break;

        int pos = input.size();

        if (!hyp.empty()) {
            cout << hyp;
            hyp = "";
            for (int i = 0, sz = input.size(); i < sz; i++) {
                if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z') {
                    cout << input[i];
                    input[i] = '_';
                    continue;
                }

                break;
            }
            cout << endl;
        }

        if (input[input.size()-1] == '-') {
            for (int i = input.size() - 2; i >= 0; i--) {
                if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z') {
                    continue;
                }

                pos = i + 1;
                break;
            }

            hyp = input.substr(pos, input.size() - pos - 1);
        }
        
        for (int i = 0; i < pos; i++) {
            if (input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z' || input[i] == ' ')
                cout << input[i];
        }

        cout << endl;
    }

    return 0;
}
