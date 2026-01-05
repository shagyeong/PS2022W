// S5 8892: 팰린드롬(문자열,팰린드롬)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ispalindrome(char* c){
    int j=0; // loop variable
    int l; // length
    l=strlen(c)-1;

    while(j<l){
        if(c[j++]==c[l--]){continue;}
        else              {return -1;} // not palindrome
    }
    return 0;
}

int main(void){
    int j; // loop variable
    int k; // loop variable
    int l; // loop variable
    int t; // number of test case
    int w; // number of word in a test case
    char* a[100]; // 1<= w <=100
    for(j=0;j<100;j++){a[j]=(char*)malloc(sizeof(char)*10001);}

    scanf("%d",&t);
    for(j=0;j<t;j++){
        scanf("%d",&w);
        for(k=0;k<w;k++){scanf("%s",a[k]);}
        if(w==1){printf("0");goto escape;}
        for(k=0;k<w-1;k++){
            for(l=k+1;l<w;l++){
                char c[10000];

                // concat(s[k],a[l])가 팰린드롬인가
                sprintf(c,"%s%s",a[k],a[l]);
                if(ispalindrome(c)==0){
                    printf("%s",c);
                    goto escape; // goto: 문제 조건 "아무거나 출력한다"
                }

                // concat(s[l],a[k])가 팰린드롬인가
                sprintf(c,"%s%s",a[l],a[k]);
                if(ispalindrome(c)==0){
                    printf("%s",c);
                    goto escape;
                }
                
            }
        }
        if((k==w-1)&&(l==w)){printf("0");} // 팰린드롬을 만들 수 없음
        escape:
        printf("\n");
    }
}