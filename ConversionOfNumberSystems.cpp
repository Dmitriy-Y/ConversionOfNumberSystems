
#include<iostream>
#include<cstring>
using namespace std;
int exp(int a, int n) {
    int exp = 1;
    while(n>0) {
        exp *=a;
        n--;
    }
    return exp;
}

void ConversionFromSourceToDecimal(int BasisOriginalSystem, int &number) {
    int result = 0;
    int NumberDigits = 0;
    while(number>0) {
    result += number%10 * exp(BasisOriginalSystem, NumberDigits);
    NumberDigits++;
    number /=10;
    }
    number = result;
}

void ConversionFromDecimalToFinal(int BasisFinalSystem, int &number) {
    int result = 0;
    int NumberDigits = 0;
    while(exp(BasisFinalSystem,NumberDigits+1) <= number) {
        NumberDigits++;
    }
    while(NumberDigits>=0) {
            result*=10;
            result += number / exp(BasisFinalSystem, NumberDigits);
            number = number % exp(BasisFinalSystem, NumberDigits);
            NumberDigits--;
    }
        number = result;
}


int ConversionOfNumberSystems(int number, int BasisOriginalSystem, int BasisFinalSystem) {

    if(BasisOriginalSystem !=BasisFinalSystem) {
    ConversionFromSourceToDecimal(BasisOriginalSystem, number);
    ConversionFromDecimalToFinal(BasisFinalSystem, number);
    }
    return number;

}
int main () {
    int num, bS, fS;
    cout<<"Input:"<<endl<<"number: ";
    cin>>num;
    cout<<"the base of the basic number system: ";
    cin>>bS;
    cout<<"the base of the final number system: ";
    cin>>fS;
    cout<<"Result: ";
    cout<<ConversionOfNumberSystems(num, bS, fS)<<endl;

    return 0;
}
