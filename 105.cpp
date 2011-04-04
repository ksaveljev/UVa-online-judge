#include <iostream>
#include <stdlib.h>
using namespace std;

int main (void) {
   int l,h,r;
   int *b;
   int beginning = -1, ending = -1;

   b = (int*)malloc(sizeof(int)*20002);
   memset(b, 0, sizeof(int) * 20002);

   while (cin >> l >> h >> r) {
      if (l == r) continue;
      if (beginning == -1) beginning = l * 2;
      if (r * 2 > ending) ending = r * 2;

      for (int i = l * 2; i <= r * 2; i++) {
         if (b[i] < h)
	    b[i] = h;
      }
   }

   int current_height = -1;

   for (int i = beginning; i <= ending; i++) {
      if (current_height != b[i]) {
         cout << i / 2 << " ";
	 cout << b[i] << " ";
	 current_height = b[i];
      }
   }

   cout << ending / 2 << " " << 0 << endl;


   free(b);

   return 0;
}
