#include <iostream>
#include "BST.h"

int main() {
    BST tree;

    int values[] = {50, 30, 70, 20, 40, 60, 80, 100, 90};

    std::cout << "=== INSERCAO ===\n";

    for (int v : values) {
        std::cout << "\nInserindo: " << v << "\n";
        tree.insert(v);
        tree.show();
        std::cout << "----------------------\n";
    }

    std::cout << "\n=== BUSCA ===\n";
    std::cout << "Buscar 40: " << (tree.search(40) ? "Encontrado" : "Nao encontrado") << "\n";
    std::cout << "Buscar 100: " << (tree.search(100) ? "Encontrado" : "Nao encontrado") << "\n";

    int removals[] = {20, 30, 50};

    std::cout << "\n=== REMOCAO ===\n";

    for (int r : removals) {
        std::cout << "\nRemovendo: " << r << "\n";
        tree.remove(r);
        tree.show();
        std::cout << "----------------------\n";
    }

    return 0;
}