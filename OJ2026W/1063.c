// S3 1063: 킹(구현,시뮬레이션)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int r;
    int c;
};

struct node d; // 방향
struct node king; struct node u;
struct node rock; struct node v;

int main(void){
    int j;
    char inst[3];
    int n;
    scanf("%s",inst); king.r=inst[1]-'0'; king.c=inst[0]-'A'+1;
    scanf("%s",inst); rock.r=inst[1]-'0'; rock.c=inst[0]-'A'+1;
    scanf("%d",&n);

    for(j=0;j<n;j++){
        scanf("%s",inst);
        if(strlen(inst)==1){
            if     (inst[0]=='R'){d.r= 0; d.c= 1;}
            else if(inst[0]=='L'){d.r= 0; d.c=-1;}
            else if(inst[0]=='T'){d.r= 1; d.c= 0;}
            else if(inst[0]=='B'){d.r=-1; d.c= 0;}
        }
        else{
            if     ((inst[0]=='R')&&(inst[1]=='T')){d.r= 1; d.c= 1;}
            else if((inst[0]=='R')&&(inst[1]=='B')){d.r=-1; d.c= 1;}
            else if((inst[0]=='L')&&(inst[1]=='T')){d.r= 1; d.c=-1;}
            else if((inst[0]=='L')&&(inst[1]=='B')){d.r=-1; d.c=-1;}
        }
        u.r=king.r+d.r; if((u.r<=0)||(u.r>8)){continue;}
        u.c=king.c+d.c; if((u.c<=0)||(u.c>8)){continue;}
        if((u.r!=rock.r)||(u.c!=rock.c)){
            king.r=u.r;
            king.c=u.c;
        }
        else{
            v.r=rock.r+d.r; if((v.r<=0)||(v.r>8)){continue;}
            v.c=rock.c+d.c; if((v.c<=0)||(v.c>8)){continue;}
            king.r=u.r;
            king.c=u.c;
            rock.r=v.r;
            rock.c=v.c;
        }
    }
    printf("%c%c\n",king.c+'A'-1,king.r+'0');
    printf("%c%c",  rock.c+'A'-1,rock.r+'0');
}