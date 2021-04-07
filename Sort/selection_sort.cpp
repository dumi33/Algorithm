#include<iostream>
using namespace std;

int arr[] = { 24,51,1,42,23 };
int key, j;

void selection(int* arr, int size) {
	int i, j, small;
	for (i = 0; i < size - 1; i++) {
		small = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[small]) small = j;
		}
		if (i!= small) {
			swap(arr[i], arr[small]);
		}
	}
}

int main() {
	int size = (sizeof(arr) / sizeof(int));

	selection(arr, size);
	
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

 
 
