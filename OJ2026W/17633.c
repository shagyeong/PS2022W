// D3 17633: 제곱수의 합(밀러-라빈,폴라드로,르장드르정리,페르마정리)
#include<stdio.h>
#include<stdlib.h> // rand(), qsort()

unsigned long long int p[64]; // 소인수
int t;

int compare(const void* u,const void* v);
unsigned long long int power(
    unsigned long long int b,
    unsigned long long int e,
    unsigned long long int q
);
unsigned long long int gcd(
    unsigned long long int a,
    unsigned long long int b
);
int mr( // Miller-Rabin
    unsigned long long int n
);
void pr( // Phollard's rho
    unsigned long long int n
);

int main(void){
    int j; // loop variable
    int f; // flag
    int c; // count
    unsigned long long int l; // left(이진탐색)
    unsigned long long int m; // middle(이진탐색)
    unsigned long long int r; // right(이진탐색)
    unsigned long long int d; // dummy
    unsigned long long int n; scanf("%llu",&n);

    // 이진 탐색 제곱수 판정
    f=0; // 제곱수 아님
    l=1;
    r=1000000000; // 10^(18/2)
    while(l<=r){
        m=l+(r-l)/2;
        if(m==0)        {l=1;          continue;}
        if(m>1000000000){r=1000000000; continue;}
        d=m*m;
        if(d==n){f=1; break;}
        if(d< n){l=m+1;}
        else    {r=m-1;}
    }
    if(f==1){printf("1"); return 0;}

    // 르장드르정리
    d=n;
    while((d>0)&&(d%4==0)){d/=4;}
    if(d%8==7){printf("4"); return 0;}
    
    // 페르마정리
    t=0; pr(n);
    qsort(&p[0],t,sizeof(unsigned long long int),compare);
    f=0; j=0;
    while(j<t){
        d=p[j];
        c=0;
        while((j<t)&&(p[j]==d)){
            c++;
            j++;
        }
        if((d%4==3)&&(c%2!=0)){
            f=1;
            break;
        }
    }
    if(f==0){printf("2");}
    else    {printf("3");}
    return 0;
}
int compare(const void* u,const void* v){
    if((*((unsigned long long int*)u))<(*((unsigned long long int*)v))){return -1;}
    if((*((unsigned long long int*)u))>(*((unsigned long long int*)v))){return 1;}
    return 0;
}
unsigned long long int power(unsigned long long int b,unsigned long long int e,unsigned long long int q){
    unsigned long long int r = 1; // return value
    b%=q;
    while(e>0){
        if(e%2==1){r=(unsigned long long int)(((__int128)r*b)%q);}
        b=           (unsigned long long int)(((__int128)b*b)%q);
        e/=2;
    }
    return r;
}
unsigned long long int gcd(unsigned long long int a,unsigned long long int b){
    unsigned long long int t; // tmp
    while(b!=0){a%=b;t=a;a=b;b=t;}
    return a;
}
int mr(unsigned long long int n){
    if(n==2||n==3)  {return 1;}
    if(n==1||n%2==0){return 0;}
    unsigned long long int a[12]={2,3,5,7,11,13,17,19,23,29,31,37};
    unsigned long long int d=n-1;
    unsigned long long int x;
    int                    s=0;
    int                    j; // loop variable
    int                    k; // loop variable
    int                    f; // prime flag

    while(d%2==0){d/=2;s++;} 
    for(j=0;j<12;j++){
        if(n<=a[j]){break;}
        x=power(a[j],d,n);
        if((x==1)||(x==n-1)){continue;}
        f=0;
        for(k=1;k<s;k++){
            x=(unsigned long long int)(((__int128)x*x)%n);
            if(x==n-1){f=1;break;}
        }
        if(f==0){return 0;}
    }
    return 1;
}
void pr(unsigned long long int n){
    if(n==1) {return;}
    if(mr(n)){p[t++]=n; return;}
    if(n%2==0){
        p[t++]=2;
        pr(n/2);
        return;
    }

    unsigned long long int x;
    unsigned long long int y;
    unsigned long long int c;
    unsigned long long int g;
    unsigned long long int d;

    x=rand()%(n-2)+2;
    y=x;
    c=rand()%(n-1)+1;
    g=1;
    
    while(g==1){
        x=(unsigned long long int)(((__int128)x*x+c)%n);
        y=(unsigned long long int)(((__int128)y*y+c)%n);
        y=(unsigned long long int)(((__int128)y*y+c)%n);
        d=(x>y)?x-y:y-x;
        g=gcd(d,n);
        if(g==n){
            pr(n);
            return;
        }
    }

    pr(g);
    pr(n/g);
}