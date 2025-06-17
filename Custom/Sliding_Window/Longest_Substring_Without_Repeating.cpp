#include<iostream>
#include<string.h>

using namespace std;


// int lengthOfLongestSubstring(string str){
//     bool isRepeated[255] = {0} ;
//     int length = 0 ;
//     int j = 0 ;
//     int tempLength = 0 ; 
//     if(str.size() == 0) return 0 ;
//     for(int i = 0 ; i < str.size() ; i++){
//         if(isRepeated[str[i]] == 0){
//             isRepeated[str[i]] = 1 ;
//             tempLength++;
//         }else{
//             while(str[j] != str[i]){
//                 isRepeated[str[j]] = 0 ;
//                 j++;
//                 tempLength--;
//             }
//             j++;
//         }
//         if((i-j+1) > length){
//             length = tempLength ;
//         }
//     }
//     return length;
// }

int lengthOfLongestSubstring(char* s) {
        bool isRepeated[255] = {0} ;
        int length = 0 ;
        int size = strlen(s) ;
        cout << size << " " ;
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

// Can be optimized by remembering each letter's latest index occurence so we dont have to use inner loop to iterate and go where s[j] == s[i] instead directly jump or assign.


int main(){
    cout << lengthOfLongestSubstring("au") ;
}