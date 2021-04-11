#include<iostream>
#include<ctime>

using namespace std;
void checksort(int a[], int n) { //알맞게 정렬되었는지 확인 //오름차순정렬확인
    int i;
    int sorted = true;
    for (i = 0; i < n-1; i++) {
        if (a[i] > a[i + 1]) {
            sorted = false;
        }
        if (!sorted) {
            break;
        }

    }
    if (sorted) {
        cout << "정렬이 완벽합니다!" << "\n";
    }
    else {
        cout << "정렬에 문제가 발생했습니다.." << "\n";
    }
}
void quick(int *arr,int st, int en) {
    if (en <= st + 1) return; //크기가 1보다 작으면 return
    int first = st; 
    int mid = (st + en) / 2;
    int rear = en-1; // 배열은 0부터 시작하므로
    if (arr[first] > arr[mid]) swap( arr[first], arr[mid]); //첫값과 중간값 비교
    if (arr[mid] > arr[rear]) swap( arr[mid], arr[rear]); // 중간값과 끝값비교
    if (arr[first] > arr[mid]) swap( arr[first], arr[mid]);//중간값이 중간으로 올바르게 정렬됨
    swap(arr[mid], arr[first]); //arr[first]가 중간값  //pivot을 배열의 첫값으로 설정하기위해 중간값을 first와 swap했음      
        int p = arr[st]; //피봇을 중간값으로 설정
        int l = st + 1; //st는 피봇이므로 +1
        int r = en - 1; //배열은 0부터 시작하므로
        while (1) {
            while (l <= r && arr[l] <= p) l++; //pivot보다 작으면 left 포인터를 증가시킨다.
            while (l <= r && arr[r] >= p) r--;//pivot보다 크면 right 포인터를 감소시킨다.
            if (l > r) break; //left가 right 보다 더 커진다면 while 문 나가기
            swap(arr[l], arr[r]); //left 포인터와 right 포인터가 가리키는 숫자 swap하기
        }
        swap(arr[r], arr[st]); //pivot과 right 포인터가 가리키는 곳 swap
        quick(arr,st, r); //처음부터 r 까지 다시 정렬
        quick(arr,r + 1, en); //r+1 부터 끝까지 다시 quick 정렬
    
}
void insertion(int* arr, int front, int last, int gap) { //gap을 가지는 삽입정렬
    int key;
    int i, j;
    for (i = front + gap; i < last; i += gap) { //첫값은 정렬되어있는 수로 보기때문에 i = front + gap;
        key = arr[i]; 
        for (j = i - gap; j >= front; j -= gap) { 
            if (key < arr[j]) {//key 보다 큰것이 있다면
                arr[j + gap] = arr[j]; //i (즉, key였던 곳을 큰값으로 덮어씌운다.
            }
            else break; 

        }

        arr[j + gap] = key; //덮어씌었던 값중 가장 작은 값을 key로 바꾼다.
    }

}

void shell_sort(int* arr, int n) {
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if (gap % 2 == 0) { //홀수로 만들어야함//짝수일때는 +1;
            gap++;
        }
        for (i = 0; i < gap; i++) {
            insertion(arr, i, n, gap); //insertion을 기반으로 한 정렬
        }
    }
}
float start1, start2, end1, end2, res1, res2;
int arr1[];
#define mil 100000//십만
#define mil2 1000000//백만
#define mil3 10000000//천만
int arr1[mil];
int arr2[mil];
int arr12[mil2];
int arr22[mil2];
int arr13[mil3];
int arr23[mil3];
int main() {
    
    srand(time(NULL));
    for (int i = 0; i < mil; i++) { //10만까지 난수를 발생하여 arr2에 넣어준다.
        arr1[i] = rand() % mil;
        arr2[i] = arr1[i];//같은 조건에서 소요시간 측정을 위해서 
    }
    
    start1 = clock(); //시작하는 시간
    quick(arr1, 0, mil);
    end1 = clock(); //정렬이 끝나는 시간
    res1 = (float)(end1 - start1); //소요시간
    cout << "변형된 quick_sort의 십만개 원소의 소요시간은 : " << res1 << "ms입니다." << "\n"; //소요시간 출력
    checksort(arr1, mil); //정렬이 잘되었나 확인

    start2 = clock(); //시작하는 시간
    shell_sort(arr2, mil);
    end2 = clock(); //정렬이 끝나는 시간
    res1 = (float)(end2 - start2); //소요시간
    cout << "변형된 shell_sort의 십만개 원소의 소요시간은 : " << res1 << "ms입니다." << "\n"; //소요시간 출력
    checksort(arr2, mil); //정렬이 잘되었나 확인
/////////////////////////////////////////////////////////////////////////////////////////////////////
    srand(time(NULL));
    for (int i = 0; i < mil2; i++) { //100만까지 난수를 발생하여 arr2에 넣어준다.
        arr12[i] = rand() % mil2;
        arr22[i] = arr12[i]; //같은 조건에서 소요시간 측정을 위해서 
    }
    
    start1 = clock(); //시작하는 시간
    quick(arr12, 0, mil2);
    end1 = clock(); //정렬이 끝나는 시간
    res1 = (float)(end1 - start1); //소요시간
    cout << "변형된 quick_sort의 백만개 원소의 소요시간은 : " << res1 << "ms입니다." << "\n"; //소요시간 출력
    checksort(arr1, mil); //정렬이 잘되었나 확인

    start2 = clock(); //시작하는 시간
    shell_sort(arr22, mil2);
    end2 = clock(); //정렬이 끝나는 시간
    res1 = (float)(end2 - start2); //소요시간
    cout << "변형된 shell_sort의 백만개 원소의 소요시간은 : " << res1 << "ms입니다." << "\n"; //소요시간 출력
    checksort(arr22, mil2); //정렬이 잘되었나 확인
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    srand(time(NULL));
    for (int i = 0; i < mil3; i++) { //천만까지 난수를 발생하여 arr2에 넣어준다.
        arr13[i] = rand() % mil3;  //난수 넣음
        arr23[i] = arr13[i]; //같은 난수 넣음
    }
  
    start1 = clock(); //시작하는 시간
    quick(arr13, 0, mil3);
    end1 = clock(); //정렬이 끝나는 시간
    res1 = (float)(end1 - start1); //소요시간
    cout << "변형된 quick_sort의 천만개 원소의 소요시간은 : " << res1 << "ms입니다." << "\n"; //소요시간 출력
    checksort(arr13, mil3); //정렬이 잘되었나 확인

    start2 = clock(); //시작하는 시간
    shell_sort(arr23, mil3);
    end2 = clock(); //정렬이 끝나는 시간
    res1 = (float)(end2 - start2); //소요시간
    cout << "변형된 shell_sort의 천만개 원소의 소요시간은 : " << res1 << "ms입니다." << "\n"; //소요시간 출력
    checksort(arr23, mil3); //정렬이 잘되었나 확인
    cout << "정보통신공학과 12191728 김두미";
        
}


 
