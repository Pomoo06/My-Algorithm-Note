//二叉树的最大深度

#include<iostream>
#include"leetcode.h"

using namespace std;

int maxdepth(TreeNode* root){
    if(!root) return 0;

    int l = maxdepth(root->left);
    int r = maxdepth(root->right);

    return max(l, r) + 1;
}

int main(){
    
    TreeNode* root = makeTree({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
    maxdepth(root);
    cout << maxdepth(root) << endl;
    return 0;
}

