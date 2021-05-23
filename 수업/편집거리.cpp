#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;

string S , T;
float dis[101][101];
char A[20], B[20];
int leven(string s, string t) {
	for (int i = 1; i <= s.size(); i++) { // 0행에 1열부터  1부터  s의 길이만큼 1씩 증가하는수를 0행에 넣어준다.
		dis[i][0] = i;
	}
	for (int j = 1; j<= t.size(); j++) {// 1행에 0열부터  1부터  t의 길이만큼 1씩 증가하는수를 배열에 넣어준다.
		dis[0][j] = j;
	}
	for (int j = 1; j <= t.size(); j++) { // 이차원배열을 모두 돌면서
		for (int i = 1; i <= s.size(); i++) {
			if (s[i - 1] == t[j - 1]) dis[i][j] = dis[i - 1][j - 1]; // 비교할 글자가 동일할경우 대각선의 값을 배열에 넣는다.
			else dis[i][j] = min(dis[i - 1][j - 1] + 1, min(dis[i][j - 1] + 1, dis[i - 1][j] + 1)); // 글자가 동일하지 않을경우 (위, 왼쪽,대각선의 값 )+1 중 가장 작은 값을 넣어준다. 
		}
	}
	for (int j = 0; j <= t.size(); j++) { // 이차원 배열을 출력한다.
		for (int i = 0; i <= s.size(); i++) {
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	return dis[s.size()][ t.size()]; // 편집하는데 필요한 최소 비용을 출력한다.
}
float leven2(string s, string t) {// 위의 leven함수와 삽입, 삭제, 교환 비용의 값을 제외하고 동일함
	for (int i = 1; i <= s.size(); i++) {
		dis[i][0] = i*0.5;
	}
	for (int j = 1; j <= t.size(); j++) {
		dis[0][j] = j * 0.7;
	}
	for (int j = 1; j <= t.size(); j++) { 
		for (int i = 1; i <= s.size(); i++) {
			if (s[i - 1] == t[j - 1]) dis[i][j] = dis[i - 1][j - 1];
			else dis[i][j] = min(dis[i - 1][j - 1] + 0.3, min(dis[i][j - 1] + 0.7, dis[i - 1][j] + 0.5)); // 삽입은 0.7, 교환은 0.3 ,삭제는 0.5로 비용을 설정
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
void leven3(string s, string t) {// 위의 leven2함수와 삽입, 삭제, 교환이 발생한 값을 출력하는 것을 제외하고 동일함
	int a=0, b=0, c=0;//교환 : a, 삽입 : b ,삭제 : c
	for (int i = 1; i <= s.size(); i++) {
		dis[i][0] = i * 0.5;
	}
	for (int j = 1; j <= t.size(); j++) {
		dis[0][j] = j * 0.7;
	}
	for (int j = 1; j <= t.size(); j++) {
		for (int i = 1; i <= s.size(); i++) {
			if (s[i - 1] == t[j - 1]) {//같을경우 -> 아무것도 발생하지않음
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
	if (t.size() > s.size()) { // t가 더 클경우 
		b = t.size() - s.size(); // 그 차이는 삽입되어야한다.
		for (int i = 0; i < s.size(); i++) { // 문자가 다를때 교체
			if (s[i] != t[i]) a++;
		}
	}
	else {// s가 더 클경우
		c = s.size() - t.size();  // 그 차이는 삭제되어야한다.
		for (int i = 0; i < t.size(); i++) { // 문자가 다를때 교체
			if (s[i] != t[i]) a++;
		}
	}
	cout<<"교환연산 : "<<a*0.3 <<" 삽입연산 : "<<b*0.7 <<" 삭제연산 : "<<c * 0.5 <<" Levenshtein Distance : "<<dis[s.size()][t.size()];
}

int main() {
	
	
	cin >> S >> T;
	cout <<"비용이 모두 1인 경우  Levenshtein Distance : " << leven(S, T) <<"입니다\n\n";
	cout << "비용이 다를경우  Levenshtein Distance : " << leven2(S, T) << "입니다\n";
	cout << "\n12191728_정보통신공학과_김두미\n\n";
	for (int i = 0; i < 2; i++) {
		cin >> S >> T;
		leven3(S, T);
	}
	cout << "\n12191728_정보통신공학과_김두미\n\n";
	
	}
