//
// Created by ahmed on 14/01/24.
//
#include<iostream>
#include "BST.h"

node::node() : left(nullptr), right(nullptr), val(0) {}

node::node(int val) : left(nullptr), right(nullptr), val(val) {}


void BST::_insert_(node *&cur, int val) {
    if (cur == nullptr) {
        cur = new node(val);
        _size_++;
        return;
    }
    if (cur->val < val) {
        _insert_(cur->right, val);
    } else if (cur->val > val) {
        _insert_(cur->left, val);
    }
}

bool BST::_find_(node *&cur, int val) {
    if (cur == nullptr) {
        return false;
    }
    if (cur->val < val) {
        return _find_(cur->right, val);
    } else if (cur->val > val) {
        return _find_(cur->left, val);
    } else {
        return true;
    }
}

void BST::_erase_(node *&cur, int val) {
    if (cur == nullptr) {
        return;
    }
    if (cur->val < val) {
        _erase_(cur->right, val);
    } else if (cur->val > val) {
        _erase_(cur->left, val);
    } else {
        if (cur->right && cur->left) {
            node *parent = cur;
            node *min_right_subtree = cur->right;
            while (min_right_subtree->left) {
                parent = min_right_subtree;
                min_right_subtree = min_right_subtree->left;
            }
            node *child = min_right_subtree->right;
            cur->val = min_right_subtree->val;
            delete min_right_subtree;
            (parent == cur) ? parent->right = child : parent->left = child;
            /*
                min_right_subtree = child  ----> not working because min_right_subtree is a copy not the reference one
             */
        } else {
            node *child = (cur->right) ? cur->right : cur->left;
            delete cur;
            cur = child;
        }
        _size_--;
    }
}

void BST::_traverse_inorder_(node *cur) {
    if (cur == nullptr)return;
    printf("%d\n", cur->val);
    _traverse_inorder_(cur->right);
    _traverse_inorder_(cur->left);

}

void BST::insert(int val) {
    _insert_(root, val);
}

bool BST::find(int val) {
    return _find_(root, val);
}

void BST::erase(int val) {
    _erase_(root, val);
}

int BST::size() {
    return _size_;
}

void BST::traverse_inorder() {
    _traverse_inorder_(root);
}
