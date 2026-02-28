// S2 18870: 좌표 압축(정렬)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int i; // id: 입력 순서
    int v;
};

int asc_i(const void* u,const void* v){return ((struct node*)u)->i-((struct node*)v)->i;}
int asc_v(const void* u,const void* v){return ((struct node*)u)->v-((struct node*)v)->v;}

int main(void){
    int j;
    int n; scanf("%d",&n);
    int v;
    int i=0; // 압축 좌표
    struct node* a=(struct node*)malloc(sizeof(struct node)*n);
    int* t=(int*)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){
        scanf("%d",&v);
        a[j].i=j;
        a[j].v=v;
    }

    qsort(a,n,sizeof(struct node),asc_v);

    t[0]=i;
    for(j=1;j<n;j++){
        if(a[j].v==a[j-1].v){t[j]=i;}
        else                {t[j]=++i;}
    }
    for(j=0;j<n;j++){
        a[j].v=t[j];
    }

    qsort(a,n,sizeof(struct node),asc_i);
    for(j=0;j<n;j++){printf("%d ",a[j].v);}
    free(a);
    free(t);
}