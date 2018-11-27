//#include <stdio.h>
//#include <stdlib.h>
//
//int* quickSorting(int *sequence, int length, int key);
////typedef struct node {
////    int data;
////    struct node *next;
////} lklist;
//
//int main(void) {
//    int seq[] = {5, 6, 12, 22, 6, 9, 3, 6, 7, 4, 2, 15, 2, 4, 21};
//    int i;
//    int *sorted_seq;
//    sorted_seq = quickSorting(seq, 15, 1);
//    for(i = 0; i < 15; i ++) {
//        if(i != 0) {
//            printf("-");
//        }
//        printf("%d", sorted_seq[i]);
//    }
//    return 0;
//}
//
////2.	设有两个集合A和集合B，要求设计生成集合C=A∩B的算法，其中集合A、B和C用
////        链式存储结构表示。
//
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
