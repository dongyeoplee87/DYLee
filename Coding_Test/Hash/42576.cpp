// 프로그래머스 문제: 완주하지 못한 선수
// https://school.programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> freq;

    for (const auto& p : participant) {
        freq[p]++;
    }

    for (const auto& c : completion) {
        freq[c]--;
    }

    for (const auto& [name, cnt] : freq) {
        if (cnt > 0)
            return name;
    }

    return "";
}