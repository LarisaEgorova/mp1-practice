#include <stdio.h>
#include <windows.h>
#include <fileapi.h>
#include <string.h>
#include <locale.h>

#define Max_way_size 256
// C:\Users\egoro\Desktop\test\

typedef struct {
	char *name;
	UINT64 size;
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
	printf("Файлов в каталоге %d\n", c);
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

void buble_sort(files* arr, int len) {
	int max_ind, n;
	while (len != 0) {
		max_ind = 0;
		for (int i = 1; i < len; i++) {
			if (arr[i - 1].size > arr[i].size) {
				n = arr[i].size;
				arr[i].size = arr[i - 1].size;
				arr[i - 1].size = n;
				max_ind = i;
			}
		}
		len = max_ind;
	}
}

void selection_sort(files* arr, int len) {
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

void quick_sort(files* arr, int len, int left, int right) {
	int centric, swap, lt, rt, center_ch;

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
			arr[lt] = arr[rt];
			arr[rt] = swap;
			lt++;
			rt--;
		}
	}
	if (left < rt) quick_sort(arr, len, left, rt);
	if (right > lt) quick_sort(arr, len, lt, right);
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

void cpy(files* a, files* b, int cf) {
	int i = 0;
	for (i; i < cf; i++) {
		b[i].name = _strdup(a[i].name);
		b[i].size = a[i].size;
	}
}

void swap(files* files_inf, int i, int j) {
	UINT64* a = &files_inf[i].size;
	UINT64* b = &files_inf[j].size;

	if (*a > *b) {
		UINT64 tmp = *a;
		char* tmpw = files_inf[i].name;

		*a = *b;
		files_inf[i].name = files_inf[j].name;
		*b = tmp;
		files_inf[j].name = tmpw;


	}
}

void print_files(files* files_inf, int cf) {
	setlocale(LC_ALL, "rus");
	printf("Файлы из вашего каталога\n");
	printf("Имя файла-----------Размер файла\n");
	for (int i = 0; i < cf; i++) {
		printf("%s \t\t %llu \n", files_inf[i].name, files_inf[i].size);
	}
}

void main() {
	files* inf_files;
	char* way;
	int chek, cfiles, n;
	way = (char*)malloc(Max_way_size * sizeof(char));
	setlocale(LC_ALL, "rus");
	while (1) {
		printf("Введите путь до каталога\n");
		scanf("%s", way);
		create_way(way);
		chek = check_way(way);
		if (chek == 0) {
			printf("Неверный путь или такого пути не существует");
			printf("Пожалуйста введите корректный путь");
			continue;
		}
		cfiles=count_files(way);
		inf_files = return_arr(way, cfiles);
		print_files(inf_files, cfiles);
		printf("Выберете способ сортировки\n");
		printf("Сортировка пузырьком - 1\n");
		printf("Сортировка выбором - 2\n");
		printf("Быстрая сортировка - 3\n");
		printf("Завершение - 0\n");
		while (1) {
			printf("Вdедите ответ\n");
			scanf("%d", &n);
			if (n != 1 || n != 2 || n != 3 || n != 0) {
				printf("Неверный ввод");
				continue;
			}
			break;
		}
	}
}



