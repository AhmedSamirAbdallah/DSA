//
// Created by ahmed on 14/01/24.
//

#ifndef BST_BST_H
#define BST_BST_H

#endif //BST_BST_H

template<typename T>
struct node {
    node *left, *right;
    T val;

    node(T val = T());
};

template<typename T>
class BST {
private:
    node<T> *root = nullptr;
    int _size_ = 0;

    void _insert_(node<T> *&cur, T val);

    bool _find_(node<T> *&cur, T val);


    void _erase_(node<T> *&cur, T val);

    void _traverse_inorder_(node<T> *cur);

public:

    BST();

    void insert(T val);

    bool find(T val);

    void erase(T val);

    int size();

    void traverse_inorder();
};

template
class BST<int>;

template
class BST<long>;

template
class BST<long long>;

template
class BST<double>;

template
class BST<float>;

template
class BST<char>;

template
class BST<std::string>;


