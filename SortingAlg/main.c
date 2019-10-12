#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

#define n 1000000

#define INT uint16_t


double wtime()
{
struct timeval t;
gettimeofday(&t, NULL);
return (double)t.tv_sec + (double)t.tv_usec * 1E-6;  /*Функция возвращает текущее время в секундах*/
}


int getrand(int min, int max)
{
return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;  /*Функция, генерирующая псевдослучайные числа*/
}


void swap(INT *i, INT *j)
{
	int k;

	k = *i;
	*i = *j;
	*j = k;
}



void CountingSort(INT mas[n])
{
	double time;
	int i, j;
	int max = -1;

	
	time = wtime(); /*Присваем переменной "time" текущее время в секундах*/


	for (i = 0; i < n; i++) {
		if (mas[i] > max) {
			max = mas[i];  /*Находим максимальный элемент исходного массива*/
		}
	}


	for(j = 0; j < max + 1; j++) {
		mas[j] = 0;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < max + 1; j++) {  
		if (mas[i] == j) {        
				mas[j] = mas[j] + 1; /*Заполняем ячейки второго массива, прибегая к подсчёту одинаковых значений с исходного массива*/
				mas[i] = 0;
			}
		}
	}


	for (i = 0; i < n; i++) {
		for (j = 0; j < max + 1; j++) {
			while (mas[j] > 0) {
				mas[i] = mas[i] + j;
				mas[j] = mas[j] - 1;
				i++;        /*С помощью второго массива сортируем методом подсчета исходный массив и результат выводим в результирующий массив*/
			}
		}
	}

	for (i = 0; i < n - 1; i++) {
		printf("mas[%d] = %d\n", i, mas[i]);
	}


	time = wtime() - time;
	printf("Work time: %f sec.\n", time);  /*Записываем время работы функции*/

}



void InsertionSort(INT mas[n])
{
	int i;
	double time;


	time = wtime();


	for (i = 0; i < n; i++) {
		while (mas[i] > mas[i + 1]) {
			swap(&mas[i], &mas[i + 1]);
			i = i - 1;
		}
	}

	for (i = 0; i < n; i++) {
		printf("mas[%d] = %d\n", i, mas[i]);
	}

	time = wtime() - time;
	printf("Work time: %f sec.\n", time);  

}



void HeapSort(INT mas[n])
{
	double time;


	time = wtime();


void PyramidFormation(INT* mas, int i, int lower)
{
	int MaxChild;
	int flag = 0;   /*flag - флаг, обозначающий факт, что куча отсортирована*/

while ((i * 2 <= lower) && (flag != 1)) {
	if (i * 2 == lower) 
		MaxChild = i * 2;
	else if (mas[i * 2 ] > mas[i * 2 + 1])
		MaxChild = i * 2;
	else
		MaxChild = i * 2 + 1;
	if (mas[i] < mas[MaxChild]) {
		swap(&mas[i], &mas[MaxChild]);
		i = MaxChild;
		}
	else
		flag = 1;
	}
}


	for (int i = (n / 2) - 1; i >= 0; i--) {     	
		PyramidFormation(mas, i, n - 1);	/*Формируем нижний ряд*/
	}

	for (int i = n - 1; i >= 1; i--) {
		swap(&mas[0], &mas[i]);
		PyramidFormation(mas, 0, i - 1);  /*Формируем остальные элементы пирамиды*/
	}


	for (int i = 0; i < n; i++) {
		printf("mas[%d] = %d\n", i, mas[i]);
	}

	time = wtime() - time;
	printf("Work time: %f sec.\n", time);  
}




int main()
{
	INT *mas = NULL;
	int i;
	short choice;

	mas = malloc(n * sizeof(INT));
		for (i = 0; i < n; i++) {
			mas[i] = i;
		}


	for (i = 0; i < n; i++) {
		mas[i] = getrand(0, 10000);
	}

	printf("Press '1' for Counting Sort\n");
	printf("Press '2' for Insertion Sort\n");
	printf("Press '3' for Heap Sort\n");
		scanf("%hd", &choice);

	if (choice != 1 && choice != 2 && choice != 3)
		printf("Unknown sort\n");

	if (choice == 1)
		CountingSort(mas);

	if (choice == 2)
		InsertionSort(mas);

	if (choice == 3)
		HeapSort(mas);
}