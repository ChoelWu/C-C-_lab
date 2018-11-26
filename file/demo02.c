#include <stdio.h>
#include <stdlib.h>

//
// Created by Choel on 2018/11/26.
//
struct Node {
    int data;
    struct Node *next;
};

int iterationB(int data, struct Node *B);

struct Node *getC(struct Node *A, struct Node *B);

int outputC(struct Node *C);

int main() {
    struct Node *A = NULL, *B = NULL, *C = NULL, *a = NULL, *b = NULL;
    int flag1 = 1, flag2 = 1, input;
    A = a = (struct Node *) malloc(sizeof(struct Node));
    printf("请输入A集合的元素，-1结束输入\n");
    do {
        scanf("%d", &input);
        if (input == -1) {
            flag1 = 0;
        } else {
            a->next = (struct Node *) malloc(sizeof(struct Node));
            a = a->next;
            a->data = input;
            a->next = NULL;
        }
    } while (flag1);
    printf("集合A输入完成，请输入A集合的元素，-1结束输入\n");
    do {
        scanf("%d", &input);
        if (input == -1) {
            flag2 = 0;
        } else {
            b->next = (struct Node *) malloc(sizeof(struct Node));
            b = b->next;
            b->data = input;
            b->next = NULL;
        }
    } while (flag2);
    C = getC(A, B);
    outputC(C);
    return 0;
}

struct Node *getC(struct Node *A, struct Node *B) {
    int i, j, rel;
    struct Node *p = NULL, *C = NULL, *c = NULL;
    p = A;
    while (!p->next) {
        rel = iterationB(p->data, B);
        if (rel) {
            c->next = p;
            c = c->next;
            if (C == NULL) {
                C = c;
            }
        }
        p = p->next;
    };
    return C;
}

int iterationB(int data, struct Node *B) {
    struct Node *q;
    q = B;
    while (!q->next) {
        if (q->data == data) {
            return 1;
        } else {
            q = q->next;
        };
    }
    return 0;
}

int outputC(struct Node *C) {
    return 0;
}