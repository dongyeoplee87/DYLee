#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

#define ARRAY_SIZE  4
int N;
int arr[ARRAY_SIZE];

void InputData(){
	cin >> N;
}

void Print(int *array) {
    for(int i=0; i<ARRAY_SIZE; i++) {
        printf("[%d]%d\n", i, arr[i]);
    }
}

void IntToArr(int value, int *arr) {
    // printf("Input : %d\n", value);

    arr[0] = value / 1000;
    value = value - (arr[0]*1000);
    arr[1] = value / 100;
    value = value - (arr[1]*100);
    arr[2] = value / 10;
    value = value - (arr[2]*10);
    arr[3] = value % 10;

    // Print(arr);
}


#ifdef DECENDING_ORDER
void Sort(int *array) {
    sort(array,array+4);
}

int Cal(int *array) {
    Sort(array);

    int max = 0;
    max += array[0];
    max += array[1]*10;
    max += array[2]*100;
    max += array[3]*1000;
    // printf("max:%d\n",max);

    int min = 0;
    min += array[3];
    min += array[2]*10;
    min += array[1]*100;
    min += array[0]*1000;
    // printf("min:%d\n",min);

    return max-min;
}
#else
void Sort(int *array) {
    sort(array,array+4,[](int a, int b){return a > b;});
}

int Cal(int *array) {
    Sort(array);

    int max = 0;
    max += array[3];
    max += array[2]*10;
    max += array[1]*100;
    max += array[0]*1000;
    // printf("max:%d\n",max);

    int min = 0;
    min += array[0];
    min += array[1]*10;
    min += array[2]*100;
    min += array[3]*1000;
    // printf("min:%d\n",min);

    return max-min;
}
#endif // DECENDING_ORDER


int main(){
	int ans = -1;
	InputData();// 입력받는 부분
    //IntToArr(N, arr);

    int ret = 0;
    while(1) {
        ans++;
        if (N == 6174)
            break;
        else {
            IntToArr(N, arr);
            N = Cal(arr);
        }
    }

	cout << ans << endl;// 출력하는 부분

	return 0;
}