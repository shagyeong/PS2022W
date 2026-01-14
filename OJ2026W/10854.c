// P1 10854: Divisions약수 개수 구하기(밀러-라빈,폴라드로,소인수분해)
#include<stdio.h>
#include<stdlib.h> // rand(), qsort()

unsigned long long int p[64]; // 소인수
int                    e[64]; // 소인수 차수
int t;
int c;

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
    int a=1; // answer: number of division
    int j;
    unsigned long long int n; scanf("%llu",&n);
    t=0; pr(n);
    qsort(&p[0],t,sizeof(unsigned long long int),compare);
    
    if(n==1){printf("1"); return 0;}
    if(t==1){printf("2"); return 0;} // 소수
        for(j=0;j<t;j++){e[j]=0;}
        e[0]=1;
        c=0;
        for(j=1;j<t;j++){
            if(p[j]==p[j-1]){e[  c]++;}
            else            {e[++c]++;}
        }
        for(j=0;j<=c;j++){
            a*=(e[j]+1);
        }
        printf("%d",a);
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