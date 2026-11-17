//将有序数组转为二叉搜索树
#include"leetcode.h"

using namespace std;

TreeNode* son(vector<int>& nums, int l, int r){
    if(l > r) return 0;
    int mid = (l + r) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = son(nums, l, mid - 1);
    root->right = son(nums, mid + 1, r);
    return root;
}

TreeNode* build(vector<int>& nums){
    return son(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = build(nums);
    printTree(root);

    return 0;
}