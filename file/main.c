#include <stdio.h>
#include <stdlib.h>

int* quickSorting(int *sequence, int length, int key);
//typedef struct node {
//    int data;
//    struct node *next;
//} lklist;

int main(void) {
    int seq[] = {5, 6, 12, 22, 6, 9, 3, 6, 7, 4, 2, 15, 2, 4, 21};
    int i;
    int *sorted_seq;
    sorted_seq = quickSorting(seq, 15, 1);
    for(i = 0; i < 15; i ++) {
        if(i != 0) {
            printf("-");
        }
        printf("%d", sorted_seq[i]);
    }
    return 0;
}

//void quickpass(int r[], int s, int t) {
//    int i = s, j = t, x = r[s];
//    while (i < j) {
//        while (i < j && r[j] > x) j = j - 1;
//        if (i < j) {
//            r[i] = r[j];
//            i = i + 1;
//        }
//        while (i < j && r[i] < x) i = i + 1;
//        if (i < j) {
//            r[j] = r[i];
//            j = j - 1;
//        }
//        r[i] = x;
//    }
//}
//
//void intersection(lklist *ha, lklist *hb, lklist *hc) {
//    lklist *p, *q, *t;
//    for (p = ha, hc = 0; p != 0; p = p->next) {
//        for (q = hb; q != 0; q = q->next) if (q->data == p->data) break;
//        if (q != 0) {
//            t = (lklist *) malloc(sizeof(lklist));
//            t->data = p->data;
//            t->next = hc;
//            hc = t;
//        }
//    }
//}

int* quickSorting(int *sequence, int length, int key) {
    int front = 0, rear, j, flag = 0, index, temp, sign = 0;
    rear = length - 1;
    for (j = 0; j < length; j++) {
        if (sequence[j] == key) {
            flag = 1;
            index = sequence[0];
            sequence[0] = key;
            sequence[j] = index;
            break;
        }
    }
    if (!flag) {
        printf("关键字 %d 不在序列中，请检查！\n", key);
    }
    do {
        if(sign == 0) {
            if (sequence[front] > sequence[rear]) {
                temp = sequence[front];
                sequence[front] = sequence[rear];
                sequence[rear] = temp;
                sign = 1;
                front ++;
            } else {
                rear --;
            }
        } else {
            if (sequence[rear] < sequence[front]) {
                temp = sequence[front];
                sequence[front] = sequence[rear];
                sequence[rear] = temp;
                sign = 0;
                rear --;
            } else {
                front ++;
            }
        }
    } while (rear != front);
    return sequence;
}