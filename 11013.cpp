#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

map<string,bool> taken;
int hand[5];
vector<char> suits = {'S', 'H', 'D', 'C'};

char int2card(int x) {
    switch (x) {
        case 0: return 'A';
        case 9: return 'T';
        case 10: return 'J';
        case 11: return 'Q';
        case 12: return 'K';
        default: return '0' + x + 1;
    }
}

int card2int(string card) {
    switch (card[0]) {
        case 'A': return 0;
        case 'T': return 9;
        case 'J': return 10;
        case 'Q': return 11;
        case 'K': return 12;
        default: return card[0] - '0' - 1;
    }
}

int calcScore() {
    int count[13];
    for (int i = 0; i < 13; i++) count[i] = 0;

    for (int i = 0; i < 5; i++)
        count[hand[i]]++;

    // Straight (run of 5)
    for (int i = 0; i < 13; i++) {
        int c = 0;
        for (int j = 0; j < 5; j++) {
            c += count[(i+j)%13] > 0;
        }
        if (c == 5) return 100;
    }

    // Invite-the-Neighbours (run of 4)
    for (int i = 0; i < 13; i++) {
        int c = 0;
        for (int j = 0; j < 4; j++) {
            c += count[(i+j)%13] > 0;
        }
        if (c == 4) return 10;
    }

    // Bed-and-Breakfast (run of 3 + run of 2)
    int _count[13];
    for (int i = 0; i < 13; i++) _count[i] = count[i];

    bool found = false;
    for (int i = 0; i < 13; i++) {
        int c = 0;
        for (int j = 0; j < 3; j++) {
            c += _count[(i+j)%13] > 0;
        }
        if (c == 3) {
            found = true;
            for (int j = 0; j < 3; j++) {
                _count[(i+j)%13]--;
            }
            break;
        }
    }
    if (found) {
        for (int i = 0; i < 13; i++) {
            int c = 0;
            for (int j = 0; j < 2; j++) {
                c += _count[(i+j)%13] > 0;
            }
            if (c == 2) return 5;
        }
    }

    // Menage-a-Trois (run of 3)
    for (int i = 0; i < 13; i++) {
        int c = 0;
        for (int j = 0; j < 3; j++) {
            c += count[(i+j)%13] > 0;
        }
        if (c == 3) return 3;
    }

    // Double Dutch (run of 2 + run of 2)
    for (int i = 0; i < 13; i++) _count[i] = count[i];
    found = false;
    for (int i = 0; i < 13; i++) {
        int c = 0;
        for (int j = 0; j < 2; j++) {
            c += _count[(i+j)%13] > 0;
        }
        if (c == 2) {
            found = true;
            for (int j = 0; j < 2; j++) {
                _count[(i+j)%13]--;
            }
            break;
        }
    }
    if (found) {
        for (int i = 0; i < 13; i++) {
            int c = 0;
            for (int j = 0; j < 2; j++) {
                c += _count[(i+j)%13] > 0;
            }
            if (c == 2) return 1;
        }
    }

    return 0;
}

void print_hand() {
    for (int i = 0; i < 5; i++) {
        cout << int2card(hand[i]) << " ";
    }
    cout << endl;
}

int main(void) {
    string tmp;

    while (cin >> tmp) {
        if (tmp == "#") break;

        vector<string> initial_hand;

        taken.clear();

        taken[tmp] = true;
        hand[0] = card2int(tmp);
        initial_hand.push_back(tmp);

        for (int i = 1; i < 5; i++) {
            cin >> tmp;
            taken[tmp] = true;
            hand[i] = card2int(tmp);
            initial_hand.push_back(tmp);
        }

        int initial_score = calcScore() * 47;
        int best_score = initial_score;
        string exchange = "";

        for (int k = 0; k < 5; k++) {
            int score = -47;
            for (int i = 0; i < 13; i++) {
                for (int j = 0; j < 4; j++) {
                    string card = "";
                    card.push_back(int2card(i));
                    card.push_back(suits[j]);
                    if (taken[card])
                        continue;

                    int prev = hand[k];
                    hand[k] = i;
                    score += calcScore();
                    hand[k] = prev;
                }
            }
            if (score > best_score) {
                best_score = score;
                exchange = initial_hand[k];
            }
        }

        if (best_score > initial_score) {
            cout << "Exchange " << exchange << endl;
        } else {
            cout << "Stay" << endl;
        }
    }

    return 0;
}
