// 反转二叉树

#include "leetcode.h"

using namespace std;

TreeNode *invertTree(TreeNode *root) {
  if (!root)
    return 0;

  swap(root->left, root->right);
  invertTree(root->left);
  invertTree(root->right);

  return root;
}

int main() {

  TreeNode *root =
      makeTree({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
  invertTree(root);
  printTree(root);

  return 0;
}