#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
//#define size 10000

void print_array(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%2i", a[i]);
	}
}

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void bubble_sort(int *a, int n, int *comps, int *swaps) {
	int i, j, f;
	for (i = 0; i < n; i++) {
		f = 0;
		for (j = 0; j < n - i - 1; j++) {
			(*comps)++;
			if (a[j] > a[j + 1]) {
				(*comps)++;
				(*swaps)++;
				swap(&a[j], &a[j + 1]);
				f = 1;
			}
		}
		if (!f) break;
	}
}

void shacker_sort(int *a, int n, int *comps, int *swaps) {
	int i, j, k, f;
	for (i = 0; i < n; i++) {
		f = 0;
		for (j = i; j < n - i - 1; j++) {
			(*comps)++;
			if (a[j] > a[j + 1]) {
				(*comps)++;
				(*swaps)++;
				swap(&a[j], &a[j + 1]);
				f = 1;
			}
		}
		for (k = n - i - 1; k > i + 1; k--) {
			(*comps)++;
			if (a[k] < a[k - 1]) {
				(*comps)++;
				(*swaps)++;
				swap(&a[k], &a[k - 1]);
				f = 1;
			}
		}
		if (!f) break;
	}
}

void selection_sort(int *a, int n, int *comps, int *swaps) {
	int i = 0, j = 0, flag, maxj;
	*comps = 0;
	*swaps = 0;
	for (i = 0; i < n; i++) {
		maxj = 0;
		for (j = 0; j < n - i; j++) {
			(*comps)++;
			if (a[j] > a[maxj]) {
				maxj = j;
				(*swaps)++;

			}

		}
		swap(&a[n - i - 1], &a[maxj]);
	}
}
void ins_sort(int a[], int n, int *comps, int *swaps) {

	int i, j, k, st, pos;
	for (i = 1; i < n; i++) {
		(*comps)++;
		pos = 0;
		for (j = i - 1; j >= 0; j--) {
			(*comps)++;
			if (a[j] <= a[i]) {

				pos = j + 1;
				(*comps)++;
				(*swaps)++;
				break;
			}
		}

		st = a[i];
		for (k = i - 1; k >= pos; k--) {
			a[k + 1] = a[k];
		}
		a[pos] = st;
	}
}

void count_sort(int a[], int n, int count[], int max1) {
	int i, j, k, pos, st;
	for (i = 0; i < max1; i++) {
		count[i] = 0; //обнуление массива
	}
	for (i = 0; i < n; i++) {
		count[a[i]]++; //заполнение вспомогательного массива
	}
	k = 0;
	for (i = 0; i < max1; i++) {
		for (j = 0; j < count[i]; j++) {
			a[k] = i;
			k++;
		}
	}
}
void dyn_count_sort(int a[], int n, int max) { //Сортировка вставками  массивом 
	int i, j, k, *count;
	count = (int*)malloc(sizeof(int)*max);
	for (i = 0; i < max; i++) {
		count[i] = 0;
	}
	for (i = 0; i < n; i++) {
		count[a[i]]++;
	}
	k = 0;
	for (i = 0; i < max; i++) {
		for (j = 0; j < count[i]; j++) {
			a[k] = i;
			k++;
		}
	}
	free(count);
}
int bin_search(int *a, int n, int k) {
	int i, start = 0, finish = n - 1;
	while (start <= finish) //добавить счетчик числа сравнений этого цикла
	{
		i = (start + finish) / 2;
		if (a[i] == k) {
			return i;
		}
		else {
			if (a[i] > k) {
				finish = i - 1;
			}
			else
			{
				start = i + 1;
			}
		}

	}
	return -1;
}
int factorial(int n) {
	int fact;
	if (n = 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);


	}
}
void merge(int a[], int buffer[], int start, int finish, int mid) {
	int i = start, j = mid + 1, pos = start;
	while ((i <= mid) && (j <= finish)) {
		if (a[i] > a[j]) {
			buffer[pos] = a[j];
			j++;
			pos++;
		}
		else {
			buffer[pos] = a[i];
			i++;
			pos++;
		}
		if (i > mid) {
			for (j; j <= finish; j++) {
				buffer[pos] = a[j];
				pos++;
			}
		}
		else {
			for (i; i <= mid; i++) {
				buffer[pos] = a[i];
				pos++;
			}
		}
		for (i = start; i <= finish; i++) {
			a[i] = buffer[i];
		}
	}

}
void merge_sort(int a[], int buffer[], int start, int finish) {
	int mid;
	if (start == finish) {
		return;
	}
	else {
		mid = (start + finish) / 2;
		merge_sort(a, buffer, start, mid);
		merge_sort(a, buffer, mid + 1, finish);
		merge(a, buffer, start, finish, mid);
	}
}

