// S1 20922: 겹치는 건 싫어(투포인터)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int n; int m; scanf("%d %d",&n,&m);
    int* a=(int*)malloc(sizeof(int)*n); for(j=0;j<n;j++){scanf("%d",&a[j]);}
    int* b=(int*)calloc(100001,sizeof(int));
    int f=0; // front
    int r=0; // rear
    int l=1; // length
    int x=l; // max of length
    b[a[r]]++;
    while(1){
        r++;
        if(r==n){break;}
        if(++b[a[r]]<=m){l+=1; if(l>x){x=l;} continue;}
        else{
            for(j=f;j<r;j++){
                b[a[j]]=0;
            }
            f++;
            r=f;
            b[a[r]]=1;
            l=1;
        }
    }
    printf("%d",x);
    free(a);
    free(b);
}