#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SORTNUM 100
#define LOOPNUM 1000000

void sort(int *start, int len) {
    int i = 0, j = 0, tmp = 0;
    if(len == 1)
        return;
    for(i = 0; i<len-1; i++) {
        if(start[i] > start[i+1]) {
            tmp = start[i];
            start[i] = start[i+1];
            start[i+1] = tmp;
        }
    }
    sort(start, len-1);
}

int main() {
    int i = 0,j = 0;
    int *a = (int *)malloc(6*sizeof(int));
    int *b = (int *)malloc(6*sizeof(int));
    srand((unsigned)time(NULL));
    for(i=0; i<SORTNUM; i++) {
        a[i] = rand()%100+1;
    }
    for(j = 0; j< LOOPNUM; j++) {
        for(i = 0; i < SORTNUM; i++) {
            b[i] = a[i];
        }
        sort(b, SORTNUM);
    }
    for(i = 0; i<SORTNUM; i++) {
        printf("%d ",b[i]);
    }
    printf("\n");
    return 0;
}
