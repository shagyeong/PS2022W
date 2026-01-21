// G3 2473: 세 용액(투포인터)
#include<stdio.h>
#include<stdlib.h>

long long int absolute(long long int i){return (i>0)?i:-i;}
int compare(const void* u,const void* v){
    if((*((int*)u))<(*((int*)v))){return -1;}
    if((*((int*)u))>(*((int*)v))){return  1;}
    return 0;
}

int main(void){
    int j; // loop variable
    int l; // left
    int r; // right
    int u=0; // 정답 위치: 좌측 고정점
    int v=1; // 정답 위치(left)
    int w; // 정답 위치(right)
    long long int m; // min: 최소값
    long long int s; // sum
    int n;scanf("%d",&n); w=n-1;
    int a[n];
    for(j=0;j<n;j++){scanf("%d",&a[j]);}
    qsort(&a[0],n,sizeof(int),compare);

    m=absolute((long long int)a[u]+a[v]+a[w]);
    for(j=0;j<n-2;j++){
        l=j+1;
        r=n-1;
        while(l<r){
            s=(long long int)a[j]+a[l]+a[r];
            if(absolute(s)<m){
                m=absolute(s);
                u=j;
                v=l;
                w=r;
            }
            if     (s<0){l++;}
            else if(s>0){r--;}
            else        {goto escape;} // 조기종료
        }
    }
    escape:
    printf("%d %d %d",a[u],a[v],a[w]);
}