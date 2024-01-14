#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node {
    node *left, *right;
    int val;

    node() : left(nullptr), right(nullptr), val(0) {}

    node(int val) : left(nullptr), right(nullptr), val(val) {}


};

class BST {
private:
    node *root = nullptr;
    int _size_ = 0;

    void insert_val(node *&cur, int val) {
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

    bool find_val(node *&cur, int val) {
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

    void erase_val(node *&cur, int val) {
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

public:
    void insert(int val) {
        insert_val(root, val);
    }

    bool find(int val) {
        return find_val(root, val);
    }

    void erase(int val) {
        erase_val(root, val);
    }

    int size() {
        return _size_;
    }
};

int main() {
    BST test;
    test.insert(12);
    test.insert(13);
    test.insert(4);
    test.insert(7);
    test.insert(0);
    test.insert(2);
    test.insert(10);
    test.insert(8);
    test.insert(9);
    test.insert(11);
    test.insert(6);
    test.insert(1);
    test.insert(-1);
    test.erase(4);
    printf("%d\n", test.size());

    return 0;
}
