#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
        int size = height.size();
        int count = 0 ;
        int left = 0 ;
        int right = size - 1 ;
        int leftMax = height[left] ;
        int rightMax = height[right];


        while (left < right)
        {
            if(leftMax < rightMax){
                left++;
                leftMax = (height[left] > leftMax) ? height[left] : leftMax ;
                count += leftMax - height[left] ;
            }else{
                right--;
                rightMax = (height[right] > rightMax) ? height[right] : rightMax ;
                count += rightMax - height[right] ;
            }
        }
        
        
        return count;
    }

int main(){
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(arr) ;
}