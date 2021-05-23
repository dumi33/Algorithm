#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;

string S , T;
float dis[101][101];
char A[20], B[20];
int leven(string s, string t) {
	for (int i = 1; i <= s.size(); i++) { // 0�࿡ 1������  1����  s�� ���̸�ŭ 1�� �����ϴ¼��� 0�࿡ �־��ش�.
		dis[i][0] = i;
	}
	for (int j = 1; j<= t.size(); j++) {// 1�࿡ 0������  1����  t�� ���̸�ŭ 1�� �����ϴ¼��� �迭�� �־��ش�.
		dis[0][j] = j;
	}
	for (int j = 1; j <= t.size(); j++) { // �������迭�� ��� ���鼭
		for (int i = 1; i <= s.size(); i++) {
			if (s[i - 1] == t[j - 1]) dis[i][j] = dis[i - 1][j - 1]; // ���� ���ڰ� �����Ұ�� �밢���� ���� �迭�� �ִ´�.
			else dis[i][j] = min(dis[i - 1][j - 1] + 1, min(dis[i][j - 1] + 1, dis[i - 1][j] + 1)); // ���ڰ� �������� ������� (��, ����,�밢���� �� )+1 �� ���� ���� ���� �־��ش�. 
		}
	}
	for (int j = 0; j <= t.size(); j++) { // ������ �迭�� ����Ѵ�.
		for (int i = 0; i <= s.size(); i++) {
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	return dis[s.size()][ t.size()]; // �����ϴµ� �ʿ��� �ּ� ����� ����Ѵ�.
}
float leven2(string s, string t) {// ���� leven�Լ��� ����, ����, ��ȯ ����� ���� �����ϰ� ������
	for (int i = 1; i <= s.size(); i++) {
		dis[i][0] = i*0.5;
	}
	for (int j = 1; j <= t.size(); j++) {
		dis[0][j] = j * 0.7;
	}
	for (int j = 1; j <= t.size(); j++) { 
		for (int i = 1; i <= s.size(); i++) {
			if (s[i - 1] == t[j - 1]) dis[i][j] = dis[i - 1][j - 1];
			else dis[i][j] = min(dis[i - 1][j - 1] + 0.3, min(dis[i][j - 1] + 0.7, dis[i - 1][j] + 0.5)); // ������ 0.7, ��ȯ�� 0.3 ,������ 0.5�� ����� ����
		}
	}
	for (int j = 0; j <= t.size(); j++) {
		for (int i = 0; i <= s.size(); i++) {
			cout << dis[i][j] << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
	return dis[s.size()][t.size()];
}
void leven3(string s, string t) {// ���� leven2�Լ��� ����, ����, ��ȯ�� �߻��� ���� ����ϴ� ���� �����ϰ� ������
	int a=0, b=0, c=0;//��ȯ : a, ���� : b ,���� : c
	for (int i = 1; i <= s.size(); i++) {
		dis[i][0] = i * 0.5;
	}
	for (int j = 1; j <= t.size(); j++) {
		dis[0][j] = j * 0.7;
	}
	for (int j = 1; j <= t.size(); j++) {
		for (int i = 1; i <= s.size(); i++) {
			if (s[i - 1] == t[j - 1]) {//������� -> �ƹ��͵� �߻���������
				dis[i][j] = dis[i - 1][j - 1];
			}
			else {
				dis[i][j] = min(dis[i - 1][j - 1] + 0.3, min(dis[i][j - 1] + 0.7, dis[i - 1][j] + 0.5));
			}
		}
	}
	for (int j = 0; j <= t.size(); j++) {
		for (int i = 0; i <= s.size(); i++) {
			cout << dis[i][j] << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
	if (t.size() > s.size()) { // t�� �� Ŭ��� 
		b = t.size() - s.size(); // �� ���̴� ���ԵǾ���Ѵ�.
		for (int i = 0; i < s.size(); i++) { // ���ڰ� �ٸ��� ��ü
			if (s[i] != t[i]) a++;
		}
	}
	else {// s�� �� Ŭ���
		c = s.size() - t.size();  // �� ���̴� �����Ǿ���Ѵ�.
		for (int i = 0; i < t.size(); i++) { // ���ڰ� �ٸ��� ��ü
			if (s[i] != t[i]) a++;
		}
	}
	cout<<"��ȯ���� : "<<a*0.3 <<" ���Կ��� : "<<b*0.7 <<" �������� : "<<c * 0.5 <<" Levenshtein Distance : "<<dis[s.size()][t.size()];
}

int main() {
	
	
	cin >> S >> T;
	cout <<"����� ��� 1�� ���  Levenshtein Distance : " << leven(S, T) <<"�Դϴ�\n\n";
	cout << "����� �ٸ����  Levenshtein Distance : " << leven2(S, T) << "�Դϴ�\n";
	cout << "\n12191728_������Ű��а�_��ι�\n\n";
	for (int i = 0; i < 2; i++) {
		cin >> S >> T;
		leven3(S, T);
	}
	cout << "\n12191728_������Ű��а�_��ι�\n\n";
	
	}