int main() {
	srand((unsigned)time(NULL));
	int as[6], max1 = 7, i, comps = 0, swaps = 0;
	int sort = 0, size_array, start1, finish1;
	int max = -2147483647;
	int *a_dyn, *a, *a1, *a2, *a3, *a4, *a5, *a6;
	float dur;
	clock_t start, stop;
	//a_dyn = (int*)malloc(sizeof(int)*size_array);
	// dur - сколько секунд работает сортировка, comps - количество сравнений в сортировке, swaps - количество перестановок в сортировке
	/*
	for (i = 0; i < size; i++) { //задание массива
		a[i] = rand() % 10;
	}

	for (i = 0; i < size; i++) { //копирование массива
		a1[i] = a[i];
		a2[i] = a[i];
		a4[i] = a[i];
	}
	//int a3[10] = { 1, 2, 5,4,6,1,2,6,1,6 };
	*/
	printf("Enter array lenght\n");
	scanf_s("%d", &size_array);
	start1 = 0;
	finish1 = size_array-1;

	a_dyn = (int*)malloc(sizeof(int)*size_array);
	a = (int*)malloc(sizeof(int)*size_array);
	a1 = (int*)malloc(sizeof(int)*size_array);
	a2 = (int*)malloc(sizeof(int)*size_array);
	a3 = (int*)malloc(sizeof(int)*size_array);
	a4 = (int*)malloc(sizeof(int)*size_array);
	a5 = (int*)malloc(sizeof(int)*size_array);
	a6 = (int*)malloc(sizeof(int)*size_array);
	for (i = 0; i < size_array; i++) { //задание массива
		a_dyn[i] = rand() % 10;
	}
	for (i = 0; i < size_array; i++) {
		if (a_dyn[i] > max) {
			max = a_dyn[i];
		}
	}
	for (i = 0; i < size_array; i++) { //копирование массива
		a1[i] = a_dyn[i];
		a2[i] = a_dyn[i];
		a3[i] = a_dyn[i];
		a4[i] = a_dyn[i];
		a5[i] = a_dyn[i];
	
	}

	if (size_array <= 20) {
		print_array(a_dyn, size_array);
		printf("\n");
		printf("max = %d\n", max);
	}
	while (sort < 7) {
		printf("Enter 1 to choose bubble sort\n");
		printf("Enter 2 to choose shacker sort\n");
		printf("Enter 3 to choose inserting sort\n");
		printf("Enter 4 to choose counting sort\n"); //Сортировка вставками с динамическим массивом 
		printf("Enter 5 to choose counting sort\n");
		printf("Enter 6 to choose merge sort\n");
		printf("Enter 7 to exit\n");

		scanf_s("%d", &sort);

		switch (sort) {
		case 1: //bubble sort
		{
			comps = 0;
			swaps = 0;
			start = clock();
			bubble_sort(a1, size_array, &comps, &swaps);
			stop = clock();
			dur = (float)(stop - start) / CLOCKS_PER_SEC;
			printf("buble sort: %f s, %d comparisons, %d swaps\n", dur, comps, swaps);
			if (size_array <= 20) {
				print_array(a1, size_array);
				printf("\n");
			}
			printf("\n");
		};
		break;
		case 2: //shacker sort
		{
			comps = 0;
			swaps = 0;
			start = clock();
			shacker_sort(a2, size_array, &comps, &swaps);
			stop = clock();
			dur = (float)(stop - start) / CLOCKS_PER_SEC;
			printf("shacker sort: %f s, %d comparisons, %d swaps\n", dur, comps, swaps);
			if (size_array <= 20) {
				print_array(a2, size_array);
				printf("\n");
			}
			printf("\n");
		};
		break;
		case 3: //inserting sort
		{
			comps = 0;
			swaps = 0;
			start = clock();
			ins_sort(a4, size_array, &comps, &swaps);
			stop = clock();
			dur = (float)(stop - start) / CLOCKS_PER_SEC;
			printf("inserting sort: %f s, %d comparisons, %d swaps\n", dur, comps, swaps);
			if (size_array <= 20) {
				print_array(a4, size_array);
				printf("\n");
			}
			printf("\n");

		};
		break;
		case 4: //counting sort
		{
			/*
			printf("Enter array lenght\n");
			scanf_s("%d", &size_array);

			a_dyn = (int*)malloc(sizeof(int)*size_array);
			for (i = 0; i < size_array; i++) { //задание массива
				a_dyn[i] = rand() % 10;
			}
			for (i = 0; i < size_array; i++) {
				if (a_dyn[i] > max) {
					max = a_dyn[i];
				}
			}
			*/
			comps = 0;
			swaps = 0;
			start = clock();
			dyn_count_sort(a_dyn, size_array, max + 1);
			stop = clock();
			dur = (float)(stop - start) / CLOCKS_PER_SEC;
			printf("counting sort: %f s, %d comparisons, %d swaps\n", dur, comps, swaps);
			printf("\n");
			if (size_array <= 20) {
				print_array(a_dyn, size_array);
				printf("\n");
			}
			printf("\n");

		};
		break;
		case 5: //selection sort
		{
			comps = 0;
			swaps = 0;
			start = clock();
			selection_sort(a3, size_array, &comps, &swaps);
			stop = clock();
			dur = (float)(stop - start) / CLOCKS_PER_SEC;
			printf("selection sort: %f s, %d comparisons, %d swaps\n", dur, comps, swaps);
			printf("\n");
			if (size_array <= 20) {
				print_array(a3, size_array);
				printf("\n");
			}
			printf("\n");
		};
		break;
		case 6: //merge sort
		{
			comps = 0;
			swaps = 0;
			start = clock();
			merge_sort(a5, a6, start1, finish1);
			stop = clock();
			dur = (float)(stop - start) / CLOCKS_PER_SEC;
			printf("merge sort: %f s, %d comparisons, %d swaps\n", dur, comps, swaps);
			printf("\n");
			if (size_array <= 20) {
				print_array(a5, size_array);
				printf("\n");
			}
			printf("\n");
		};
		break;
		case 7: //exit
			break;
		}
	}
	_getch();
	return 0;
}