#include <stdio.h>

int main() {
   int n, a, f, i, j, k, u;

   scanf("%d", &n);

   for (u = 0; u < n; u++) {
      if (u > 0) printf("\n");

      scanf("%d %d", &a, &f);

      for (i = 1; i <= f; i++) {
         if (i > 1) printf("\n");
         for (j = 1; j <= a; j++) {
            for (k = 1; k <= j; k++) {
               printf("%d", j);
	    }
	    printf("\n");
	 }

	 for (j = a - 1; j >= 1; j--) {
            for (k = 1; k <= j; k++) {
               printf("%d", j);
	    }
	    printf("\n");
	 }
      }
   }


   return 0;
}
