#include<iostream>
#include<time.h>
#define ARRLEN 100
void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}
void bubblesort(int *arr) {
	for (int i = 0; i < ARRLEN; i++) {
		for (int j = 0; j < ARRLEN-1; j++) {
			if (arr[j + 1] < arr[j]) {
				swap(&arr[j + 1], &arr[j]);
			}
		}
	}
}
void selectionsort(int *arr) {
	int minidx;
	for (int i = 0; i < ARRLEN; i++) {
		minidx = i;
		for (int j = i; j < ARRLEN; j++) {
			if (arr[j] < arr[minidx]) {
				minidx = j;
			}
		}
		swap(&arr[i], &arr[minidx]);
	}
}
void insertionsort(int *arr) {
	for (int i = 0; i < ARRLEN; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j-1] >= arr[j]) swap(&arr[j],&arr[j-1]);
			else break;
		}
	}
}
void mergesort(int *arr, int start, int end) {
	int temp_arr[ARRLEN];
	int mid = (start + end) / 2;
	int i=start, j= mid+1, idx=0;
	if (end <= start) return;

	mergesort(arr, start, mid);
	mergesort(arr, mid+1, end);

	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) temp_arr[idx++] = arr[i++];
		else temp_arr[idx++] = arr[j++];
	}

	while (j <= end) {
		temp_arr[idx++] = arr[j++];
	}

	while (i <= mid) {
		temp_arr[idx++] = arr[i++];
	}

	for (int i = start; i <= end; i++) {
		arr[i] = temp_arr[i-start];
	}
}
void quicksort(int *arr, int start, int end) {
	int mid = (start + end) / 2; 
	int pivot = start;
	int left = start + 1;
	int right = end;
	if (start >= end) return;

	while (left <= right) {
		while (left <= right && arr[left] <= arr[pivot]) {
			left++;
		}
		while (left <= right && arr[right] >= arr[pivot]) {
			right--;
		}

		if (right < left) break;
		else {
			swap(&arr[right], &arr[left]);
		}
	}
	swap(&arr[pivot], &arr[right]);

	quicksort(arr, start, right -1);
	quicksort(arr, right + 1, end);

}
int main(void) {
	int a[ARRLEN];
	for(int i=0;i<ARRLEN;i++)
		a[i] = rand()%101;

	clock_t time = clock();

	//bubblesort(a);
	//selectionsort(a);
	//insertionsort(a);
	//mergesort(a, 0, ARRLEN-1);
	quicksort(a,0,ARRLEN-1);

	clock_t end_time = clock();
	for (int i = 0; i < ARRLEN; i++) {
		printf("%d\n", a[i]);
	}

	printf("elapsed time : %lf\n", (double)((end_time - time))/CLOCKS_PER_SEC);
	return 0;
}