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
    int height;

    node(T val = T());

    void update_height();

    int get_balance_factor();
};

template<typename T>
class BST {
private:
    node<T> *root = nullptr;
    int _size_ = 0;

    void _insert_(node<T> *&, T);

    bool _find_(node<T> *&, T);

    void _erase_(node<T> *&, T);

    void _clear(node<T> *&);

    void _traverse_inorder_(node<T> *);

    void rotate_left(node<T> *&);

    void rotate_right(node<T> *&);

    void balance(node<T> *&, T);


public:

    BST();

    void insert(T);

    bool find(T);

    void erase(T);

    int size();

    void clear();

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


