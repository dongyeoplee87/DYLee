#include <iostream>
#include <algorithm>    // std::sort
#include <numeric>
using namespace std;

int N;//정수

class Fraction {
public :
    Fraction(int num, int denomi) : numerator(num), denominator(denomi) {}
    Fraction() {}
    void Print() {
        int val_gdc = __gcd((int)this->numerator, (int)this->denominator);
        printf("%d/%d\n", this->numerator/val_gdc, this->denominator/val_gdc);
    }
    double ShowVal() {
        return ((double)this->numerator / (double)this->denominator);
    }

// private :
    int numerator; // 분자
    int denominator; // 분모
};

void InputData(){
	cin >> N;
}

int main() {
	InputData(); //입력

    int index = 0;

    int maxIndex = 2;
    for(int i=2;i<=N;i++) {
        maxIndex += (i-1);
    }

    Fraction data[maxIndex];
    data[0] = Fraction(0,1);
    data[1] = Fraction(1,1);
    index += 2;

    for(int i=2;i<=N;i++) {
        for(int j=1;j<i;j++) {
            data[index] = Fraction(j,i);
            index++;
        }
    }

    sort(data, &data[index], [](Fraction a, Fraction b) {
        int multi = a.denominator * b.denominator;
        return ((a.numerator * multi / a.denominator) < (b.numerator * multi / b.denominator));
    });

    double beforeValue = -1;
    for(int i=0; i<index; i++) {
        if (beforeValue != data[i].ShowVal()) {
                data[i].Print();
            beforeValue = data[i].ShowVal();
        }
    }

	return 0;
}