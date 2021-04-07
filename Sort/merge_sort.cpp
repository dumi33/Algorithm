#include<iostream>
using namespace std;
int tmp[1000001];
int arr[] = { 24,54,78,45,12,6,2,3 };
void merge(int st, int en) {
    int mid = (st + en) / 2;
    int lidx = st; //left 부터 mid 까지 볼생각
    int ridx = mid; // mid부터 right 까지 볼생각
    for (int i = st; i < en; i++) {
        if (ridx == en) tmp[i] = arr[lidx++]; //right index reach end
        else if (lidx == mid) tmp[i] = arr[ridx++]; //left index reach mid
        else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for (int i = st; i < en; i++) {
        arr[i] = tmp[i];
    }
}
void merge_sort(int st, int en) {
    if (en == st + 1) return; //list's length is 1
    int mid = (st + en)/2;
    merge_sort(st, mid); // st:mid_sort
    merge_sort(mid, en); // mid:en_sort
    merge(st, en); // arr[st:en] & arr[mid:en] _ sort

}
int main() {
    int size = sizeof(arr) / sizeof(int);
    merge_sort(0, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

 
 
