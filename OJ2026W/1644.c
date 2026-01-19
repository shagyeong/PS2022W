// G3 1644: 소수의 연속합(소수판정,투포인터,비트마스킹)
#include<stdio.h>
#include<string.h>

char a[500001]; // 비트필드 소수 테이블: 4,000,000/8=500,000
int  p[283146]; // 4,000,000까지 소수 개수
int  c;         // 소수 개수

void sieve(int n);

int main(void){
    int t; scanf("%d",&t);
    if(t==1){printf("0"); return 0;}
    sieve(t);
    int f=0; // front pointer
    int r=0; // rear  pointer
    int s=0; // sum
    int n=0; // answer

    while(1){
        if(s>=t){if(s==t){n++;}   s-=p[f++];}
        else    {if(r==c){break;} s+=p[r++];}
    }

    printf("%d",n);
    return 0;
}


void sieve(int n){
    int j; // loop variable
    int k; // loop variable
    int s=1; while(s*s<=n){s++;}// sqrt(n)+1
    memset(a,0b11111111,sizeof(a));
  
    for(j=2;j<s;j++){
        if((a[j>>3]&(1<<(j&0b00000111)))==0){continue;}
        else{for(k=j*j;k<=n;k+=j){a[k>>3]&=~(1<<(k&0b00000111));}}
    }
    
    c=0; // 전역 소수 개수
    for(j=2;j<=n;j++){if((a[j>>3]&(1<<(j&0b00000111)))!=0){p[c++]=j;}}
}