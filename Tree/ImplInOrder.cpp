#include"Tree.h"
#include<iostream>

using namespace std;

void inorder(Tree* root){
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);   
}

int main(){


    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    inorder(root);
    return 0;
}