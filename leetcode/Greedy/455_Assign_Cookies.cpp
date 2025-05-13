#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int sg = g.size(),ss = s.size(),i = 0,j=0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    while(i<sg && j < ss){
        if(s[j] >= g[i]){
            i++;j++;
        }else{
            j++;
        }
    }
    return i;
}

int main(){
    vector<int> g = {1, 2, 3}; // Greed factors of children
    vector<int> s = {1, 1};    // Sizes of cookies
    cout << findContentChildren(g,s) << endl;
}