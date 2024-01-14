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

    void insert_val(node *&cur, int val);


    bool find_val(node *&cur, int val);

    void erase_val(node *&cur, int val);

public:
    void insert(int val);

    bool find(int val);

    void erase(int val);

    int size();
};
