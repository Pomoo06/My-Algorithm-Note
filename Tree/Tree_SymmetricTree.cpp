//判断二叉树是否对称

#include"leetcode.h"

using namespace std;

bool check(TreeNode* l, TreeNode* r){
    if(!l && !r) return true;
    if(!l || !r) return false;

    return (l->val == r->val) && check(l->left, r->right) && check(l->right, r->left);
}

bool isSymmetric(TreeNode* root){
    if(!root) return true;
    return check(root->left, root->right);
}

int main(){

    TreeNode* root = makeTree({1, 2, 2, 3, 4, 4, 3});
    cout << isSymmetric(root) << endl;

    return 0;
}