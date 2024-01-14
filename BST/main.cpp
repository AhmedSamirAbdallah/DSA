#include <iostream>
#include "BST.h"

using namespace std;


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
