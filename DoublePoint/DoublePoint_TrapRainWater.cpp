//接雨水
/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
*/

#include<iostream>
#include<vector>

using namespace std;

int trap(vector<int>& height){
    int n = height.size();
    int leftMax = 0;
    int rightMax = 0;
    int res = 0;
    int l = 0;
    int r = n-1;

    while(l < r){
        if(height[l] < height[r]){
            leftMax = max(leftMax, height[l]);
            res += leftMax - height[l];
            l++;
        }
        else{
            rightMax = max(rightMax, height[r]);
            res += rightMax - height[r];
            r--;
        }
    }
    return res;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
    return 0;
}