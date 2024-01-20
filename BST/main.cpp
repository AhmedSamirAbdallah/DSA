#include <iostream>
#include "BST.h"

using namespace std;


int main() {
    BST<string> test;
    test.insert("bbb");
    test.insert("aaa");
    test.insert("ccc");
    test.traverse_inorder();
    return 0;
}
