// S3 15654: N과 M (5)(재귀,백트래킹,정렬)
#include<stdio.h>

#define UNV 0 // unvisted
#define VIS 1 // visted

short a[10001]; // 테스트케이스
short t[10001]; // temp
short v[10001]; // 방문 상태
short n;
short m;
void backtrack(short d);
void mergesort(short s,        short e);
void merge    (short s,short m,short e);

int main(void){
    short j; // loop variable
    scanf("%hd %hd",&n,&m);
    for(j=1;j<=n;j++){scanf("%hd",&a[j]);v[j]=0;}
    mergesort(1,n);
    backtrack(0);
}

void backtrack(short d){
    short j; // loop variable
    if(d==m){
        for(j=0;j<m;j++){printf("%u ",t[j]);}
        printf("\n");
    }
    else{
        for(j=1;j<=n;j++){
            if(v[j]==UNV){
                v[j]=VIS;
                t[d]=a[j];
                backtrack(d+1);
                v[j]=UNV;
            }
        }
    }
}
void mergesort(short s,        short e){
    if(s<e){
        short m=(s+e)/2;
        mergesort(s,  m);
        mergesort(m+1,e);
        merge(s,m,e);
    }
}
void merge    (short s,short m,short e){
    short i;
    short j;
    short k;
    short L=m-s+1;short l[L];
    short R=e-m;  short r[R];
    for(i=0;i<L;i++){l[i]=a[s+i];}
    for(i=0;i<R;i++){r[i]=a[m+1+i];}
    i=0;j=0;k=s;
    while(i<L&&j<R){
        if(l[i]<r[j]){a[k++]=l[i++];}
        else{         a[k++]=r[j++];}
    }
    while(i<L){a[k++]=l[i++];}
    while(j<R){a[k++]=r[j++];}
}