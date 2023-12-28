#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#define Max_way_size 256
// C:\Users\egoro\Desktop\test\
// C:\Users\ITMM-230041\Desktop\test\

typedef struct {
	char *name;
	long size;
} files;

int count_files(char *way) {
	WIN32_FIND_DATAA findfile;
	HANDLE hFind = FindFirstFileA(way, &findfile);
	int c = 0;
	do {
		if (findfile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			continue;
		}
		c++;
	} while (FindNextFileA(hFind, &findfile) != NULL);
	printf("������ � �������� %d\n", c);
	return c;
}

void create_way(char* way) {
	int len = strlen(way);
	if (way[len - 1] != '*') {
		way[len + 1] = way[len];
		way[len] = '*';
	}
}

int check_way(char* way) {
	WIN32_FIND_DATAA findfile;
	HANDLE hFind = FindFirstFileA(way, &findfile);
	if (hFind == INVALID_HANDLE_VALUE) return 0;
	return 1;
}

files* return_arr(char* way, int n) {
	int i = 0;
	files* inf_files;
	WIN32_FIND_DATAA findfile;
	LARGE_INTEGER fullsize;
	UINT64 filesize_final;
	HANDLE hFind = FindFirstFileA(way, &findfile);

	inf_files = (files*)malloc(n * sizeof(files));

	do {
		fullsize.HighPart = findfile.nFileSizeHigh;
		fullsize.LowPart = findfile.nFileSizeLow;
		filesize_final = fullsize.QuadPart;

		if (!(findfile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			inf_files[i].name = _strdup(findfile.cFileName);
			inf_files[i].size = filesize_final;
			i++;
			continue;
		}
	} while (FindNextFileA(hFind, &findfile) != NULL);
	FindClose(hFind);
	return inf_files;
}

void buble_sort(long * arr, int* support, int len) {
	int max_ind, n, ne;
	while (len != 0) {
		max_ind = 0;
		for (int i = 1; i < len; i++) {
			if (arr[i - 1] > arr[i]) {
				n = arr[i];
				ne = support[i];
				arr[i] = arr[i - 1];
				support[i] = support[i - 1];
				arr[i - 1] = n;
				support[i - 1] = ne;
				max_ind = i;
			}
		}
		len = max_ind;
	}
}

void selection_sort(long * arr, int* support, int len) {
	int i, j,  min_ind, n, ne;
	for (i = 0; i < len; i++) {
		min_ind = i;
		for (j = i + 1; j < len; j++) {
			if (arr[min_ind] > arr[j])
				min_ind = j;
		}
		if (min_ind != i) {
			n = arr[min_ind];
			ne = support[min_ind];
			arr[min_ind] =arr[i];
			support[min_ind] = support[i];
			arr[i] = n;
			support[i] = ne;
		}
	}
}

void quick_sort(long * arr, int* support, int len, int left, int right) {
	int centric, swap, lt, rt, center_ch, swape;

	if (len == 0 || left >= right) {
		return;
	}
	centric = left + (right-left) / 2;
	center_ch = arr[centric];
	lt = left; rt = right;
	while (lt <= rt) {
		while (arr[lt] < center_ch) lt++;
		while (arr[rt] > center_ch) rt--;
		if (lt <= rt) {
			swap = arr[lt];
			swape = support[lt];
			arr[lt] = arr[rt];
			support[lt] = support[rt];
			arr[rt] = swap;
			support[rt] = swape;
			lt++;
			rt--;
		}
	}
	if (left < rt) quick_sort(arr, support, len, left, rt);
	if (right > lt) quick_sort(arr, support, len, lt, right);
}

long* get_size(files* files_inf, int cf) {
	long* sizes;
	sizes= (long*)malloc(sizeof(long) * cf);
	for (int i = 0; i < cf; i++) {
		sizes[i] = files_inf[i].size;
	}
	return sizes;
}

void print_files(files* files_inf, int cf) {
	printf("����� �� ������ ��������\n");
	printf("��� �����-----------������ �����\n");
	for (int i = 0; i < cf; i++) {
		printf("%s %ld \n", files_inf[i].name, files_inf[i].size);
	}
	printf("\n");
}

void print_sort_files(files* files_inf, long* sizes, int* support, int cf) {
	printf("������������� ����� �� ������ ��������\n");
	printf("��� �����-----------������ �����\n");
	int name;
	for (int i=0; i < cf; i++) {
		name = support[i];
		printf("%s %ld \n", files_inf[name].name, sizes[i]);
	}
	printf("\n");
}

double choice_sort(files* files_inf, long* sizes, int k, int len) {
	int left, right;
	int flag = 1;
	int* support_file;
	clock_t t_start;
	clock_t t_finish;
	double time_in_work=0;

	support_file = (int*)malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++) {
		support_file[i] = i;
	}
	switch (k)
	{
	case 1:
		t_start = clock();
		buble_sort(sizes, support_file, len);
		t_finish = clock();
		time_in_work = (double)((t_finish - t_start)) / CLOCKS_PER_SEC;
		print_sort_files(files_inf, sizes, support_file, len);
		break;
	case 2:
		t_start = clock();
		selection_sort(sizes, support_file, len);
		t_finish = clock();
		time_in_work = (double)((t_finish - t_start)) / CLOCKS_PER_SEC;
		print_sort_files(files_inf, sizes, support_file, len);
		break;
	case 3:
		left = 0; right = len - 1;
		t_start = clock();
		quick_sort(sizes, support_file, len, left, right);
		t_finish = clock();
		time_in_work = (double)((t_finish - t_start)) / CLOCKS_PER_SEC;
		print_sort_files(files_inf, sizes, support_file, len);
		break;
	}
	free(support_file);
	return time_in_work;
} 

int choice(files* files_inf, long* sizes, int*cfiles) {
	int n, k;
	double time_in_work;

	printf("��� �� ������ �������?\n");
	printf("1 - ������� ����� �� ����������\n");
	printf("2 - ������������� �����\n");
	printf("3 - ��������� ������\n");
	scanf("%d", &n);

	switch (n)
	{
	case 1:
		print_files(files_inf, cfiles);
		return 1;
	case 2:
		printf("�������� ������ ����������\n");
		printf("���������� ��������� - 1\n");
		printf("���������� ������� - 2\n");
		printf("������� ���������� - 3\n");
		do {
			printf("��� �����\n");
			scanf("%d", &k);
			if (k == 1 || k == 2 || k == 3) break;
			printf("�������� ����, ��������� ��� ���\n");
		} while (1);
		time_in_work = choice_sort(files_inf, sizes, k, cfiles);
		printf("����� ������ ���������� - %lf\n", time_in_work);
		return 1;
	case 3:
		printf("���������� ������\n");
		return 0;
	default:
		printf("�������� ����, ���������� �����\n");
		return -1;
	}

}

void main() {
	files* inf_files;
	long*sizes;
	char* way;
	int chek, cfiles, flag=1;

	way = (char*)malloc(Max_way_size * sizeof(char));

	setlocale(LC_ALL, "rus");

	while (flag) {
		printf("������� ���� �� ��������\n");
		scanf("%s", way);
		create_way(way);
		chek = check_way(way);
		if (chek == 0) {
			printf("�������� ���� ��� ������ ���� �� ����������\n");
			printf("���������� ������� ���������� ����\n");
			continue;
		}

		cfiles=count_files(way);
		inf_files = return_arr(way, cfiles);
		sizes=get_size(inf_files, cfiles);

		do {
			flag = choice(inf_files, sizes, cfiles);
		} while (flag != 0);

		free(way);
		//free(inf_files);
	}
}



