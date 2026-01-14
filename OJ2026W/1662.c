// G4 1662: 압축(스택,재귀)
#include<stdio.h>
#include<string.h>

char a[51];
int  s[51]; // stack: '('
int  p[51]; // pair: ')'

int length(int f,int r);

int main(void){
    int j;
    scanf("%s",&a[0]);
    int l=(int)(strlen(a));
    int t=-1; // top of stack

    for(j=0;j<l;j++){
        if     (a[j]=='('){s[++t]   =j;}
        else if(a[j]==')'){p[s[t--]]=j;}
    }

    printf("%d",length(0,l));
}

int length(int f,int r){
    int j;
    int k;
    int l=0; // length
    for(j=f;j<r;j++){
        if(a[j]=='('){
            k=a[j-1]-'0'; // 동치문: atoi(a[j-1])
            l+=k*length(j+1,p[j])-1;
            j=p[j];
        }
        else{
            l+=1;
        }
    }
    return l;
}