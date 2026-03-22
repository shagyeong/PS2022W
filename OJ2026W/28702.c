// B1 28702: FizzBuzz(문자열)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Z 1 // FizzBuzz
#define F 2 // Fuzz
#define B 3 // Buzz

int conv(int d;);

int main(void){
    char s[9];
    int u;
    int v;
    int w;
    if((u=conv(3))==0){scanf("%s",s); scanf("%s",s); return 0;}
    if((v=conv(2))==0){scanf("%s",s); return 0;}
    if((w=conv(1))==0){return 0;}
}


int conv(int d){
    int j;
    char s[9]; scanf("%s",s);
    int l=(int)(strlen(s));
    int r=0;
    int b=1;

    if(s[0]=='B'){return B;}
    if(s[0]=='F'){
        if(l==4){return F;}
        if(l==8){return Z;}
    }

    for(j=l-1;j>=0;j--){
        r+=(b*(s[j]-'0'));
        b*=10;
    }
    r+=d;
    if(r%15==0){printf("FizzBuzz"); return 0;}
    if(r%3 ==0){printf("Fizz");     return 0;}
    if(r%5 ==0){printf("Buzz");     return 0;}
    printf("%d",r); return 0;
}