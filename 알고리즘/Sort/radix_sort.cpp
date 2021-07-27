#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int arr[8] = { 170,45,75,90,2,24,802,66 };
void rxsort(int* data, int size, int p, int k) {
	int* count, * temp;
	int index, pval, i, j, n;
	if ((count = (int*)malloc(k * sizeof(int))) == NULL) return;
	if ((temp = (int*) malloc(size * sizeof(int))) == NULL) return;
	for (int n = 0; n < p; n++) {
		for (int i = 0; i < k; i++) {
			count[i] = 0;
			pval = (int)pow((double)k, (double)n);
		}
		for (int j = 0; j < size; j++) {
			index = (int)(data[j] / pval) % k;
			count[index] = count[index] + 1;
		}
		for (int i = 1; i < k; i++) {
			count[i] = count[i] + count[i - 1];
		}
		for (int j = size - 1; j >= 0; j--) {
			index = (int)(data[j] / pval) % k;
			temp[count[index] - 1] = data[j];
			count[index] = count[index] - 1;
		}
		memcpy(data, temp, size * sizeof(int));
		
	}
	
}
int main() {
	int arrsize = sizeof(arr) / sizeof(int);
	
	cout << "정렬 전 출력\n";
	for (int i = 0; i < arrsize; i++) {
		cout << arr[i] << " ";
	}
	rxsort(arr, arrsize, 3, 10); //정렬 
	cout << "\n정렬 이후 출력\n";
	for (int i = 0; i < arrsize; i++) {
		cout << arr[i] << " ";
	}

	cout << "\n정보통신공학과 / 12191728 / 김두미";
}