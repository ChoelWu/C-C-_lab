#include <stdio.h>
#include <stdlib.h>

//
// Created by Choel on 2018/11/26.
//
typedef struct NODE {
    int data;
    struct NODE *next;
} node;

int iterationSeq(int data, node *B);

node *getMixed(node *A, node *B);

int outputSeq(node *C);

node *createSeq();

int main() {
    node *A = NULL, *B = NULL, *C = NULL, *a = NULL, *b = NULL;
    printf("请输入A集合的元素，-1结束输入\n");
    A = createSeq();
//    C = getMixed(A, B);
    outputSeq(A);
    return 0;
}

/**
 * 得到集合的交集
 * @param A
 * @param B
 * @return
 */
node *getMixed(node *A, node *B) {
    int rel;
    node *p = NULL, *C = NULL, *c = NULL;
    p = A;
    while (!p->next) {
        rel = iterationSeq(p->data, B);
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

/**
 * 遍历单链表并查找元素data
 * @param data
 * @param B
 * @return
 */
int iterationSeq(int data, node *N) {
    node *q;
    q = N;
    while (!q->next) {
        if (q->data == data) {
            return 1;
        } else {
            q = q->next;
        };
    }
    return 0;
}

/**
 * 输出单链表
 * @param C
 * @return
 */
int outputSeq(node *C) {
    node *cp = NULL;
    cp = C;
    printf("元素为:");
    while (cp != NULL) {
        printf("%d-", cp->data);
        cp = cp->next;
    }
    return 0;
}

/**
 * 无头节点头部插入法创建链表
 * @return
 */
//node *createSeq() {
//    node *n = NULL, *N = NULL;
//    int input, flag = 1;
//    do {
//        scanf("%d", &input);
//        if (input == -1) {
//            flag = 0;
//        } else {
//            n = (node *) malloc(sizeof(node));
//            n->next = N;
//            n->data = input;
//            N = n;
//        }
//    } while (flag);
//    return N;
//}

/**
 * 无头结点尾部插入法
 * @return
 */
node *createSeq() {
    node *n = NULL, *N = NULL, *tmp = NULL;
    int input, flag = 1;
    while (flag) {
        scanf("%d", &input);
        if (input == -1) {
            flag = 0;
        } else {
            tmp = (node *) malloc(sizeof(node));
            tmp->data = input;
            tmp->next = NULL;
            if (N == NULL) {
                N = n = tmp;
            } else {
                n->next = tmp;
                n = n->next;
            }
        }
    }
    return N;
}