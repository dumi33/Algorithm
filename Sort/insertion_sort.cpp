#include<iostream>
using namespace std;

int arr[] = { 24,51,1,42,23 };
int key, j;
void insertion(int* arr, int size) {
	for (int i = 1; i < size; i++) { //0번째 원소는 정렬되었다고 가정 //size -1 만큼 돌면서
		key = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > key) arr[j + 1] = arr[j]; //큰 수를 나한테 덮는다.
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

 
 
