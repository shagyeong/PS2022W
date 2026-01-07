// G2 1365: 꼬인 전깃줄(정렬,LIS)
#include<stdio.h>
#include<stdlib.h> // qsort()

struct line{
    int l;
    int r;
};

int compare(const void *u,const void *v);

int main(void){
    int j; // loop variable
    int l;
    int r;
    int n;
    int s=0; // length of LIS
    int m; // middle
    int i; // location
    scanf("%d",&n);
    struct line a[n];
    struct line t[n]; // tmp: LIS

    for(j=0;j<n;j++){
        scanf("%d",&r);
        a[j].l=j;
        a[j].r=r;
    }
    qsort(a,n,sizeof(struct line),compare);
    
    // 이분 탐색 LIS
    for(j=0;j<n;j++){
        l=0;
        r=s-1;
        i=-1;
        while(l<=r){
            m=(l+r)/2;
            if(t[m].r<a[j].r){l=m+1;}
            else         {i=m;r=m-1;}
        }
        if(i==-1){t[s++].r=a[j].r;}
        else     {t[i].r=a[j].r;}
    }
    printf("%d",n-s);
}
int compare(const void* u,const void* v){
    if((((struct line*)u)->l)<(((struct line*)v)->l)){return -1;}
    if((((struct line*)u)->l)>(((struct line*)v)->l)){return 1;}
    return 0;
}