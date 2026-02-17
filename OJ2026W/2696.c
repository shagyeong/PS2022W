// G2 2696: 중앙값 구하기(힙)
#include<stdio.h>
#include<stdlib.h>

struct heap{
    int* a;
    int n;
};

void maxpush(struct heap* h,int v);
void minpush(struct heap* h,int v);
int   maxpop(struct heap* h);
int   minpop(struct heap* h);

int main(void){
    int j; int k;
    int t; scanf("%d",&t);
    int n;
    int v; // push dummy
    struct heap max; max.a=(int*)malloc(sizeof(int)*10000);
    struct heap min; min.a=(int*)malloc(sizeof(int)*10000);

    for(j=0;j<t;j++){
        max.n=0;
        min.n=0;
        scanf("%d",&n); printf("%d\n",(n+1)/2);
        for(k=0;k<n;k++){
            scanf("%d",&v);
            if(max.n==min.n){maxpush(&max,v);}
            else            {minpush(&min,v);}
            if((max.n>=1)&&(min.n>=1)&&(max.a[1]>min.a[1])){
                minpush(&min,maxpop(&max));
                maxpush(&max,minpop(&min));
            }
            if(k%2==0){printf("%d ",max.a[1]);}
            if((k+2)%20==0){printf("\n");}
        }
        if((k+1)%20!=0){printf("\n");} // 중복줄바꿈 방지
    }
    
    free(max.a);
    free(min.a);
}

void maxpush(struct heap* h,int v){
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
void minpush(struct heap* h,int v){
    int i=++(h->n);
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
    int r=h->a[1];
    int i=1;
    int t;
    int c;
    h->a[i]=h->a[(h->n)--];
    while(i*2<=h->n){
        if((i*2+1<=h->n)&&(h->a[i*2+1]>h->a[i*2])){c=2*i+1;}
        else                                      {c=2*i;}
        if(h->a[i]>=h->a[c]){break;}
        t=h->a[i];
        h->a[i]=h->a[c];
        h->a[c]=t;
        i=c;
    }
    return r;
}
int   minpop(struct heap* h){
    int r=h->a[1];
    int i=1;
    int t;
    int c;
    h->a[i]=h->a[(h->n)--];
    while(i*2<=h->n){
        if((i*2+1<=h->n)&&(h->a[i*2+1]<h->a[i*2])){c=2*i+1;}
        else                                      {c=2*i;}
        if(h->a[i]<=h->a[c]){break;}
        t=h->a[i];
        h->a[i]=h->a[c];
        h->a[c]=t;
        i=c;
    }
    return r;
}