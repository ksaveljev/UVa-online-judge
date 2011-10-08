#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

double call_rate(char step, int time_of_day) {
  double rates[3][5] = {{0.10, 0.25, 0.53, 0.87, 1.44},
                        {0.06, 0.15, 0.33, 0.47, 0.80},
                        {0.02, 0.05, 0.13, 0.17, 0.30}};

  return rates[time_of_day][step - 'A'];
}

void print_result(string& number, int day, int evening, int night, char step) {
  printf("%10s%6d%6d%6d%3c%8.2f\n", number.c_str(), day, evening, night, step, call_rate(step, 0) * day + call_rate(step, 1) * evening + call_rate(step, 2) * night);
}

void inc_time(int& h1, int& m1) {
  m1++;

  if (m1 == 60) {
    h1++;
    m1 = 0;
  }

  if (h1 == 24) {
    h1 = 0;
  }
}

int main(void)
{
  char step;
  string number;
  int h1, m1, h2, m2;

  while (cin >> step) {
    if (step == '#') {
      break;
    }

    cin >> number >> h1 >> m1 >> h2 >> m2;

    // boundary case start == end --> 24h call
    if (h1 == h2 && m1 == m2) {
      print_result(number, 600, 240, 600, step);
      continue;
    }

    int day, evening, night;
    day = evening = night = 0;

    while (h1 != h2 || m1 != m2) {
      if (h1 >= 8 && h1 < 18) {
        day++;
      } else if (h1 >= 18 && h1 < 22) {
        evening++;
      } else {
        night++;
      }

      inc_time(h1, m1);
    }

    print_result(number, day, evening, night, step);
  }
  
  return 0;
}
