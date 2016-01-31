#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SORTNUM 100
#define LOOPNUM 1000000

void sort(int *start, int len) {
    int i = 0, j = 0, tmp = 0;
    for(i = len-j; i>0; i--) {
        for(j = 0; j<i-1; j++) {
            if(start[j] > start[j+1]) {
                tmp = start[j];
                start[j] = start[j+1];
                start[j+1] = tmp;
            }
        }
    }
}

int main() {
    int i = 0,j = 0;
    int *a = (int *)malloc(10*sizeof(int));
    int *b = (int *)malloc(10*sizeof(int));
    srand((unsigned)time(NULL));
    for(i=0; i<SORTNUM; i++) {
        a[i] = rand()%SORTNUM+1;
    }
    for(j = 0; j<LOOPNUM; j++) {
        for(i = 0; i<SORTNUM; i++) {
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
