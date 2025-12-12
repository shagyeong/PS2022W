//2164: 카드2(자료 구조, 큐)
#include<stdio.h>
#include<stdlib.h>
struct card{
    int value;
    struct card* prev;
    struct card* next;
};
struct deck{
    struct card* top;
};
void push(struct deck* d, int i);
int pop(struct deck* d);
int main(void){
    int n; scanf("%d", &n);
    struct deck* d = (struct deck*)malloc(sizeof(struct deck));
    struct card* t = (struct card*)malloc(sizeof(struct card));
    t->value = -1; t->prev = t; t->next = t;
    d->top = t;
    for(int i = 1; i <= n; i++){
        push(d, i);
    }
    if(n != 1){
        pop(d);
    }
    for(int i = 0; i < n - 3; i++){
        push(d, pop(d));
        pop(d);
    }
    push(d, pop(d));
    printf("%d", d->top->next->value);
}
void push(struct deck* d, int i){
    struct card* newcard = (struct card*)malloc(sizeof(struct card));
    newcard -> value = i;
    newcard -> prev = d->top->prev;
    newcard -> next = d->top;
    d->top->prev->next = newcard;
    d->top->prev = newcard;
}
int pop(struct deck* d){
    int i = d->top->next->value;
    struct card* popcard = (struct card*)malloc(sizeof(struct card));
    popcard = d->top->next;
    d->top->next = d->top->next->next;
    d->top->next->next->prev = d->top;
    free(popcard);
    return i;
}
