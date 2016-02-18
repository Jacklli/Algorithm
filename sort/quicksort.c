#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMS 7

int *src, *tmp, *dst;

int quicksort(int *start, int len) {
	int tmp = 0,i = 0,j = 0,direction = 1;    //direction 0 from left to right, 1 from right to left
	if(len <= 1)
		return 1;
	for(i=0,j=len-1; i!=j;) {
		if(direction && start[i] > start[j] && i!=j) {  //从右往左走
			tmp = start[i];
			start[i] = start[j];
			start[j] = tmp;
			direction = 0;
			i++;
		} else if(direction && start[i] <= start[j] && i!=j){
			j--;
		}
		if(!direction && start[i] > start[j] && i!=j) { //从左往右走
			tmp = start[i];
			start[i] = start[j];
			start[j] = tmp;
			direction = 1;
			j--;
		} else if(!direction && start[i] <= start[j] && i!=j) {
			i++;
		}
	}
	//if(i==0) {  //第一个数就是最小的数，第一遍快排后，没有左边部分
	//	quicksort(start+i,len-(i+1));
	//} else if(j==len-1) {
	//	quicksort(start,i);  //第一个数就是最大的数，第一遍快排后，没有右边部分
	//} else {
		quicksort(start,i);
		quicksort(start+i+1,len-i-1);
	//}
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
	//src[0] = 39;
	//src[1] = 2;
	//src[2] = 1;
	//src[3] = 8;
	//src[4] = 3;
	//src[5] = 77;
	//src[6] = 12;
	//src[7] = 33;
	quicksort(src,NUMS);
    for(i=0; i<NUMS; i++) {
        printf("%d ", src[i]);
    }
    printf("\n");
	system("pause");
    return 1;
}
