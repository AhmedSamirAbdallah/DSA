//
// Created by ahmed on 14/01/24.
//
#include<iostream>
#include "BST.h"

using namespace std;

template<typename T>
node<T>::node(T val) : left(nullptr), right(nullptr), val(val), height(0) {}

template<typename T>
void node<T>::update_height() {
    height = max((left ? left->height : 0), (right ? right->height : 0)) + 1;
}

template<typename T>
BST<T>::BST() : root(nullptr), _size_(0) {}


template<typename T>
void BST<T>::rotate_left(node<T> *&cur) {
    node<T> *y = cur;
    node<T> *x = cur->right;
    y->right = x->left;
    x->left = y;
    y->update_height();
    x->update_height();
    cur = x;
}

template<typename T>
void BST<T>::rotate_right(node<T> *&cur) {
    node<T> *x = cur;
    node<T> *y = cur->left;
    x->left = y->right;
    y->right = x;
    x->update_height();
    y->update_height();
    cur = y;
}


template<typename T>
void BST<T>::_insert_(node<T> *&cur, T val) {
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
    cur->update_height();
}

template<typename T>
bool BST<T>::_find_(node<T> *&cur, T val) {
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

template<typename T>
void BST<T>::_erase_(node<T> *&cur, T val) {
    if (cur == nullptr) {
        return;
    }
    if (cur->val < val) {
        _erase_(cur->right, val);
    } else if (cur->val > val) {
        _erase_(cur->left, val);
    } else {
        if (cur->right && cur->left) {
            node<T> *parent = cur;
            node<T> *min_right_subtree = cur->right;
            while (min_right_subtree->left) {
                parent = min_right_subtree;
                min_right_subtree = min_right_subtree->left;
            }
            node<T> *child = min_right_subtree->right;
            cur->val = min_right_subtree->val;
            delete min_right_subtree;
            (parent == cur) ? parent->right = child : parent->left = child;
            /*
                min_right_subtree = child  ----> not working because min_right_subtree is a copy not the reference one
             */
        } else {
            node<T> *child = (cur->right) ? cur->right : cur->left;
            delete cur;
            cur = child;
        }
        _size_--;
        cur->update_height();
    }
}

template<typename T>
void BST<T>::_traverse_inorder_(node<T> *cur) {
    if (cur == nullptr)return;
    std::cout << cur->val << "    " << cur->height << "\n";
    _traverse_inorder_(cur->left);
    _traverse_inorder_(cur->right);
}

template<typename T>
void BST<T>::insert(T val) {
    _insert_(root, val);
}

template<typename T>
bool BST<T>::find(T val) {
    return _find_(root, val);
}

template<typename T>
void BST<T>::erase(T val) {
    _erase_(root, val);
}

template<typename T>
int BST<T>::size() {
    return _size_;
}

template<typename T>
void BST<T>::traverse_inorder() {
    _traverse_inorder_(root);
}