#include<iostream>
using namespace std;
int arr[] = { 24,51,1,42,23 };
void swap2(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void bubble(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) swap2( &arr[j], &arr[j + 1]);
		}
	}
}
int main() {
	int size = (sizeof(arr) / sizeof(int));
	bubble(arr, size);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}