#include<iostream>
#include<algorithm>

using namespace std;

int finding_Total_Barber(int arr[],int brr[],int n){
    int i = 0, j = 0;
    int barber = 0; 
    int ans = -999 ;
    sort(arr,arr+n);
    sort(brr,brr+n);
    while(i < n){
        if(arr[i] < brr[j]){
            barber++;
            i++;
            ans = ans  < barber ? barber : ans ;
        }else{
            barber--;
            j++;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n ;
    int arr[n];
    int brr[n];

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> brr[i];
    }
    return 0;
}
