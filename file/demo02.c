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
    printf("������A���ϵ�Ԫ�أ�-1��������\n");
    A = createSeq();
//    C = getMixed(A, B);
    outputSeq(A);
    return 0;
}

/**
 * �õ����ϵĽ���
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
 * ��������������Ԫ��data
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
 * ���������
 * @param C
 * @return
 */
int outputSeq(node *C) {
    node *cp = NULL;
    cp = C;
    printf("Ԫ��Ϊ:");
    while (cp != NULL) {
        printf("%d-", cp->data);
        cp = cp->next;
    }
    return 0;
}

/**
 * ��ͷ�ڵ�ͷ�����뷨��������
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
 * ��ͷ���β�����뷨
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