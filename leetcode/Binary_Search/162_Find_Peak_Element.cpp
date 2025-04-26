#include<iostream>
#include<vector>

// Namespaces
using namespace std;

int peakElement(vector<int>& nums){

    int start = 0, end = nums.size()-1,mid;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] < nums[mid + 1])
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << peakElement(nums) << endl;
    return 0;
}
