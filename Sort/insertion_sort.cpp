#include<iostream>
using namespace std;

int arr[] = { 24,51,1,42,23 };
int key, j;
void insertion(int* arr, int size) {
	for (int i = 1; i < size; i++) { //size -1 ��ŭ ���鼭
		key = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > key) arr[j + 1] = arr[j]; //ū ���� ������ ���´�.
			else break;
		}
		arr[j + 1] = key;
	}
}



int main() {
	int size = (sizeof(arr) / sizeof(int));
	insertion(arr, size);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

 
 
