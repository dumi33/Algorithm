#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer; // 반환할 정답 

    vector<int> answer1{ 1,2,3,4,5 };
    vector<int> answer2{ 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> answer3{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    for (int i = 0; i < answers.size(); i++) {
        int i1 = i % 5;  // 0~4까지만 
        int i2 = i % 8;
        int i3 = i % 10;

        if (answers[i] == answer1[i1]) cnt1++;
        if (answers[i] == answer2[i2]) cnt2++;
        if (answers[i] == answer3[i3]) cnt3++;
    }
    int mx = max(cnt1, (max(cnt2, cnt3)));
    if (mx == cnt1) answer.push_back(1);
    if (mx == cnt2) answer.push_back(2);
    if (mx == cnt3) answer.push_back(3);
    return answer;
}