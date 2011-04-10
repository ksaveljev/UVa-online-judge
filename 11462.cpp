#include <cstdio>
#include <cstdlib>
using namespace std;

int theTruthIsOutThere(const void *a, const void *b) {
  return ( *(int*)a - *(int*)b );
}

int main(void) {
  int n, i;
  int *v = new int[2000001];

  while (scanf("%d", &n)) {
    if (n == 0)
      break;

    for (i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }

    qsort(v, n, sizeof(int), theTruthIsOutThere);

    for (i = 0; i < n; i++) {
      if (i > 0)
        printf(" ");
      printf("%d", v[i]);
    }
    printf("\n");
  }


  delete [] v;

  return 0;
}
