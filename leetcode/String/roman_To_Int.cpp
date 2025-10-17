#include <iostream>
#include <string>
#include <map>

using namespace std ;

int numberMap(char &romanNum) {
    switch (romanNum)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M' :
        return 1000;        
    
    default:
        break;
    }
    return 0;
}

int romanToInteger(string s) {
    map<char, int> rep = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}} ;
    int size = s.size() ;
    int ans = 0 ;
    for ( int i = 0 ; i < size - 1 ; i++) {
        if (numberMap(s[i]) < numberMap(s[i+1])) {
            ans -= numberMap(s[i]) ;
        } else {
            ans += numberMap(s[i]) ;
        }
    }
    ans += numberMap(s[size-1]) ;

    return ans ;
}

int main(int argc, char const *argv[])
{
    cout << romanToInteger("MCMXCIV") << endl ;
    return 0;
}

