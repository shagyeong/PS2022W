// P5 2568: 전깃줄 - 2(LIS,정렬)
#include<stdio.h>
#include<stdlib.h> //qsort

struct line{
    int l;
    int r;
};

int compare(const void* u,const void* v);

int main(void){
    int j; // loop variable
    int l;
    int r;
    int n;
    int s=0; // length of LIS
    int m; // middle
    int i; // location
    scanf("%d",&n);
    struct line a[n+1]; // n+1: 1부터 시작하는 과제 환경
    int t[n+1]; // tmp: LIS 길이 작성용
    int p[n+1]; // position: 역추적용
    int e; // 역추적용
    a[0].l=-1; // 정렬로 인한 오염 방지
    a[0].r=-1;
    for(j=1;j<=n;j++){
        scanf("%d %d",&l,&r);
        a[j].l=l;
        a[j].r=r;
    }
    qsort(a,n+1,sizeof(struct line),compare);

    // LIS 길이 작성
    for(j=1;j<=n;j++){
        l=0;
        r=s-1;
        i=-1;
        while(l<=r){
            m=(l+r)/2;
            if(t[m]<a[j].r){l=m+1;}
            else           {i=m; r=m-1;}
        }
        if(i==-1){p[j]=s; t[s++]=a[j].r;}
        else     {p[j]=i; t[i  ]=a[j].r;}   
    }
    
    // 역추적
    e=s-1;
    for(j=n;j>0;j--){
        if(p[j]==e){
            a[j].l=-1; // 제거 전선 마크
            e--;
        }
    }

    // 결과 출력
    printf("%d\n",n-s);
    for(j=1;j<=n;j++){
        if(a[j].l==-1){continue;}
        else          {printf("%d\n",a[j].l);}
    }
}
int compare(const void* u,const void* v){
    if((((struct line*)u)->l)<(((struct line*)v)->l)){return -1;}
    if((((struct line*)u)->l)>(((struct line*)v)->l)){return 1;}
    return 0;
}