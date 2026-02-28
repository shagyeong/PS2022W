// G2 1781: 컵라면(그리디,정렬,힙)
#include<stdio.h>
#include<stdlib.h>

struct node{
    int d; // deadline
    int v; // number of 컵라면
};

struct heap{
    int* a;
    int n;
};

void push(struct heap* h,int v);
int   pop(struct heap* h);
int compare(const void* u,const void* v);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int w=0; // answer
    struct node* a=(struct node*)malloc(sizeof(struct node)*n);
    struct heap h;
    h.a=(int*)malloc(sizeof(int)*(n+1));
    h.n=0;


    for(j=0;j<n;j++){
        scanf("%d",&a[j].d);
        scanf("%d",&a[j].v);
    }
    qsort(a,n,sizeof(struct node),compare);

    for(j=0;j<n;j++){
        if(h.n<a[j].d){
            push(&h,a[j].v);
        }
        else{
            if(h.a[1]<a[j].v){
                pop(&h);
                push(&h,a[j].v);
            }
        }
    }

    for(j=1;j<=h.n;j++){w+=h.a[j];}
    printf("%d",w);

    free(h.a);
    free(a);
}

void push(struct heap* h,int v){
    int i=++h->n;
    int t;
    h->a[i]=v;
    while((i>1)&&(h->a[i]<h->a[i/2])){
        t=h->a[i];
        h->a[i]=h->a[i/2];
        h->a[i/2]=t;
        i/=2;
    }
}
int   pop(struct heap* h){
    int i=1;
    int t;
    int r=h->a[i];
    int c;

    h->a[i]=h->a[h->n--];
    while(i*2<=h->n){
        if(i*2+1<=h->n&&h->a[i*2+1]<h->a[i*2]){c=i*2+1;}
        else                                  {c=i*2;}
        if(h->a[c]>=h->a[i]){break;}
        t=h->a[i];
        h->a[i]=h->a[c];
        h->a[c]=t;
        i=c;
    }
    return r;
}
int compare(const void* u,const void* v){
    if(((struct node*)u)->d< ((struct node*)v)->d){return -1;}
    if(((struct node*)u)->d> ((struct node*)v)->d){return  1;}
    if(((struct node*)u)->d==((struct node*)v)->d){
        if(((struct node*)u)->v> ((struct node*)v)->v){return -1;}
        if(((struct node*)u)->v< ((struct node*)v)->v){return  1;}
    }
    return 0;
}