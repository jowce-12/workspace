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
void quicksort2(int *arr, int start, int end) {
	int leftarr[ARRLEN];
	int rightarr[ARRLEN];
	int leftidx = 0;
	int rightidx = 0;
	int pivot = arr[start];

	if (start >= end) return;

	for (int i = start+1; i <= end; i++) {
		if (arr[i] <= pivot) {
			leftarr[leftidx++] = arr[i];
		}
		else if (arr[i] > pivot) {
			rightarr[rightidx++] = arr[i];
		}
	}

	int i,j;
	for (i = 0; i < leftidx; i++) {
		arr[start + i] = leftarr[i];
	}
	arr[start + i] = pivot;
	for (j=0; j < rightidx; j++) {
		arr[start + i + j+1] = rightarr[j];
	}

	quicksort2(arr,start, start+i-1);
	quicksort2(arr, start+i+1, end);
}
void heapsort(int *a) {
	int node[ARRLEN + 1];

	for (int i = 0; i < ARRLEN; i++) {// insert node
		int idx_cur = i + 1;
		int idx_prev = idx_cur;
		node[idx_cur] = a[i];

		while (node[idx_cur] >= node[idx_prev] && idx_cur > 0) {
			if(node[idx_cur] != node[idx_prev]) swap(&node[idx_cur], &node[idx_prev]);
			idx_prev = idx_cur;
			idx_cur = idx_cur / 2;
		}
	}

	int idx_last = ARRLEN;
	int idx_head = 1;
	int idx_cur = idx_head;
	for (int i = 0; i < ARRLEN; i++) {// delete node
		a[i] = node[idx_head];
		swap(&node[idx_head], &node[idx_last]);
		idx_last--;

		idx_cur = idx_head;
		while (idx_cur * 2 <= idx_last) {
			if (idx_cur * 2 + 1 <= idx_last) {
				if (node[idx_cur] < node[idx_cur * 2] && node[idx_cur] < node[idx_cur * 2 + 1]) {
					break;
				} else if (node[idx_cur * 2] <= node[idx_cur * 2 + 1]) {
					swap(&node[idx_cur], &node[idx_cur * 2]);
					idx_cur = idx_cur * 2;
				}
				else {
					swap(&node[idx_cur], &node[idx_cur * 2 + 1]);
					idx_cur = idx_cur * 2 + 1;
				}
			}
			else {
				if (node[idx_cur] < node[idx_cur * 2]) {
					break;
				}
				else {
					swap(&node[idx_cur], &node[idx_cur * 2]);
					idx_cur = idx_cur * 2;
				}
			}
		}
	}
	//  1 , 2 , 3, 4, 5, 6, 7
}
int main(void) {
	int a[ARRLEN];

	for (int i = 0; i < ARRLEN; i++) {
		a[i] = rand() % 101;
	}
		

	clock_t time = clock();

	//bubblesort(a);
	//selectionsort(a);
	//insertionsort(a);
	//mergesort(a, 0, ARRLEN-1);
	//quicksort(a,0,ARRLEN-1);
	//quicksort2(a,0,ARRLEN-1);
	heapsort(a);

	
	clock_t end_time = clock();
	for (int i = 0; i < ARRLEN; i++) {
		printf("%d\n", a[i]);
	}

	printf("elapsed time : %lf\n", (double)((end_time - time))/CLOCKS_PER_SEC);
	return 0;
}