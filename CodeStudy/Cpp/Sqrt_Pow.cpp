#include <iostream>
#include <math.h> // sqrt, pow
using namespace std;

#ifdef DBG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif // DBG

int R;//원의 반지름

void InputData(){
	cin >> R;
}

int GetHeight(int x) {
    double height = sqrt(pow(R,2)-pow(x,2));
    DEBUG("DEBUG. R[%d] x[%d] height[%f] return[%d]\n", R, x, height, (int)height);
    return (int)height;
}

int main() {
	int ans = 0;
	InputData();//입력

    for(int i=1; i<=R; i++) {
        ans += GetHeight(i);
        DEBUG("DEBUG. cur ans:%d\n", ans);
    }
    ans *= 4;

	cout << ans << endl;//출력
	return 0;
}