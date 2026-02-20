// S4 1026: 보물(그리디,정렬)
#include<stdio.h>
#include<stdlib.h>

int asc(const void* u,const void* v){return *((int*)u)-*((int*)v);}
int des(const void* u,const void* v){return *((int*)v)-*((int*)u);}

int main(void){
    int j;
    int n; scanf("%d",&n);
    int s=0;
    int* a=(int*)malloc(sizeof(int)*n);
    int* b=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    for(j=0;j<n;j++){scanf("%d",&b[j]);}
    qsort(a,n,sizeof(int),asc);
    qsort(b,n,sizeof(int),des);
    
    for(j=0;j<n;j++){s+=a[j]*b[j];}
    printf("%d",s);
    free(a);
    free(b);
}