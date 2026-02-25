// S5 1417: 국회의원 선거(구현,시뮬레이션,힙)
#include<stdio.h>
#include<stdlib.h>

struct heap{
    int* a;
    int n;
};

void push(struct heap* h,int v);
int   pop(struct heap* h);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int v;
    int c=0; // answer
    int d; scanf("%d",&d); if(n==1){printf("0"); return 0;}
    struct heap h;
    h.a=(int*)malloc(sizeof(int)*(n+1));
    h.a[0]=-1;
    h.n=0;
    
    for(j=2;j<=n;j++){
        scanf("%d",&v);
        push(&h,v);
    }

    while(1){
        v=pop(&h);
        if(d>v){break;}
        d+=1; c+=1; v-=1;
        push(&h,v);
    }

    printf("%d",c);
    free(h.a);
    return 0;
}

void push(struct heap* h,int v){
    int i=++(h->n);
    int t;
    h->a[i]=v;
    while((i>1)&&(h->a[i]>h->a[i/2])){
        t=h->a[i];
        h->a[i]=h->a[i/2];
        h->a[i/2]=t;
        i/=2;
    }
}
int   pop(struct heap* h){
    int i=1;
    int r=h->a[i];
    int t;
    int c;

    h->a[i]=h->a[h->n--];
    while(i*2<=h->n){
        if(i*2+1<=h->n&&h->a[i*2]<h->a[i*2+1]){c=i*2+1;}
        else                                  {c=i*2;}
        if(h->a[i]>=h->a[c]){break;}
        t=h->a[i];
        h->a[i]=h->a[c];
        h->a[c]=t;
        i=c;
    }
    return r;
}