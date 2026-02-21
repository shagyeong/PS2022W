// G2 2437: 저울(그리디,정렬)
#include<stdio.h>
#include<stdlib.h>

int asc(const void* u,const void* v){return *((int*)u)-*((int*)v);}

int main(void){
    int j;
    int n; scanf("%d",&n);
    int w=1; // answer
    int* a=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    qsort(a,n,sizeof(int),asc);

    for(j=0;j<n;j++){
        if(w<a[j]){break;}
        else      {w+=a[j];}
    }
    
    printf("%d",w);
    free(a);
}