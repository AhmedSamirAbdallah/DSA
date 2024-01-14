//
// Created by ahmed on 14/01/24.
//
#include "BST.h"


node::node() : left(nullptr), right(nullptr), val(0), subtree_size(1) {}

node::node(int val) : left(nullptr), right(nullptr), val(val), subtree_size(1) {}


void BST::insert_val(node *&cur, int val) {
    if (cur == nullptr) {
        cur = new node(val);
        _size_++;
        return;
    }
    if (cur->val < val) {
        insert_val(cur->right, val);
    } else if (cur->val > val) {
        insert_val(cur->left, val);
    }
}

bool BST::find_val(node *&cur, int val) {
    if (cur == nullptr) {
        return false;
    }
    if (cur->val < val) {
        return find_val(cur->right, val);
    } else if (cur->val > val) {
        return find_val(cur->left, val);
    } else {
        return true;
    }
}

void BST::erase_val(node *&cur, int val) {
    if (cur == nullptr) {
        return;
    }
    if (cur->val < val) {
        erase_val(cur->right, val);
    } else if (cur->val > val) {
        erase_val(cur->left, val);
    } else {
        if (cur->right && cur->left) {
            node *min_right_subtree = cur->right;
            node *parent = cur;
            while (min_right_subtree->left) {
                parent = min_right_subtree;
                min_right_subtree = min_right_subtree->left;
            }
            parent->left = (min_right_subtree->right) ? min_right_subtree->right : nullptr;
            node *temp = min_right_subtree;
            temp->left = cur->left;
            if (cur->right != min_right_subtree)temp->right = cur->right;
            delete cur;
            cur = temp;
        } else {
            node *child = (cur->right) ? cur->right : cur->left;
            delete cur;
            cur = child;
        }
        _size_--;
    }
}

void BST::insert(int val) {
    insert_val(root, val);
}

bool BST::find(int val) {
    return find_val(root, val);
}

void BST::erase(int val) {
    erase_val(root, val);
}

int BST::size() {
    return _size_;
}
