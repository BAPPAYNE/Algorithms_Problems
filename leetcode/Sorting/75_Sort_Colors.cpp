#include<iostream>
#include<vector>
#include<chrono>

using namespace std;

int partition(vector<int> &arr,int low,int high){
int x = arr[high];
int i = low - 1 ;
for(int j = low ; j < high ; j++){
    if(arr[j] <= x){
        i++;
        swap(arr[i],arr[j]);
    }
}
swap(arr[i+1], arr[high]);
return i + 1 ;
}

void quick_Sort(vector<int> &arr,int low,int high){
    if(low < high){
        int p = partition(arr,low,high);
        quick_Sort(arr,low,p-1);
        quick_Sort(arr,p+1,high);
    }
}
void sortColors(vector<int>& nums) {
    quick_Sort(nums,0,nums.size()-1);
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,0,2,1,1,0};
    
    auto T1 = chrono::high_resolution_clock::now();
    sortColors(nums) ;
    auto diff_ = chrono::high_resolution_clock::now() - T1;
    for(auto i : nums)  cout << i << " " ;
    cout << "\n" << chrono::duration_cast<chrono::duration<double,milli>>(diff_).count() << " milliseconds" << endl ;
    return 0;
}
