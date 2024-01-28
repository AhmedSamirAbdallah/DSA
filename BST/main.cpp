#include <iostream>
#include "BST.h"

using namespace std;


int main() {
    BST<int> test;
    test.insert(10);
    test.insert(5);
    test.insert(15);
    test.insert(14);
    test.insert(19);
    test.insert(13);
    test.insert(20);
    test.traverse_inorder();
    return 0;
}
