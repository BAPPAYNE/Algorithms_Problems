#include<iostream>
#include<vector>
using namespace std;

vector<int> merge_Sorted_Arr(vector<int> &arr1,vector<int> &arr2){
    int size = arr1.size() + arr2.size() - 1;
    vector<int> ans(size);
    int i = 0 ;
    while(i < size){
        if(arr1[i] < arr2[i]){
            ans[i] = arr1[i];
        }else{
            ans[i] = arr2[i];
        }
        i++;
    }
    return ans;
}















vector<int> merge_Sort(vector<int> &arr,int start,int end){
    if(arr.size() == 1){
        return arr ;
    }
    int mid = start + (end - start)/2 ;
    vector<int> arr1 = merge_Sort(arr,start,mid);
    vector<int> arr2 = merge_Sort(arr,mid+1,end);
    return merge_Sorted_Arr(arr1,arr2);
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 5, 7, 8, 1, -15, 0, 3, 2} ;
    // vector<int> ans = merge_Sort(arr,0,arr.size() - 1) ;

    for(auto i : arr)   printf("%d ",i);
    
    return 0;
}
