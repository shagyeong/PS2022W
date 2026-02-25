// S2 31860: 열심히 일하는 중(시뮬레이션,힙)
#include<stdio.h>
#include<stdlib.h>

struct heap{
    int* a;
    int  n;
};

void push(struct heap* h,int v);
int   pop(struct heap* h);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int m; scanf("%d",&m);
    int k; scanf("%d",&k);
    int v;
    int tim=0; // timer
    int ans=0; // answer
    int* seq=(int*)malloc(sizeof(int)*2000000);
    int i=0; // 정답열 인덱스

    struct heap h;
    h.a=(int*)malloc(sizeof(int)*(n+1));
    h.n=0;

    for(j=0;j<n;j++){
        scanf("%d",&v);
        push(&h,v);
    }

    while(1){
        v=pop(&h);
        if(v<=k){break;}
        tim+=1;
        ans=(ans/2)+v; seq[i++]=ans;
        v-=m;
        push(&h,v);
    }

    printf("%d\n",tim);
    for(j=0;j<i;j++){printf("%d\n",seq[j]);}

    free(seq);
    free(h.a);
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
int pop(struct heap* h){
    int r=h->a[1];
    int i=1;
    int t;
    int c;
    
    h->a[i]=h->a[h->n--];
    while(i*2<=h->n){
        if((2*i+1<=h->n)&&(h->a[2*i+1]>h->a[2*i])){c=2*i+1;}
        else                                      {c=2*i;}
        if(h->a[i]>=h->a[c]){break;}
        t=h->a[i];
        h->a[i]=h->a[c];
        h->a[c]=t;
        i=c;
    }
    return r;
}