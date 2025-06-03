#include<iostream>
#include<string>

using namespace std;

int main(){
    int num = 8369;
    string s = to_string(num) ;
    int n = s.size();
    int i = 0 ;
    int k = 500 ;
    
    // Selection Sort (but k times);
    while(k > 0){
        int max = INT_MIN ;
        int idx = -1;
        for(int j = i ; j < n ; j++){
            if(s[j] > max){
                max = s[j];
                idx = j ;
            }
        }
        if(idx != -1){
            swap(s[i],s[idx]);
        }
        k--;
        i++;
    }
    cout << s ;
}