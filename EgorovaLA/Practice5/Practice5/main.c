#include <stdio.h>
#include <windows.h>
#include <fileapi.h>
#include <string.h>

void buble_sort(int* arr, int len) {
	int max_ind, n;
	while (len != 0) {
		max_ind = 0;
		for (int i = 1; i < len; i++) {
			if (arr[i - 1] > arr[i]) {
				n = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = n;
				max_ind = i;
			}
		}
		len = max_ind;
	}
}

void selection_sort(int* arr, int len) {
	int i, j,  min_ind, n;
	for (i = 0; i < len; i++) {
		min_ind = i;
		for (j = i + 1; j < len; j++) {
			if (arr[min_ind] > arr[j])
				min_ind = j;
		}
		if (min_ind != i) {
			n = arr[min_ind];
			arr[min_ind]=arr[i];
			arr[i] = n;
		}
	}
}

int part_of_fast(int* arr, int len, int left, int right) {
	int centric, n;
	centric = arr[(left + right) / 2];
	while (left < right) {
		while (arr[left] < centric) left++;
		while (arr[right] < centric) right--;
		if (left <= right) {
			n = arr[left];
			arr[left] = arr[right];
			arr[left] = n;
			left++;
			right--;
		}
	}
	return left;
}

void fast_sort(int* arr, int len) {
	;
}

struct files
{
	char* name;
	int size;
};

void allocade(int** arr, int* n) {
	;
}

void fill() {
	;
}

void print() {
	;
}

void main() {
	return;
}