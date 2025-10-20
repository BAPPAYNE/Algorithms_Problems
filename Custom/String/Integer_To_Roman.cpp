#include <iostream>
#include <string>

using namespace std;
string integerToRoman(int number) {
    const char *ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    const char *tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    const char *hundreds[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    const char *thousands[] = {"","M","MM","MMM"};

    string result = string(thousands[number/1000]) + hundreds[(number%1000)/100] + tens[(number%100)/10] + ones[number%10];
    return result;
}


int main(int argc, char const *argv[])
{
    cout << integerToRoman(123) ;
    return 0;
}
