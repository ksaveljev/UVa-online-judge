#include <iostream>
#include <vector>
using namespace std;

template<typename T> vector<int> find_LIS (vector<T>& a) {
   vector<int>b, p (a.size());
   int u, v;

   if (a.size() < 1) return b;

   b.push_back (0);

   for (int i = 1; i < a.size(); i++) {
      if (a[b.back()] < a[i]) {
         p[i] = b.back();
	 b.push_back (i);
	 continue;
      }

      for (u = 0, v = b.size() - 1; u < v;) {
         int c = (u+v) / 2;
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
   int n, temp = 0;
   vector<int> h;
   vector<int> result;
   char c;
   bool first = true;

   cin >> n;
   getchar(); // \n
   getchar(); // \n

   while ((c = getchar()) != EOF) {
      if (c == '\n') {
         h.push_back (temp);

	 if (cin.peek() == '\n' || cin.peek() == EOF) {
	    getchar();
            result = find_LIS (h);

            if (!first) cout << endl;
            cout << "Max hits: " << result.size() << endl;
	    for (int i = 0; i < result.size(); i++)
	       cout << h[result[i]] << endl;

	    first = false;

	    h.clear();
	    result.clear();
	 }

	 temp = 0;
      } else {
         temp = temp * 10 + c - '0';
      }
   }


   return 0;
}
