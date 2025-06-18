#include<iostream>
#include<string.h>

using namespace std;

int lengthOfLongestSubstring(char* s) {
        bool isRepeated[256] = {0} ;
        int length = 0 ;
        int size = strlen(s) ;
        int j = 0 ;
        if(size == 0) return 0 ;
        for(int i = 0 ; i < size ; i++){
            if(isRepeated[s[i]] == 0){
                isRepeated[s[i]] = 1 ;
            }else{
                while(s[j] != s[i]){
                    isRepeated[s[j]] = 0 ;
                    j++;
                }
                j++;
            }
            if((i-j+1) > length){
                length = (i-j+1) ;
            }
        }
        return length;
}

// Without inner loop

int lengthOfLongestSubstring2(char* s){
    int length = 0 ;
    short inxStored[256];
    memset(inxStored, -1, sizeof(inxStored)); 
    int size = strlen(s) ;
    int i = 0 ;
    if(size == 0) return 0 ;
    for (int j = 0 ; j < size ; j++){
        if(inxStored[s[j]] >= i){
            i = inxStored[s[j]] + 1 ;
        }
        // cout << "[DEBUG] i j : " << i << " " << j << endl ;
        inxStored[s[j]] = j ;
        if((j-i+1) > length){
            length = (j - i + 1) ;
        }
        // cout << "[DEBUG] length: "<< length << endl ;
    }
    return length ;
}



int main(){
    cout << lengthOfLongestSubstring("abcabc") << endl ;
    cout << lengthOfLongestSubstring2("abcabc") << endl ;
}