//二叉树的右视图

#include"leetcode.h"

using namespace std;

vector<int> right(TreeNode* root){
    if(!root) return {};

    queue<TreeNode*> q;
    vector<vector<int>> arr;
    vector<int> res;
    q.push(root);
    while(!q.empty()){

        int n = q.size();
        vector<int> tmp;

        for(int i = 0; i < n; i++){
            TreeNode *cur = q.front();
            q.pop();
            tmp.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }

        arr.push_back(tmp);
    }

    for(auto &x : arr){
        res.push_back(x.back());

    }
    return res;
}

int main(){



    return 0;
}