//
// Created by ahmed on 14/01/24.
//
#include<iostream>
#include "BST.h"

node::node() : left(nullptr), right(nullptr), val(0), subtree_size(1) {}

node::node(int val) : left(nullptr), right(nullptr), val(val), subtree_size(1) {}


bool BST::_insert_(node *&cur, int val) {
    if (cur == nullptr) {
        cur = new node(val);
        _size_++;
        return true;
    }
    if (cur->val < val) {
        bool can_insert = _insert_(cur->right, val);
        cur->subtree_size += can_insert;
        return can_insert;
    } else if (cur->val > val) {
        bool can_insert = _insert_(cur->left, val);
        cur->subtree_size += can_insert;
        return can_insert;
    } else {
        return false;
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

void BST::_traverse_inorder_(node *cur) {
    if (cur == nullptr)return;
    printf("node : %d | comp = %d\n", cur->val, cur->subtree_size);
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
