#include<iostream>
#include<ctime>

using namespace std;
void checksort(int a[], int n) { //�˸°� ���ĵǾ����� Ȯ�� //������������Ȯ��
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
        cout << "������ �Ϻ��մϴ�!" << "\n";
    }
    else {
        cout << "���Ŀ� ������ �߻��߽��ϴ�.." << "\n";
    }
}
void quick(int *arr,int st, int en) {
    if (en <= st + 1) return; //ũ�Ⱑ 1���� ������ return
    int first = st; 
    int mid = (st + en) / 2;
    int rear = en-1; // �迭�� 0���� �����ϹǷ�
    if (arr[first] > arr[mid]) swap( arr[first], arr[mid]); //ù���� �߰��� ��
    if (arr[mid] > arr[rear]) swap( arr[mid], arr[rear]); // �߰����� ������
    if (arr[first] > arr[mid]) swap( arr[first], arr[mid]);//�߰����� �߰����� �ùٸ��� ���ĵ�
    swap(arr[mid], arr[first]); //arr[first]�� �߰���  //pivot�� �迭�� ù������ �����ϱ����� �߰����� first�� swap����      
        int p = arr[st]; //�Ǻ��� �߰������� ����
        int l = st + 1; //st�� �Ǻ��̹Ƿ� +1
        int r = en - 1; //�迭�� 0���� �����ϹǷ�
        while (1) {
            while (l <= r && arr[l] <= p) l++; //pivot���� ������ left �����͸� ������Ų��.
            while (l <= r && arr[r] >= p) r--;//pivot���� ũ�� right �����͸� ���ҽ�Ų��.
            if (l > r) break; //left�� right ���� �� Ŀ���ٸ� while �� ������
            swap(arr[l], arr[r]); //left �����Ϳ� right �����Ͱ� ����Ű�� ���� swap�ϱ�
        }
        swap(arr[r], arr[st]); //pivot�� right �����Ͱ� ����Ű�� �� swap
        quick(arr,st, r); //ó������ r ���� �ٽ� ����
        quick(arr,r + 1, en); //r+1 ���� ������ �ٽ� quick ����
    
}
void insertion(int* arr, int front, int last, int gap) { //gap�� ������ ��������
    int key;
    int i, j;
    for (i = front + gap; i < last; i += gap) { //ù���� ���ĵǾ��ִ� ���� ���⶧���� i = front + gap;
        key = arr[i]; 
        for (j = i - gap; j >= front; j -= gap) { 
            if (key < arr[j]) {//key ���� ū���� �ִٸ�
                arr[j + gap] = arr[j]; //i (��, key���� ���� ū������ ������.
            }
            else break; 

        }

        arr[j + gap] = key; //������� ���� ���� ���� ���� key�� �ٲ۴�.
    }

}

void shell_sort(int* arr, int n) {
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if (gap % 2 == 0) { //Ȧ���� ��������//¦���϶��� +1;
            gap++;
        }
        for (i = 0; i < gap; i++) {
            insertion(arr, i, n, gap); //insertion�� ������� �� ����
        }
    }
}
float start1, start2, end1, end2, res1, res2;
int arr1[];
#define mil 100000//�ʸ�
#define mil2 1000000//�鸸
#define mil3 10000000//õ��
int arr1[mil];
int arr2[mil];
int arr12[mil2];
int arr22[mil2];
int arr13[mil3];
int arr23[mil3];
int main() {
    
    srand(time(NULL));
    for (int i = 0; i < mil; i++) { //10������ ������ �߻��Ͽ� arr2�� �־��ش�.
        arr1[i] = rand() % mil;
        arr2[i] = arr1[i];//���� ���ǿ��� �ҿ�ð� ������ ���ؼ� 
    }
    
    start1 = clock(); //�����ϴ� �ð�
    quick(arr1, 0, mil);
    end1 = clock(); //������ ������ �ð�
    res1 = (float)(end1 - start1); //�ҿ�ð�
    cout << "������ quick_sort�� �ʸ��� ������ �ҿ�ð��� : " << res1 << "ms�Դϴ�." << "\n"; //�ҿ�ð� ���
    checksort(arr1, mil); //������ �ߵǾ��� Ȯ��

    start2 = clock(); //�����ϴ� �ð�
    shell_sort(arr2, mil);
    end2 = clock(); //������ ������ �ð�
    res1 = (float)(end2 - start2); //�ҿ�ð�
    cout << "������ shell_sort�� �ʸ��� ������ �ҿ�ð��� : " << res1 << "ms�Դϴ�." << "\n"; //�ҿ�ð� ���
    checksort(arr2, mil); //������ �ߵǾ��� Ȯ��
/////////////////////////////////////////////////////////////////////////////////////////////////////
    srand(time(NULL));
    for (int i = 0; i < mil2; i++) { //100������ ������ �߻��Ͽ� arr2�� �־��ش�.
        arr12[i] = rand() % mil2;
        arr22[i] = arr12[i]; //���� ���ǿ��� �ҿ�ð� ������ ���ؼ� 
    }
    
    start1 = clock(); //�����ϴ� �ð�
    quick(arr12, 0, mil2);
    end1 = clock(); //������ ������ �ð�
    res1 = (float)(end1 - start1); //�ҿ�ð�
    cout << "������ quick_sort�� �鸸�� ������ �ҿ�ð��� : " << res1 << "ms�Դϴ�." << "\n"; //�ҿ�ð� ���
    checksort(arr1, mil); //������ �ߵǾ��� Ȯ��

    start2 = clock(); //�����ϴ� �ð�
    shell_sort(arr22, mil2);
    end2 = clock(); //������ ������ �ð�
    res1 = (float)(end2 - start2); //�ҿ�ð�
    cout << "������ shell_sort�� �鸸�� ������ �ҿ�ð��� : " << res1 << "ms�Դϴ�." << "\n"; //�ҿ�ð� ���
    checksort(arr22, mil2); //������ �ߵǾ��� Ȯ��
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    srand(time(NULL));
    for (int i = 0; i < mil3; i++) { //õ������ ������ �߻��Ͽ� arr2�� �־��ش�.
        arr13[i] = rand() % mil3;  //���� ����
        arr23[i] = arr13[i]; //���� ���� ����
    }
  
    start1 = clock(); //�����ϴ� �ð�
    quick(arr13, 0, mil3);
    end1 = clock(); //������ ������ �ð�
    res1 = (float)(end1 - start1); //�ҿ�ð�
    cout << "������ quick_sort�� õ���� ������ �ҿ�ð��� : " << res1 << "ms�Դϴ�." << "\n"; //�ҿ�ð� ���
    checksort(arr13, mil3); //������ �ߵǾ��� Ȯ��

    start2 = clock(); //�����ϴ� �ð�
    shell_sort(arr23, mil3);
    end2 = clock(); //������ ������ �ð�
    res1 = (float)(end2 - start2); //�ҿ�ð�
    cout << "������ shell_sort�� õ���� ������ �ҿ�ð��� : " << res1 << "ms�Դϴ�." << "\n"; //�ҿ�ð� ���
    checksort(arr23, mil3); //������ �ߵǾ��� Ȯ��
    cout << "������Ű��а� 12191728 ��ι�";
        
}


 
