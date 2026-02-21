// S4 2217: 로프(그리디,정렬)
#include<stdio.h>
#include<stdlib.h>

int dsc(const void* u,const void* v){return *((int*)v)-*((int*)u);}

int main(void){
    int j;
    int n; scanf("%d",&n);
    int m; // max
    int w=0;
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    qsort(a,n,sizeof(int),dsc);

    m=w=a[0];
    for(j=1;j<n;j++){
        if(w<=a[j]*(j+1)){w=a[j]*(j+1);}
        if(m<w){m=w;}
    }
    printf("%d",m);
    free(a);
}