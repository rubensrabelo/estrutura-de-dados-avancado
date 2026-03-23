#include <iostream>
#include <string>
#include <sstream>

#include "BST.hpp"

using namespace std;

int main()
{
    int key;
    string line;
    BST tree;

    line = "0 1 2 4 5 7 8 9 10 11 12 13 23 45 67 21 89 43 99 100 123 155 200";

    stringstream ss(line);

    while (ss >> key) {
        tree.insert(key);
    }

    tree.show();

    cout << tree.height() << " " << tree.size() << endl;

    return 0;
}