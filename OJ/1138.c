//1138: 한 줄로 서기(구현, 그리디 알고리즘)
#include<stdio.h>
#include<stdlib.h>
struct node{
    unsigned short value;
    struct node* next;
};

int main(void){
    unsigned short i, j;
    unsigned short sft;

    unsigned short n; scanf("%hd", &n);
    unsigned short arr[n + 1];
    for(i = 1; i <= n; i++){
        scanf("%hd", &arr[i]);
    }

    struct node* ans = (struct node*)malloc(sizeof(struct node));
    struct node* buf = (struct node*)malloc(sizeof(struct node));
    ans->value = -1;
    ans->next = NULL;
    buf = ans;      //헤드를 겸함

    for(i = n; i >= 1; i--){
        sft = arr[i];
        for(j = 0; j < sft; j++){
            buf = buf->next;
        }
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->value = i;
        newnode->next = buf->next;
        buf->next = newnode;
        buf = ans;  //다시 헤드로 위치시킴
    }
    buf = buf->next;
    for(i = 0; i < n; i++){
        printf("%hd ", buf->value);
        buf = buf->next;
    }
}
