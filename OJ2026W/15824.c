// G2 15824: 너 봄에는 캡사이신이 맛있단다(조합론,분할정복거듭제곱)
#include<stdio.h>
#include<stdlib.h>

#define D 1000000007 // divisor

int compare(const void* u,const void* v);
long long int power(long long int b,long long int e);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    long long int w=0; // answer
    long long int s=0; // 합
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    qsort(a,n,sizeof(int),compare);

    for(j=0;j<n;j++){s+=a[j]*power(2,j);    s%=D;}w+=s; s=0;
    for(j=0;j<n;j++){s+=a[j]*power(2,n-1-j);s%=D;}w-=s;
    w+=D; w%=D;
    printf("%lld",w);
    free(a);
}

int compare(const void* u,const void* v){
    if((*((int*)u))<(*((int*)v))){return -1;}
    if((*((int*)u))>(*((int*)v))){return  1;}
    return 0;
}

long long int power(long long int b,long long int e){
    if(e==0){return 1;}
    if(e==1){return b;}
    long long int t;
    if(e%2==0){t=power(b,e/2);     return (t*t)%D;}
    else      {t=power(b,(e-1)/2); return (((t*t)%D)*b)%D;}
}