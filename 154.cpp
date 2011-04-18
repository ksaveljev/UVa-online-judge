#include <iostream>
#include <string>
#include <map>
using namespace std;

enum bin_t { PLASTIC, GLASS, ALUMINIMUM, STEEL, NEWSPAPER };

struct _result {
  int best;
  int city;
};

int main(void) {
  char c, t;
  char useless;
  int city_num;
  int changes;
  string str;
  _result result;
  bin_t cities[110][5];
  map<char,int> m;

  m['r'] = 0;
  m['o'] = 1;
  m['y'] = 2;
  m['g'] = 3;
  m['b'] = 4;

  result.best = 2000000000;
  city_num = 0;

  while (true) {
    if (cin.peek() == '#')
      break;
    else if (cin.peek() == 'e') {
      getline(cin, str);

      for (int i = 0; i < city_num; i++) {
        changes = 0;
        for (int j = 0; j < city_num; j++) {
          for (int k = 0; k < 5; k++) {
            if (cities[i][k] != cities[j][k])
              changes++;
          }
        }

        if (changes < result.best) {
          result.best = changes;
          result.city = i + 1;
        }
      }

      cout << result.city << endl;


      city_num = 0;
      result.best = 2000000000;

      if (t == '#')
        break;

      continue;
    }

    for (int i = 0; i < 5; i++) {
      if (i > 0)
        cin >> useless;
      cin >> c >> useless >> t;
      if (t == 'G') {
        cities[city_num][m[c]] = GLASS;
      } else if (t == 'P') {
        cities[city_num][m[c]] = PLASTIC;
      } else if (t == 'S') {
        cities[city_num][m[c]] = STEEL;
      } else if (t == 'N') {
        cities[city_num][m[c]] = NEWSPAPER;
      } else if (t == 'A') {
        cities[city_num][m[c]] = ALUMINIMUM;
      }
    }

    cin.ignore(1000, '\n');

    city_num++;
  }

  return 0;
}
