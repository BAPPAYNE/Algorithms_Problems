#include<iostream>

using namespace std;

long long  maxArea(int *height, int size) {
    long long start = 0, end = size - 1;
    long long area = 0 ;
    long long max_Area = 0; 
    while(start < end){
        if (height[start] > height[end]){
            area = height[end]*(end - start);
            if(area > max_Area){
                max_Area = area ;
            }
            end--;
        }else{
            area = height[start]*(end - start) ;
            if(area > max_Area){
                max_Area = area ;
            }
            start++;

        }
    }
    return max_Area ;
}

int main(){
    int height[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(height) / sizeof(height[0]);
    cout << "Maximum area: " << maxArea(height, size) << endl;
}