// P5 2618: 경찰차(DP,역추적)
#include<stdio.h>

struct node{
    int r;
    int c;
};

// Manhattan distance
int dist(struct node A,struct node B){
    int d;
    d= (A.r>B.r)?(A.r-B.r):(B.r-A.r);
    d+=(A.c>B.c)?(A.c-B.c):(B.c-A.c);
    return d;
}

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int w; scanf("%d",&w);
    int t[w+2][w+2]; // table
    int b[w+2][w+2]; // backtracking
    int r; int c;
    int d;
    struct node a[w+2];

    // 테이블 초기화
    for(j=0;j<w+2;j++){for(k=0;k<w+2;k++){t[j][k]=0;}}
    for(j=2;j<w+2;j++){scanf("%d %d",&a[j].r,&a[j].c);}
    a[0].r=1; a[0].c=1;
    a[1].r=n; a[1].c=n;

    // 점화식
    for(j=w;j>=0;j--){
        for(k=w;k>=0;k--){
            if((j==k)&&(j!=0)){continue;}
            d=(j>k)?(j+1):(k+1); if(d>=w+2){continue;}
            r=t[d][k]+dist(a[j],a[d]);
            c=t[j][d]+dist(a[k],a[d]);
            if(r<c){t[j][k]=r; b[j][k]=1;}
            else   {t[j][k]=c; b[j][k]=2;}
        }
    }
    printf("%d\n",t[0][1]);
    
    // 역추적
    r=0;
    c=1;
    for(j=0;j<w;j++){
        d=b[r][c];
        printf("%d\n",d);
        if(d==1){r=(r>c)?(r+1):(c+1);}
        else    {c=(r>c)?(r+1):(c+1);}
    }
}