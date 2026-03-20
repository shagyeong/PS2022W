// G1 11003: 최소값 찾기(투포인터,슬라이딩윈도우,데크최대값트릭)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int v;
    int i; // 입력 순서
};

int main(void){
    int j;
    int n; int l; scanf("%d %d",&n,&l);
    int v;
    struct node* d=(struct node*)malloc(sizeof(struct node)*n);
    int f=0;
    int r=0;
    for(j=0;j<n;j++){
        scanf("%d",&v);
        while((f<r)&&(v<=d[r-1].v)){r--;}
        d[r].v=v; d[r++].i=j;
        if(d[f].i<=j-l){f++;}
        printf("%d ",d[f].v);
    }
    free(d);
}