// D5 7501: Key(밀러-라빈,윌슨의정리)
#include<stdio.h>

unsigned long long int power(
    unsigned long long int b,
    unsigned long long int e,
    unsigned long long int q
);
int mr( // Miller-Rabin
    unsigned long long int n
);

int main(void){
    unsigned long long int j;
    unsigned long long int a; scanf("%llu",&a);
    unsigned long long int b; scanf("%llu",&b);
    if(a%2==0){a+=1;}

    for(j=a;j<=b;j+=2){if((mr(j)==1)||(j==9)){printf("%lld ",j);}}
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