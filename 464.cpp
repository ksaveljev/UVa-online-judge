#include <iostream>
#include <string>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int k = 0;

enum grammar {
    SENTENCE,
    TRANS_SENTENCE,
    INTRANS_SENTENCE,
    SUBJECT,
    OBJECT,
    NOUN_PHRASE,
    MODIFIED_NOUN,
    MODIFIER,
    VERB_PHRASE,
    INTRANS_VERB_PHRASE,
    PREP_PHRASE,
    NOUN,
    TRANS_VERB,
    INTRANS_VERB,
    ARTICLE,
    ADJECTIVE,
    ADVERB,
    PREPOSITION,
    EMPTY
};

string generate (grammar g) {
    int tmp;
    string a,b,c,d,e;

    switch (g) {
    case SENTENCE:
        k++;
        if (k % 2 + 1 == 1) {
            return generate(TRANS_SENTENCE);
        } else {
            return generate(INTRANS_SENTENCE);
        }
    case TRANS_SENTENCE:
        a = generate(SUBJECT);
        b = generate(VERB_PHRASE);
        c = generate(OBJECT);
        d = generate(PREP_PHRASE);
        return a + " " + b + " " + c + (d.empty() ? "" : d);
    case INTRANS_SENTENCE:
        a = generate(SUBJECT);
        b = generate(INTRANS_VERB_PHRASE);
        c = generate(PREP_PHRASE);
        return a + " " + b + " " + (c.empty() ? "" : c);
    case SUBJECT:
        return generate(NOUN_PHRASE);
    case OBJECT:
        return generate(NOUN_PHRASE);
    case NOUN_PHRASE:
        a = generate(ARTICLE);
        b = generate(MODIFIED_NOUN);
        return a + " " + b;
    case MODIFIED_NOUN:
        k++;
        if (k % 2 + 1 == 1) {
            return generate(NOUN);
        } else {
            a = generate(MODIFIER);
            b = generate(NOUN);
            return a + " " + b;
        }
    case MODIFIER:
        k++;
        if (k % 2 + 1 == 1) {
            return generate(ADJECTIVE);
        } else {
            a = generate(ADVERB);
            b = generate(ADJECTIVE);
            return a + " " + b;
        }
    case VERB_PHRASE:
        k++;
        if (k % 2 + 1 == 1) {
            return generate(TRANS_VERB);
        } else {
            a = generate(ADVERB);
            b = generate(TRANS_VERB);
            return a + " " + b;
        }
    case INTRANS_VERB_PHRASE:
        k++;
        if (k % 2 + 1 == 1) {
            return generate(INTRANS_VERB);
        } else {
            a = generate(ADVERB);
            b = generate(INTRANS_VERB);
            return a + " " + b;
        }
    case PREP_PHRASE:
        k++;
        if (k % 2 + 1 == 1) {
            a = generate(PREPOSITION);
            b = generate(NOUN_PHRASE);
            return a + " " + b;
        } else {
            return generate(EMPTY);
        }
    case NOUN:
        k++;
        tmp = k % 5 + 1;
        switch (tmp) {
            case 1:
                return "man";
            case 2:
                return "dog";
            case 3:
                return "fish";
            case 4:
                return "computer";
            case 5:
                return "waves";
        }
    case TRANS_VERB:
        k++;
        tmp = k % 4 + 1;
        switch (tmp) {
            case 1:
                return "struck";
            case 2:
                return "saw";
            case 3:
                return "bit";
            case 4:
                return "took";
        }
    case INTRANS_VERB:
        k++;
        tmp = k % 4 + 1;
        switch (tmp) {
            case 1:
                return "slept";
            case 2:
                return "jumped";
            case 3:
                return "walked";
            case 4:
                return "swam";
        }
    case ARTICLE:
        k++;
        if (k % 2 + 1 == 1) {
            return "the";
        } else {
            return "a";
        }
    case ADJECTIVE:
        k++;
        tmp = k % 4 + 1;
        switch (tmp) {
            case 1:
                return "green";
            case 2:
                return "small";
            case 3:
                return "rabid";
            case 4:
                return "quick";
        }
    case ADVERB:
        k++;
        tmp = k % 3 + 1;
        switch (tmp) {
            case 1:
                return "nearly";
            case 2:
                return "suddenly";
            case 3:
                return "restlessly";
        }
    case PREPOSITION:
        k++;
        tmp = k % 3 + 1;
        switch (tmp) {
            case 1:
                return "on";
            case 2:
                return "over";
            case 3:
                return "through";
        }
    case EMPTY:
        return "";
    }
}

int main(void) {
    string input;

    while (getline (cin, input)) {
        grammar g;

        if (input == "sentence")
            g = SENTENCE;
        else if (input == "trans-sentence")
            g = TRANS_SENTENCE;
        else if (input == "intrans-sentence")
            g = INTRANS_SENTENCE;
        else if (input == "subject")
            g = SUBJECT;
        else if (input == "object")
            g = OBJECT;
        else if (input == "noun-phrase")
            g = NOUN_PHRASE;
        else if (input == "modified-noun")
            g = MODIFIED_NOUN;
        else if (input == "modifier")
            g = MODIFIER;
        else if (input == "verb-phrase")
            g = VERB_PHRASE;
        else if (input == "intrans-verb-phrase")
            g = INTRANS_VERB_PHRASE;
        else if (input == "prep-phrase")
            g = PREP_PHRASE;
        else if (input == "noun")
            g = NOUN;
        else if (input == "trans-verb")
            g = TRANS_VERB;
        else if (input == "intrans-verb")
            g = INTRANS_VERB;
        else if (input == "article")
            g = ARTICLE;
        else if (input == "adjective")
            g = ADJECTIVE;
        else if (input == "adverb")
            g = ADVERB;
        else if (input == "preposition")
            g = PREPOSITION;
        else if (input == "empty")
            g = EMPTY;

        cout << generate(g) << endl;
    }

    return 0;
}
