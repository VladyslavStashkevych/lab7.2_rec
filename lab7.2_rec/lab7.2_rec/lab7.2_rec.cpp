// lab7.2_rec.cpp
// <Сташкевич Владислав>
// Лабораторна робота № 7.2
// Опрацювання багатовимірних масивів ітераційними та рекурсивними способами
// Варіант 19

#include <iostream>
#include <iomanip>

using namespace std;

int** ArrayBuilder(int** arr, const int size, const int Low, const int High, int i, int j);
void PrintArray(int** arr, const int size, const int i, const int j);
int IndexMax(int* arr, const int size, int max, int index, int i);
int** DiagChanger(int** arr, const int size, const int i);

int main() {
	srand((unsigned)time(NULL));
	int n = 5,
		Low = 0,
		High = 99;

	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	cout << " Matrix:\n\n";
	arr = ArrayBuilder(arr, n, Low, High, 0, 0);
	PrintArray(arr, n, 0, 0);


	cout << "\n\n New matrix: \n\n";
	arr = DiagChanger(arr, n, 0);
	PrintArray(arr, n, 0, 0);

	return 0;
}

int** ArrayBuilder(int** arr, const int size, const int Low, const int High, int i, int j) {
	if (i >= size) {
		return arr;
	}
	else {
		if (j >= size) {
			return ArrayBuilder(arr, size, Low, High, i + 1, 0);
		}
		else {
			arr[i][j] = Low + rand() % (High - Low + 1);
			return ArrayBuilder(arr, size, Low, High, i, j + 1);
		}
	}
		
}

void PrintArray(int** arr, const int size, const int i, const int j) {
	if (i < size)
		if (j < size) {
			cout << setw(3) << arr[i][j];
			PrintArray(arr, size, i, j + 1);
		}
		else {
			cout << endl;
			PrintArray(arr, size, i + 1, 0);
		}
}

int IndexMax(int* arr, const int size, int max, int index, int i) {
	if (i >= size)
		return index;
	else
		if (arr[i] > max) {
			index = i;
			max = arr[i];
		}

	return IndexMax(arr, size, max, index, i + 1);
}

int** DiagChanger(int** arr, const int size, const int i) {
	int temp, 
		index;

	if (i >= size)
		return arr;
	else {
		index = IndexMax(arr[i], size, arr[i][0], 0, 0);
		temp = arr[i][index];
		arr[i][index] = arr[i][i];
		arr[i][i] = temp;
	}

	return DiagChanger(arr, size, i + 1);
}