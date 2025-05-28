#include<iostream>
#include<limits.h>
using namespace std;

int atoi(string s) {
    bool is_Negative = false;
    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    
    if(s[i] == '-'){
        is_Negative = true;
    }
    long long ans = 0;
    if(s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <='9')){
        if(s[i] == '+' || s[i] == '-'){
            i++;
        }
        while(i < s.size()){
            if((s[i] >= '0' && s[i] <='9') || s[i] == ' '){
                if(s[i] == ' '){
                    continue ;
                }else if(s[i] >= '0' && s[i] <='9'){
                    ans = ans*10 + (s[i] - '0');
                    if (!is_Negative && ans > INT_MAX) return INT_MAX;
                    if (is_Negative && -ans < INT_MIN) return INT_MIN;
                }
            }else{
                break;
            }
            i++;
        }
    }
    ans/=10;
    if(is_Negative){
        ans =  -ans;
    }
    if(ans > INT_MAX)   return INT_MAX;
    if(ans < INT_MIN)   return INT_MIN;
    return (int)ans;
}

int main(int argc, char const *argv[])
{
    printf("%d",atoi("-91283472332"));
    return 0;
}
