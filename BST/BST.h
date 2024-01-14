//
// Created by ahmed on 14/01/24.
//

#ifndef BST_BST_H
#define BST_BST_H

#endif //BST_BST_H

struct node {
    node *left, *right;
    int val;
    int subtree_size;

    node();

    node(int val);
};


class BST {
private:
    node *root = nullptr;
    int _size_ = 0;

    bool _insert_(node *&cur, int val);


    bool _find_(node *&cur, int val);

    bool _erase_(node *&cur, int val);

    void _traverse_inorder_(node *cur);

public:
    void insert(int val);

    bool find(int val);

    void erase(int val);

    int size();

    void traverse_inorder();
};
