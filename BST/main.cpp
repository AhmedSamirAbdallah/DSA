#include <iostream>
#include "BST.h"

using namespace std;


int main() {
    BST<int> test;
    test.insert(10);
    test.insert(8);
    test.insert(15);
    test.insert(6);
    test.insert(9);
    test.insert(12);
    test.insert(16);


    test.traverse_inorder();
    return 0;
}
