// S5 25206: 너의 평점은(문자열)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int t=0;
    int g=0;
    float f;
    char* subj=(char*)malloc(sizeof(char)*51);
    char* time=(char*)malloc(sizeof(char)*4);
    char* grad=(char*)malloc(sizeof(char)*3);
    for(j=0;j<20;j++){
        scanf("%s",subj);
        scanf("%s",time);
        scanf("%s",grad);
        if(grad[0]=='P'){continue;}
        t+=time[0]-'0';
        if((grad[0]=='A')&&(grad[1]=='+')){g+=(45*(time[0]-'0')); continue;}
        if((grad[0]=='A')&&(grad[1]=='0')){g+=(40*(time[0]-'0')); continue;}
        if((grad[0]=='B')&&(grad[1]=='+')){g+=(35*(time[0]-'0')); continue;}
        if((grad[0]=='B')&&(grad[1]=='0')){g+=(30*(time[0]-'0')); continue;}
        if((grad[0]=='C')&&(grad[1]=='+')){g+=(25*(time[0]-'0')); continue;}
        if((grad[0]=='C')&&(grad[1]=='0')){g+=(20*(time[0]-'0')); continue;}
        if((grad[0]=='D')&&(grad[1]=='+')){g+=(15*(time[0]-'0')); continue;}
        if((grad[0]=='D')&&(grad[1]=='0')){g+=(10*(time[0]-'0')); continue;}
    }
    f=((float)g)/10;
    f=f/((float)t);
    printf("%f",f);
}