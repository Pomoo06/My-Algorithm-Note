//基数排序
/*
在一个数组中，每个元素都是一个整数，数组的长度为N，将数组排序，要求时间复杂度为O(N)，空间复杂度为O(N)。
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void RadixSort(vector<int>& nums){
    int max_val = INT_MIN;
    for(int x : nums){
        max_val = max(max_val, x);
    }

    vector<queue<int>> bucket(max_val + 1);

    for(int i : nums){
        bucket[i].push(i);
    }
    vector<int> res;
    for(auto &q : bucket){
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
    }

    nums = res;

}

int main(){

    vector<int> nums = {1, 2, 3, 3, 2, 1};
    RadixSort(nums);
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}