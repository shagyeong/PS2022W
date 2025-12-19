// 1918: 후위 표기식(자료구조, 스택)
#include<stdio.h>
#include<stdlib.h>

struct stack{
    char n;
    char l[127];
};

void push(struct stack* s,char c){s->l[(s->n)++]=c;}
char top(struct stack* s){return s->l[(s->n)-1];}
char pop(struct stack* s){return s->l[--(s->n)];}
void printstack(struct stack* s){for(char j=0;j<s->n;j++){printf("%c ",s->l[j]);}printf("\n");}

int main(void){
    char j;      // loop variable
    char* b;     // char buffer for formula
    char c;      // char buffer for stack
    char n;      // s->n buffer
    char f[127]; // input formula
    struct stack* s=(struct stack*)malloc(sizeof(struct stack)); // stack
    s->n=0;

    scanf("%s",f);
    b=&f[0];
    
    while(*b!='\0'){
        switch(*b){
            case '(':
                push(s,*b);
                break;
            case ')':
                n=s->n;
                for(j=0;j<n;j++){
                    c=pop(s);
                    if(c=='('){break;}
                    else{printf("%c",c);}
                }
                break;
            case '*':
            case '/':
                n=s->n;
                for(j=0;j<n;j++){
                    c=top(s);
                    if(c=='+'||c=='-'){break;}
                    if(c=='('){break;}
                    else{printf("%c",pop(s));}
                }
                push(s,*b);
                break;
            case '+':
            case '-':
                n=s->n;
                for(j=0;j<n;j++){
                    c=top(s);
                    if(c=='('){break;}
                    else{printf("%c",pop(s));}
                }
                push(s,*b);
                break;
            default: printf("%c",*b);
        };
        b++;
    }
    n=s->n;
    for(j=0;j<n;j++){
        printf("%c",pop(s));
    }
}