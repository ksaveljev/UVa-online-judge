#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void) {
  int scenario;
  int counter = 0;
  double u, v, t, a, s;

  while (cin >> scenario) {
    if (scenario == 0)
      break;

    counter++;

    cout << "Case " << counter << ": ";

    switch (scenario) {
      case 1:
        cin >> u >> v >> t;
        a = (v - u) / t;
        s = u * t + 0.5 * a * t * t;
        cout << setprecision(3) << fixed << showpoint << s << " " << a << endl;
        break;
      case 2:
        cin >> u >> v >> a;
        t = (v - u) / a;
        s = u * t + 0.5 * a * t * t;
        cout << setprecision(3) << fixed << showpoint << s << " " << t << endl;
        break;
      case 3:
        cin >> u >> a >> s;
        t = (-u + sqrt(u * u + 2 * a * s)) / a;
        v = a * t + u;
        cout << setprecision(3) << fixed << showpoint << v << " " << t << endl;
        break;
      case 4:
        cin >> v >> a >> s;
        t = (-v + sqrt(v * v - 2 * a * s)) / -a;
        u = v - a * t;
        cout << setprecision(3) << fixed << showpoint << u << " " << t << endl;
        break;
    }
  }

  return 0;
}
