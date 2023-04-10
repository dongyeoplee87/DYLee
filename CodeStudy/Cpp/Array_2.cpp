#include <iostream>
#include <cstring>  // strlen
using namespace std;

//#define DBG
#ifdef DBG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

char str[100000 + 10];//쇠막대기와 레이저의 배치를 나타내는 괄호 표현 문자열

void InputData(){
	cin >> str;
}

int main() {
	int ans = 0;
	InputData();//입력

	//여기서부터 작성
    int stack = 0;
    int length = strlen(str);
    DEBUG("length:%d. str:%s\n",length,str);
    for(int i=0;i<length;i++) {
        if(str[i]=='(') {
            if(str[i+1] == ')') {
                ans += stack;
                DEBUG("%d : This is laser. current ans:%d and stack:%d\n", i, ans, stack);
                i++; // skip next
            } else {
                stack++;
                DEBUG("%d : Add stack. current ans:%d and stack:%d\n", i, ans, stack);
            }
        } else if (str[i] == ')') {
            stack--;
            ans++;
            DEBUG("%d : Remove stack. current ans:%d and stack:%d\n", i, ans, stack);
        }
    }

	cout << ans << endl;//출력
	return 0;
}