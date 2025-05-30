#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int size = nums.size();
    if(size <=1) return 0;
    int start = 0, end = size - 1;
    int count = 0;
    while(start < end){
        int sum = nums[start] + nums[end] ;
        if(sum == k){
            count++;
            start++;end--;
        }else if(sum < k){
            start++;
        }else{
            end--;
        }
    }
    return count ;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4};
    int k = 2 ;
    auto T1 = chrono::high_resolution_clock::now();
    cout << maxOperations(nums,k) << endl;
    auto diff_ = chrono::high_resolution_clock::now() - T1 ;
    cout << chrono::duration_cast<chrono::duration<double,milli>>(diff_).count() << " milliseconds" << endl;
    return 0;
}

