#include<iostream>
using namespace std;
int arr[] = { 4,3,5,34,34,2,425,2,1};
void quick(int st, int en) {
    if (en <= st + 1) return;
    int first = st;
    int mid = (st + en) / 2;
    int rear = en-1;
    if (arr[first] > arr[mid]) swap( arr[first], arr[mid]);
    if (arr[mid] > arr[rear]) swap( arr[mid], arr[rear]);
    if (arr[first] > arr[mid]) swap( arr[first], arr[mid]);//�߰����� �߰����� ���ĵ�
    swap(arr[mid], arr[first]); //arr[first]�� �߰���        
        int p = arr[st]; //�Ǻ��� �߰������� ����
        int l = st + 1; //
        int r = en - 1;
        while (1) {
            while (l <= r && arr[l] <= p) l++;
            while (l <= r && arr[r] >= p) r--;
            if (l > r) break;
            swap(arr[l], arr[r]);
        }
        swap(arr[r], arr[st]);
        quick(st, r);
        quick(r + 1, en);
    
}
int main() {
    int size = sizeof(arr) / sizeof(int);
    quick(0, size);
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
         }
}


 
