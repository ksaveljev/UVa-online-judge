#include <iostream>
#include <string>
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

enum hand_rank {
    HIGH_CARD = 1,
    PAIR = 2,
    TWO_PAIRS = 3,
    THREE_OF_A_KIND = 4,
    STRAIGHT = 5,
    FLUSH = 6,
    FULL_HOUSE = 7,
    FOUR_OF_A_KIND = 8,
    STRAIGHT_FLUSH = 9
};

int suit2int(char suit) {
    static string suits = "DHCS";
    return suits.find(suit);
}

int val2int(char val) {
    static string vals = "23456789TJQKA";
    return vals.find(val);
}

struct hand {
    int suits[4];
    int vals[13];
    int highest;
    int lowest;
    int nvals;
    int nsuits;

    hand() {
        rep (i, 4) suits[i] = 0;
        rep (i, 13) vals[i] = 0;
        highest = -1;
        lowest = 666;
        nvals = 0;
        nsuits = 0;
    }

    void add_card(const string &card) {
        int suit = suit2int(card[1]);
        int val = val2int(card[0]);

        if (vals[val] == 0)
            nvals++;

        if (suits[suit] == 0)
            nsuits++;

        suits[suit]++;
        vals[val]++;

        highest = highest > val ? highest : val;
        lowest = lowest < val ? lowest : val;
    }
};

pair<int,int> hand_value(const hand &h) {
    // Straight flush: 5 cards of the same suit with consecutive values.
    // Ranked by the highest card in the hand.
    if (h.nsuits == 1 && h.nvals == 5 && h.lowest + 4 == h.highest) {
        return make_pair(STRAIGHT_FLUSH, h.highest);
    }

    // Four of a kind: 4 cards with the same value.
    // Ranked by the value of the 4 cards.
    if (h.nsuits == 4 && h.nvals == 2 && (h.vals[h.lowest] == 4 || h.vals[h.lowest] == 4)) {
        if (h.vals[h.lowest] == 4) {
            return make_pair(FOUR_OF_A_KIND, h.lowest);
        } else {
            return make_pair(FOUR_OF_A_KIND, h.highest);
        }
    }

    // Full House: 3 cards of the same value,
    // with the remaining 2 cards forming a pair.
    // Ranked by the value of the 3 cards.
    if (h.nvals == 2 && (h.vals[h.lowest] == 3 && h.vals[h.highest] == 2 || h.vals[h.lowest] == 2 && h.vals[h.highest] == 3)) {
        if (h.vals[h.highest] == 3) {
            return make_pair(FULL_HOUSE, h.highest);
        } else {
            return make_pair(FULL_HOUSE, h.lowest);
        }
    }

    // Flush: Hand contains 5 cards of the same suit.
    // Hands which are both flushes are ranked using the rules for High Card.
    if (h.nsuits == 1 && h.nvals == 5) {
        int m = 0;
        for (int i = 12; i >= 0; i--) {
            rep (j, h.vals[i]) {
                m = (m << 4) | i;
            }
        }

        return make_pair(FLUSH, m);
    }

    // Straight: Hand contains 5 cards with consecutive values. 
    // Hands which both contain a straight are ranked by their highest card.
    if (h.nvals == 5 && h.lowest + 4 == h.highest) {
        return make_pair(STRAIGHT, h.highest);
    }

    // Three of a Kind: Three of the cards in the hand have the same value.
    // Hands which both contain three of a kind are ranked by the value of the 3 cards.
    rep (i, 13) {
        if (h.vals[i] == 3) {
            return make_pair(THREE_OF_A_KIND, i);
        }
    }

    // Two Pairs: The hand contains 2 different pairs.
    // Hands which both contain 2 pairs are ranked by the value of their highest pair.
    // Hands with the same highest pair are ranked by the value of their other pair.
    // If these values are the same the hands are ranked by the value of the remaining card.
    rep (i, 13) {
        rep (j, 13) {
            if (i == j) continue;

            if (h.vals[i] == 2 && h.vals[j] == 2) {
                rep (k, 13) {
                    if (h.vals[k] == 1) {
                        return make_pair(TWO_PAIRS, (i << 8) + (j << 4) + k);
                    }
                }
            }
        }
    }

    // Pair: 2 of the 5 cards in the hand have the same value.
    // Hands which both contain a pair are ranked by the value of the cards forming the pair.
    // If these values are the same, the hands are ranked by the values of
    // the cards not forming the pair, in decreasing order.
    rep (i, 13) {
        if (h.vals[i] == 2) {
            int m = i;

            for (int j = 12; j >= 0; j--) {
                if (j == i) continue;
                rep (k, h.vals[j]) {
                    m = (m << 4) | j;
                }
            }

            return make_pair(PAIR, m);
        }
    }

    // High Card: Hands which do not fit any higher category are ranked by
    // the value of their highest card. If the highest cards have the same
    // value, the hands are ranked by the next highest, and so on.
    int m = 0;
    for (int i = 12; i >= 0; i--) {
        rep (j, h.vals[i]) {
            m = (m << 4) | i;
        }
    }

    return make_pair(HIGH_CARD, m);
}

int main(void) {
    string card;

    while (cin >> card) {
        hand a, b;

        a.add_card(card);
        rep (i, 4) {
            cin >> card;
            a.add_card(card);
        }

        rep (i, 5) {
            cin >> card;
            b.add_card(card);
        }

        pair<int,int> av = hand_value(a);
        pair<int,int> bv = hand_value(b);

        if (av.first > bv.first || av.first == bv.first && av.second > bv.second) {
            cout << "Black wins." << endl;
        } else if (av.first == bv.first && av.second == bv.second) {
            cout << "Tie." << endl;
        } else {
            cout << "White wins." << endl;
        }
    }

    return 0;
}
