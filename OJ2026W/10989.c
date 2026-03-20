// B1 10989: 수 정렬하기 3(정렬)
// 계수정렬
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; scanf("%d",&n);
    int v;
    int* a=(int*)calloc(10001,sizeof(int));
    for(j=0;j<n;j++){scanf("%d",&v);a[v]++;}
    for(j=1;j<=10000;j++){while(a[j]-->0){printf("%d\n",j);}}
    free(a);
}