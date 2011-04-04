#include <iostream>
#include <vector>
using namespace std;

template<typename T> vector<int> find_LIS (vector<T>& a) {
   vector<int> b, p (a.size());
   int u, v;

   if (a.size() < 1) return b;

   b.push_back (0);

   for (int i = 1; i < a.size(); i++) {
      if (a[b.back()] < a[i]) {
         p[i] = b.back();
	 b.push_back(i);
	 continue;
      }

      for (u = 0, v = b.size() - 1; u < v;) {
         int c = (u + v) / 2;
	 if (a[b[c]] < a[i]) u = c + 1; else v = c;
      }

      if (a[i] < a[b[u]]) {
         if (u > 0) p[i] = b[u-1];
	 b[u] = i;
      }
   }

   for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
   return b;
}

int main (void) {
   vector<int> input;
   int n;

   while (cin >> n)
      input.push_back (n);


   vector<int> result = find_LIS (input);
   cout << result.size() << endl << "-" << endl;

   for (int i = 0; i < result.size(); i++)
      cout << input[result[i]] << endl;

   return 0;
}
