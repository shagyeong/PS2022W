//10845: 큐(자료 구조, 큐)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* prev;
    struct node* next;
};
struct queue{
    int num;
    struct node* head;
};
void push(struct queue* q, int i);
int pop(struct queue* q);
int size(struct queue* q);
int empty(struct queue* q);
int front(struct queue* q);
int back(struct queue* q);

int main(void){
    int n; scanf("%d", &n);
    char inst[10];
    int arg;
    //큐 세팅
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    struct node* h = (struct node*)malloc(sizeof(struct node));
    q->num = 0; q->head = h;
    h->value = -1; h->prev = h; h->next = h;
    for(int i = 0; i < n; i++){
        scanf("%s", inst);
        if(strcmp(inst, "push") == 0){
            scanf("%d", &arg);
            push(q, arg);
        }
        else if(strcmp(inst, "pop") == 0){
            printf("%d\n", pop(q));
        }
        else if(strcmp(inst, "size") == 0){
            printf("%d\n", size(q));
        }
        else if(strcmp(inst, "empty") == 0){
            printf("%d\n", empty(q));
        }
        else if(strcmp(inst, "front") == 0){
            printf("%d\n", front(q));
        }
        else if(strcmp(inst, "back") == 0){
            printf("%d\n", back(q));
        }
    }
}
void push(struct queue* q, int i){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = i;
    newnode->next = q->head;
    newnode->prev = q->head->prev;
    q->head->prev->next = newnode;
    q->head->prev = newnode;
    q->num += 1;
}
int pop(struct queue* q){
    if(q->num == 0){
        return -1;
    }
    else{
        int v = q->head->next->value;
        q->head->next->next->prev = q->head;
        q->head->next = q->head->next->next;
        q->num -= 1;
        return v;
    }
}
int size(struct queue* q){
    return q->num;
}
int empty(struct queue* q){
    return q->num == 0;
}
int front(struct queue* q){
    if(q->num == 0){
        return -1;
    }
    else{
        return q->head->next->value;
    }
}
int back(struct queue* q){
    if(q->num == 0){
        return -1;
    }
    else{
        return q->head->prev->value;
    }
}
