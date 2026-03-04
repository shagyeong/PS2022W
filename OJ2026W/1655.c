// G2 1655: 가운데를 말해요(힙)
#include<stdio.h>
#include<stdlib.h>

struct heap{
    int* a;
    int  n;
};

void maxpush(struct heap* h,int v);
void minpush(struct heap* h,int v);
int   maxpop(struct heap* h);
int   minpop(struct heap* h);

int main(void){
    int j;
    int n; scanf("%d",&n);
    int v;
    struct heap max; max.n=0; max.a=(int*)malloc(sizeof(int)*(n/2+4));
    struct heap min; min.n=0; min.a=(int*)malloc(sizeof(int)*(n/2+4));

    for(j=0;j<n;j++){
        scanf("%d",&v);
        if(j%2==0){maxpush(&max,v);}
        else      {minpush(&min,v);}
        if((max.n>=1)&&(min.n>=1)&&(max.a[1]>min.a[1])){
            minpush(&min,maxpop(&max));
            maxpush(&max,minpop(&min));
        }
        printf("%d\n",max.a[1]);
    }
    free(max.a);
    free(min.a);
}

void maxpush(struct heap* h,int v){
    int i=++h->n;
    int t;
    h->a[i]=v;
    while((i>1)&&(h->a[i]>h->a[i/2])){
        t=h->a[i];
        h->a[i]=h->a[i/2];
        h->a[i/2]=t;
        i/=2;
    }
}
void minpush(struct heap* h,int v){
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
int   maxpop(struct heap* h){
    int i=1;
    int t;
    int r=h->a[i];
    int c;
    h->a[i]=h->a[h->n--];
    while(i*2<=h->n){
        if((i*2+1<=h->n)&&(h->a[i*2+1]>h->a[i*2])){c=i*2+1;}
        else                                      {c=i*2;}
        if(h->a[i]>=h->a[c]){break;}
        t=h->a[i];
        h->a[i]=h->a[c];
        h->a[c]=t;
        i=c;
    }
    return r;
}
int   minpop(struct heap* h){
    int i=1;
    int t;
    int r=h->a[i];
    int c;
    h->a[i]=h->a[h->n--];
    while(i*2<=h->n){
        if((i*2+1<=h->n)&&(h->a[i*2+1]<h->a[i*2])){c=i*2+1;}
        else                                      {c=i*2;}
        if(h->a[i]<=h->a[c]){break;}
        t=h->a[i];
        h->a[i]=h->a[c];
        h->a[c]=t;
        i=c;
    }
    return r;
}