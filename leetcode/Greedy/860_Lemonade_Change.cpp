#include<iostream>
#include<vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int size = bills.size();
    int i = 0 ;
    int mon5 = 0,mon10 = 0;
    while(i < size) {
        if(bills[i] == 5){
            mon5++;
        }else if (bills[i] == 10){
            if(mon5){
                mon10++;
                mon5--;
            }else {
                return false ;
            }
        }else{
            if(mon5){
                if(mon10){
                    mon10--;
                    mon5--;
                }else if(mon5 >= 3){
                        mon5-=3;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        i++;
    }
    return true;
}

int main(){
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << lemonadeChange(bills);
}