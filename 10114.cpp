#include <iostream>
using namespace std;

int main(void) {
  int duration;
  double down_payment, loan;
  int deprecation_num;
  double deprecation[101];
  int m;
  double d;

  while (cin >> duration >> down_payment >> loan >> deprecation_num) {
    if (duration < 0)
      break;

    while (deprecation_num--) {
      cin >> m >> d;
      for (int i = m; i < 101; i++)
        deprecation[i] = d;
    }

    int months = 0;
    double loan_diff = loan / duration;
    double car_value = (down_payment + loan) * (1 - deprecation[0]);
    while (car_value < loan) {
      months++;
      loan -= loan_diff;
      car_value = car_value * (1 - deprecation[months]);
    }

    if (months == 1) {
      cout << "1 month" << endl;
    } else {
      cout << months << " months" << endl;
    }
  }

  return 0;
}
