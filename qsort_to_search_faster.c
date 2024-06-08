#include <stdio.h>
#include <stdlib.h>
int Search(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
    int imcp(const void *a,const void *b){
        return ( *(int*)a - *(int*)b );
    }
int main() {
    int n,i,m,j;
    scanf("%d",&n);
    int *a;
    a = (int*)malloc(n*sizeof(int));
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);}
    qsort(a,n,sizeof(int),imcp);
    getchar();
    scanf("%d",&m);
    int *b;
    b = (int*)malloc(m*sizeof(int));
    for (i=0;i<m;i++){
        scanf("%d",&b[i]);
        if (Search(a,1,n,b[i])==-1) printf("0\n"); else printf("1\n");}
    free(a);free(b);
    return 0;
}