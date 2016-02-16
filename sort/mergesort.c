#include <stdio.h>
#include <stdlib.h>

#define NUMS 8

int *src, *tmp;

int mergesort(int *tmp, int *sortstart, int sortnums) {
    int i = 0;
    int *arrayA = NULL, *arrayB = NULL;
    if(sortstart) {
        arrayA = sortstart;
        arrayB = sortstart + sizeof(int)*(sortnums/2);
    } else {
        printf("do not get sort source num sets.\n");
        exit(-1);
    }
    for(i = 0; i<sortnums/2; i++) {
        if(arrayA[i] < arrayB[i]) {
            tmp[i] = arrayA[i];
            tmp[i+1] = arrayB[i];
            i++;                   // step with 2 steps.
        }
        
    }
    for(i = 0; i<sortnums/2; i++) {
        sortstart[i] = tmp[i];
    }
    return 1;
}

int main() {
    int i = 0, j = 0;
    src = (int *)malloc(NUMS*sizeof(int));
    tmp = (int *)malloc(NUMS*sizeof(int));
    srand((unsigned)time(NULL));
    for(i=0; i<NUMS; i++) {
        src[i] = rand()%100+1;
        printf("%d ", src[i]);
    }
    printf("\n");
    for(j=NUMS/2; j>=2; j=j/2) {
        for(i=1; i<j; i++) {
           mergesort(tmp, src + sizeof(int)*(NUMS/j)*i, NUMS/j);
        }
    }
    for(i=0; i<NUMS; i++) {
        src[i] = rand()%100+1;
        printf("%d ", src[i]);
    }
    printf("\n");
    return 1;
}
