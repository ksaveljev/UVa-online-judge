#include <iostream>
using namespace std;

long Jd(int year, int month, int day) {
  int Grig = 0; // is it Grigorian date?
  if (year > 1528) Grig = 0; else
  if (year < 1528) Grig = 1; else
  if (month > 10) Grig = 0; else
  if (month < 10) Grig = 1; else
  if (day >= 15) Grig = 0; else
  Grig = 1;
  if (month <= 2) {
    year--;
    month += 12;
  };
  unsigned long J;
  int A;
  if (Grig == 0) {
    A = year/100;
    A = 2 - A + (A / 4);
  } else A = 0;
  J = 1461L * long(year);
  J /= 4L;
  unsigned long K = 306001L * long(month+1);
  K /= 10000L;
  J += K + day + 1720995L + A;
  return J;
}

void GDate(long JD, int &y, int &m, int &d) {
  unsigned long A = (JD*4L - 7468865L) / 146097L;
  A = (JD > 2299160) ? JD+1+A-(A/4L):JD;
  long B = A + 1524;
  long C = (B*20L-2442L)/7305L;
  long D = (C*1461L)/4L;
  long E = (10000L*(B-D))/306001L;
  d = int(B-D-((E*306001L)/10000L));
  m = int((E<=13) ? E-1 : E-13);
  y = int(C - ((m>2) ? 4716 : 4715));
}

int main(void) {
  int d, m, y, n;
  
  while (cin >> n >> d >> m >> y) {
    if (!n && !d && !m && !y)
      break;

    long julian_date = Jd(y, m, d);
    julian_date += n;
    GDate(julian_date, y, m, d);
    cout << d << " " << m << " " << y << endl;
  }

  return 0;
}
