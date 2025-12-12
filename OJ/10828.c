//10828: 스택(구현, 자료 구조, 스택)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int value;
    struct node* next;
};
struct stack{
    int num;
    struct node* head;
};
void push(struct stack* s, int i);
int pop(struct stack* s);
int top(struct stack* s);
int size(struct stack* s);
int empty(struct stack* s);

int main(void){
    int n; scanf("%d", &n);
    char inst[6]; int arg;
    //스택 세팅
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->value = -1;
    head->next = NULL;
    s->num = 0;
    s->head = head;
    
    for(int i = 0; i < n; i++){
        scanf("%s", inst);
        if(strcmp(inst, "push") == 0){
            scanf("%d", &arg);
            push(s, arg);
        }
        else if(strcmp(inst, "pop") == 0){
            printf("%d\n", pop(s));
        }
        else if(strcmp(inst, "top") == 0){
            printf("%d\n", top(s));
        }
        else if(strcmp(inst, "size") == 0){
            printf("%d\n", size(s));
        }
        else if(strcmp(inst, "empty") == 0){
            printf("%d\n", empty(s));
        }
    }
}
void push(struct stack* s, int i){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = i;
    newnode->next = s->head->next;
    s->head->next = newnode;
    s->num += 1;
}
int pop(struct stack* s){
    if(s->num == 0){
        return -1;
    }
    else{
        int v = s->head->next->value;
        s->head->next = s->head->next->next;
        s->num -= 1;
        return v;
    }
}
int top(struct stack* s){
    if(s->num == 0){
        return -1;
    }
    else{
        return s->head->next->value;
    }
}
int size(struct stack* s){
    return s->num;
}
int empty(struct stack* s){
    if(s->num == 0){
        return 1;
    }
    else{
        return 0;
    }
}
