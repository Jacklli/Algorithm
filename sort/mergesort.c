/*************************************************************
*
*  *can only sort data sets with num that is a power of 2
*  
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMS 8

int *src, *tmp, *dst;

int mergesort(int *tmp, int *sortstart, int *dst, int sortnums, int groupseq) {
    int i = 0,j = 0,index = 0,offset = 0;
    int *arrayA = NULL, *arrayB = NULL;
    if(sortstart) {
        arrayA = sortstart;
		arrayB = sortstart + sortnums/2;
    } else {
        printf("do not get sort source num sets.\n");
        exit(-1);
    }
    for(i = 0,j = 0; index<sortnums; ) {
        if(i < sortnums/2 && j < sortnums/2 && arrayA[i] <= arrayB[j]) {
            tmp[index+sortnums*groupseq] = arrayA[i];
            index++;
            i++;                   
        } else if(i < sortnums/2 && j < sortnums/2 && arrayA[i] > arrayB[j]) {
            tmp[index+sortnums*groupseq] = arrayB[j];
            index++;
            j++;
		} else if(i < sortnums/2) {    //第3和第4个if只能2选1
			tmp[index+sortnums*groupseq] = arrayA[i];
            index++;
            i++;      
		} else if(j < sortnums/2) {    //第3和第4个if只能2选1
			tmp[index+sortnums*groupseq] = arrayB[j];
            index++;
            j++;
		}
    }
    for(i = 0; i<sortnums; i++) {
        src[i+sortnums*groupseq] = tmp[i+sortnums*groupseq];
    }
    return 1;
}

int main() {
    int i = 0, j = 0, offset = 0;
    src = (int *)malloc(NUMS*sizeof(int));
    tmp = (int *)malloc(NUMS*sizeof(int));
	dst = (int *)malloc(NUMS*sizeof(int));
    srand((unsigned)time(NULL));
    for(i=0; i<NUMS; i++) {
        src[i] = rand()%100+1;
        printf("%d ", src[i]);
    }
    printf("\n");
    for(j=NUMS/2; j>=1; j=j/2) {   //j代表有多少个分组需要排序
        for(i=0; i<j; i++) {	   //i代表第几组
            mergesort(tmp, src + (NUMS/j)*i, dst, NUMS/j,i);    //  NUMS/j代表每个分组有多少个元素
        }
    }
    for(i=0; i<NUMS; i++) {
        printf("%d ", src[i]);
    }
    printf("\n");
	system("pause");
    return 1;
}
