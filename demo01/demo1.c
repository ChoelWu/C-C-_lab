#include <stdio.h>
#include <stdlib.h>

int* quickSorting(int *sequence, int length, int key);

/**
 * 设有一组初始记录关键字序列（K1，K2，…，Kn），要求设计一个算法能够在O(n)的时间
 * 复杂度内将线性表划分成两部分，其中左半部分的每个关键字均小于Ki，右半部分的每个关键字均大于等于Ki。
 * 分析: 事实上就是一趟快排
 */

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

/**
 * 一次快排
 * @param sequence
 * @param length
 * @param key
 * @return
 */
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