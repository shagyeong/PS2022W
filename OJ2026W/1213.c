// S3 1213: 팰린드롬 만들기(문자열,그리디)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j;
    char* s=(char*)malloc(sizeof(char)*51); scanf("%s",s);
    char* a=(char*)malloc(sizeof(char)*51); // 정답열
    int i=0; // 정답열 포인터
    int l=(int)strlen(s);
    int f=-1; // 홀수 플래그: 등장시 알파벳 인덱스 저장
    int t[26]; memset(t,0,sizeof(int)*26);

    for(j=0;j<l;j++){t[s[j]-'A']++;}

    if(l%2==0){
        for(j=0;j<26;j++){if(t[j]%2==1){printf("I'm Sorry Hansoo"); free(s); free(a); return 0;}}
    }
    else{
        for(j=0;j<26;j++){
            if(t[j]%2==1){
                if(f!=-1){printf("I'm Sorry Hansoo"); free(s); free(a); return 0;}
                else{f=j;}
            }
        }
        a[l/2]=f+'A'; t[f]--;
    }

    
    for(j=0;j<26;j++){
        while(t[j]>0){
            a[i]=      j+'A';
            a[(l-1)-i]=j+'A';
            i+=1;
            t[j]-=2;
        }
    }
    a[l]='\0';
    printf("%s",a);
    free(s);
    free(a);
    return 0;
}