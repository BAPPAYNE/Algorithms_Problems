#include <iostream>
#include <vector>
#include <chrono>
// Namespaces
using namespace std;

// Linear Approach
double medianArray(vector<int> &nums, int size_nums) {
    // Calculate the mid index
    int mid = (size_nums - 1) / 2; // Use int for mid

    // If the size is even
    if (size_nums % 2 == 0) {
        return float((nums[mid] + nums[mid + 1]) / 2.0); // Average of the two middle elements
    } else {
        return float(nums[mid]); // Middle element for odd size
    }
}


double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{

    int size_nums1 = nums1.size(), size_nums2 = nums2.size();

    if (size_nums1 == 0 && size_nums2 != 0)
    {
        // nums2
        return medianArray(nums2, size_nums2);
    }
    else if (size_nums2 == 0 && size_nums1 !=0)
    {
        // nums1
        return medianArray(nums1,size_nums1);
    }else if(size_nums1 == 0 && size_nums2 == 0){
        return -1;
    }
    else
    {
        // Pointers
        int i = 0, j = 0, k = 0;
        vector<int> res(size_nums1 + size_nums2);
        while (i < size_nums1 && j < size_nums2)
        {
            if (nums2[j] > nums1[i])
            {
                res[k++] = nums1[i++];
            }
            else
            {
                res[k++] = nums2[j++];
            }
        }

        while (i < size_nums1)
        {
            res[k++] = nums1[i++];
        }
        while (j < size_nums2)
        {
            res[k++] = nums2[j++];
        }

        // for (int index = 0; index < k; index++)
        // {
        //     cout << res[index] << " ";
        // }
        // cout << "\n";
        return medianArray(res,size_nums1+size_nums2);
    }
    cout << "\n";
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    auto _start = chrono::high_resolution_clock::now();
    printf("%lf\n",findMedianSortedArrays(nums1,nums2));
    auto _difference = chrono::high_resolution_clock::now() - _start;

    cout<< chrono::duration_cast<chrono::duration<double,milli>>(_difference).count() << " ms" << endl ;
    return 0;
}
