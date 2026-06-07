// 프로그래머스 문제: 기능개발
// https://school.programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int n = 100; // Array size

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int MaxDay = 0;
    vector<int> answer;

    for (int i = 0; i < progresses.size(); i++) {
        int current = (100 - progresses[i] + speeds[i] - 1) / speeds[i]; // 올림 공식

        if (current > MaxDay) {
            MaxDay = current;
            answer.push_back(1);
        } else {
            answer.back()++;
        }
    }

    return answer;
}