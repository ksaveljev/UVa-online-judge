#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int str2int(const string &input) {
  switch (tolower(input[0])) {
    case 'a':
      if (input.size() == 1) return 1;
      return (input[1] == '#' ? 2 : 12);
    case 'b':
      return (input.size() == 1 ? 3 : 2);
    case 'c':
      return (input.size() == 2 ? 5 : 4);
    case 'd':
      if (input.size() == 1) return 6;
      return (input[1] == '#' ? 7 : 5);
    case 'e':
      return (input.size() == 1 ? 8 : 7);
    case 'f':
      return (input.size() == 2 ? 10 : 9);
    case 'g':
      if (input.size() == 1) return 11;
      return (input[1] == '#' ? 12 : 10);
  }
}

string int2chord(int c) {
  string result[12] = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
  return result[c-1];
}

int main(void) {
  int chords[3];
  string input;

  while (cin >> input) {
    cout << input;
    chords[0] = str2int(input);
    for (int i = 0; i < 2; i++) {
      cin >> input;
      cout << " " << input;
      chords[i+1] = str2int(input);
    }

    sort(chords, chords + 3);

    bool found = false;
    do {
      int a = chords[1] - chords[0];
      int b = chords[2] - chords[1];
      a = (a < 0 ? a + 12 : a);
      b = (b < 0 ? b + 12 : b);

      if (a == 4 && b == 3) {
        found = true;
        cout << " is a " << int2chord(chords[0]) << " Major chord." << endl;
        break;
      } else if (a == 3 && b == 4) {
        found = true;
        cout << " is a " << int2chord(chords[0]) << " Minor chord." << endl;
        break;
      }
    } while (next_permutation(chords, chords+3));

    if (!found)
      cout << " is unrecognized." << endl;
  }

  return 0;
}
