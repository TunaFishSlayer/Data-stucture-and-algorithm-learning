#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HLEFT(i) (((i) << 1) + 1)
#define HRIGHT(i) (((i) << 1) + 2)
typedef struct string{
    char ch[30];
    int num;
} str;
#define SWAP(a, b) { str _tmp = (a); (a) = (b); (b) = _tmp; }
void heap_shift_down(long i, long n, str *a) {
  for (;;) {
    long lc = HLEFT(i), rc = HRIGHT(i), root = i;
    if (lc < n && a[root].num < a[lc].num) {
      root = lc;
    }
    if (rc < n && a[root].num < a[rc].num) {
      root = rc;
    }
    if (lc < n && a[root].num == a[lc].num)
        if (strcmp(a[root].ch,a[lc].ch) > 0 ) root = lc;
    if (rc < n && a[root].num == a[rc].num)
        if (strcmp(a[root].ch,a[rc].ch) > 0 ) root = rc;
    if (root == i) {
      break;
    }
    SWAP(a[i], a[root]);
    i = root;
  }
}
void heap_make(long n, str *a) {
  for (long i = n / 2; i >= 0; --i) {
    heap_shift_down(i, n, a);
  }
}
int main() {
    int n,k,i;
    scanf("%d %d",&k,&n);
    str *a;
    a = (str*)malloc(n*sizeof(str));
    getchar();
    for (i=0;i<n;++i){
        scanf("%s %d",a[i].ch,&a[i].num);}
    heap_make(n, a);
    for (i = 0; i < k; ++i) {
        printf("%s %d\n",a[0].ch,a[0].num);
        SWAP(a[0], a[n - i - 1]);
        heap_shift_down(0, n - i - 1, a);
    }
    free(a);
}

