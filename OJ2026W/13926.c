// D5 13926: gcd(n,k)=1(오일러피함수,밀러-라빈,폴라드로)
#include<stdio.h>
#include<stdlib.h> // rand()

unsigned long long int p[64]; // 소인수
int t;

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
void phi(unsigned long long int n); // 전역 소인수 배열 조작

int main(void){
    unsigned long long int n; scanf("%llu",&n);
    t=0; pr(n);
    phi(n);
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
void phi(unsigned long long int n){
    int j; // loop variable
    unsigned long long int r; // rsult: phi(n)
    unsigned long long int q; /// quotient
    r=n; q=n;
    for(j=0;j<t;j++){
        if(q%p[j]==0){
            r-=r/p[j];
            while(q%p[j]==0){q/=p[j];}
        }
    }
    if(q>1){r-=(r/q);}
    printf("%llu",r);
}