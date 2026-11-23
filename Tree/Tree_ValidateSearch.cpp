//验证搜索二叉树
//判断一个二叉树是不是搜索二叉树

#include"leetcode.h"

using namespace std;

bool check(TreeNode *root, long long low, long long high){
    if(!root) return true;

    if(root->val <= low || root->val >= high)
        return false;

    return check(root->left, low, root->val) && check(root->right, root->val, high);
}

int main(){

    TreeNode* root = makeTree({2, 1, 3});
    cout << check(root, LONG_MIN, LONG_MAX) << endl;

    return 0;
}