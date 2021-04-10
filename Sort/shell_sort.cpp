#include<iostream>
using namespace std;
int arr[] = { 343,64,3,5,2,23,4,5 };
void insertion(int *arr, int first, int last, int gap) {
    int key, i,j;
    for (i = first + gap; i <= last; i += gap) {
        key = arr[i];
        for ( j = i - gap; first <= j ; j -= gap) {
            if (key < arr[j]) {
                arr[j + gap] = arr[j];
            }
            else break;
            
        }
        
        arr[j + gap] = key;
    }
    
}

void shell_sort(int *arr, int n) {
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if (gap % 2 == 0) { //홀수가 좋은가보다//짝수일때는 +1;
            gap++;
        }
        for (i = 0; i < gap; i++) {
            insertion(arr, i, n - 1, gap);
        }
    }
}
int main() {
    int size = sizeof(arr) / sizeof(int);
    
    shell_sort(arr, size);
    for (int i = 0;  i < size; i++) {
        cout << arr[i] << " ";
    }
}


 
