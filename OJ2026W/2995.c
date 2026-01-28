// P4 2995: 생일(LIS,역추적)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int l;
    int r;
};

int compare(const void* u,const void* v);

int main(void){
    int j;
    int n; scanf("%d",&n);
    struct node* a=(struct node*)malloc(sizeof(struct node)*n);
    int* t=(int*)malloc(sizeof(int)*n);
    int* p=(int*)malloc(sizeof(int)*n);
    struct node* q; // 역추적 결과 저장
    int s=0;
    int l; int m; int r;
    int i; int e;

    for(j=0;j<n;j++){scanf("%d %d",&a[j].l,&a[j].r);}
    qsort(&a[0],n,sizeof(struct node),compare);

    for(j=0;j<n;j++){
        l=0;
        r=s-1;
        i=-1;
        while(l<=r){
            m=(l+r)/2;
            if(a[j].r<=t[m]){l=m+1;}
            else            {r=m-1; i=m;}
        }
        if(i==-1){p[j]=s; t[s++]=a[j].r;}
        else     {p[j]=i; t[i  ]=a[j].r;}
    }

    e=s-1;
    q=(struct node*)malloc(sizeof(struct node)*s);
    for(j=n-1;j>=0;j--){
        if(p[j]==e){
            q[e  ].l=a[j].l;
            q[e--].r=a[j].r;
        }
    }
    printf("%d\n",s);
    for(j=0;j<s;j++){printf("%d %d\n",q[j].l,q[j].r);}
};

int compare(const void* u,const void* v){
    if((((struct node*)u)->l)< (((struct node*)v)->l)){return -1;}
    if((((struct node*)u)->l)> (((struct node*)v)->l)){return  1;}
    if((((struct node*)u)->l)==(((struct node*)v)->l)){
        if((((struct node*)u)->r)>(((struct node*)v)->r)){return -1;}
        if((((struct node*)u)->r)<(((struct node*)v)->r)){return  1;}
    }
    return 0;
}