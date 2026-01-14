// G1 4355: 서로소(오일러피함수)
#include<stdio.h>
#include<math.h>

int main(void){
    long long int r; // result: phi(n)
    long long int j; // loop variable
    long long int p; // prime number
    long long int n;
    long long int q; // quotient
    long long int s=0; // sqrt(n)+1
    
    scanf("%lld",&n);

    while(n!=0){
    if(n==1){printf("0\n");scanf("%lld",&n);continue;}
    while(s*s<=n){s++;}

    long long int a[s+1];
    for(j=0;j<=s;j++){a[j]=j;}
    for(p=2;p<=s;p++){
        if(a[p]!=p)              {continue;}
        else{for(j=p*p;j<=s;j+=p){a[j]=0;}} // 합성수 마크
    }

    r=n; q=n;
    for(j=2;j<=s;j++){
        if((a[j]!=0)&&(q%a[j]==0)){
            r-=r/a[j];
            while(q%a[j]==0){q/=a[j];}
        }
    }
    if(q>1){r-=(r/q);}
    printf("%lld\n",r);
    scanf("%lld",&n);
    }
}