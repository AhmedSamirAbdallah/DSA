#include <iostream>
#include "BST.h"

using namespace std;


int main() {
    BST test;
    test.insert(9);
    test.insert(20);
    test.insert(5);
    test.insert(1);

    test.erase(5);
    test.traverse_inorder();


    return 0;
}
