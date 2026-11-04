#ifndef TREE_H
#define TREE_H

class Tree {
public:
    int val = 0;
    Tree* left = nullptr;
    Tree* right = nullptr;

    Tree() = default;
    Tree(int val) : val(val) {}
    Tree(int val, Tree* left, Tree* right) : val(val), left(left), right(right) {}
    ~Tree() = default;
};

#endif
