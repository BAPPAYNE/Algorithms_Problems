#include<iostream>
using namespace std;
#include<vector>
#include<chrono>

vector<int> mergeSortedArray(vector<int> nums1,int m,vector<int> nums2, const int n){
    // int i = nums1.size()-nums2.size()-1;
    // int j = nums2.size()-1;
    // int k = nums1.size()-nums2.size() + nums2.size()-1;
    auto T1 = chrono::high_resolution_clock::now();
    int i=m-1, j=n-1, k=m+n-1;

    //if m = 0 then technically nums1 is empty and it has space for nums2 only.
    if(m == 0) return nums2;
    while(i>=0 && j>=0){
        if(nums1[i]>=nums2[j]){
            nums1[k--] = nums1[i--];
        }else{
            nums1[k--] = nums2[j--];
        }
    }
    while(j>=0){
        nums1[k--]=nums2[j--];
    }
    
    
    return nums1;
}

int main(int argc, char const *argv[])
{
    auto _start = chrono::high_resolution_clock::now();
    vector<int> nums1 = {0,0,3,0,0,0,0,0,0};
    vector<int> nums2 = {-1,1,1,1,2,3};

    
    vector<int>mergedArray = mergeSortedArray(nums1,nums1.size()-nums2.size(),nums2,nums2.size());

    auto _difference = chrono::high_resolution_clock::now() - _start;
    
    cout<< chrono::duration_cast<chrono::duration<double,milli>>(_difference).count() << " ms" <<endl;

    
    // for (int i = 0; i < mergedArray.size();i++){
    //     cout<<mergedArray[i]<<" ";
    // }
    return 0;
}
