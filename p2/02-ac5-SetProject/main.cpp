#include <iostream>
#include <vector>

#include "lib/include/Set.h"

using namespace std;

void menu()
{
    cout << "\n========== MENU ==========\n";

    cout << "1 - Criar conjunto\n";
    cout << "2 - Inserir elemento\n";
    cout << "3 - Remover elemento\n";
    cout << "4 - Mostrar conjunto\n";
    cout << "5 - Contains\n";
    cout << "6 - Minimum\n";
    cout << "7 - Maximum\n";
    cout << "8 - Successor\n";
    cout << "9 - Predecessor\n";
    cout << "10 - Union\n";
    cout << "11 - Intersection\n";
    cout << "12 - Difference\n";
    cout << "13 - Size\n";
    cout << "14 - Empty\n";
    cout << "15 - Clear\n";
    cout << "0 - Sair\n";

    cout << "\nOpcao: ";
}

int main()
{
    vector<Set *> sets;

    int option;

    do
    {
        menu();

        cin >> option;

        if (option == 1)
        {
            sets.push_back(new Set());

            cout << "\nConjunto criado com ID "
                 << sets.size() - 1 << endl;
        }

        else if (option == 2)
        {
            int id;

            cout << "ID do conjunto: ";
            cin >> id;

            cout << "Digite os valores (q para parar): ";

            string input;

            while (cin >> input && input != "q")
            {
                int value = stoi(input);

                sets[id]->Insert(value);
            }
        }

        else if (option == 3)
        {
            int id, value;

            cout << "ID do conjunto: ";
            cin >> id;

            cout << "Valor: ";
            cin >> value;

            sets[id]->Erase(value);
        }

        else if (option == 4)
        {
            int id;

            cout << "ID do conjunto: ";
            cin >> id;

            sets[id]->Show();
        }

        else if (option == 5)
        {
            int id, value;

            cout << "ID do conjunto: ";
            cin >> id;

            cout << "Valor: ";
            cin >> value;

            cout << (sets[id]->Contains(value)
                         ? "true"
                         : "false")
                 << endl;
        }

        else if (option == 6)
        {
            int id;

            cout << "ID do conjunto: ";
            cin >> id;

            cout << sets[id]->Minimum() << endl;
        }

        else if (option == 7)
        {
            int id;

            cout << "ID do conjunto: ";
            cin >> id;

            cout << sets[id]->Maximum() << endl;
        }

        else if (option == 8)
        {
            int id, value;

            cout << "ID do conjunto: ";
            cin >> id;

            cout << "Valor: ";
            cin >> value;

            cout << sets[id]->Successor(value) << endl;
        }

        else if (option == 9)
        {
            int id, value;

            cout << "ID do conjunto: ";
            cin >> id;

            cout << "Valor: ";
            cin >> value;

            cout << sets[id]->Predecessor(value) << endl;
        }

        else if (option == 10)
        {
            int a, b;

            cout << "Conjunto A: ";
            cin >> a;

            cout << "Conjunto B: ";
            cin >> b;

            Set result = sets[a]->Union(*sets[b]);

            result.Show();
        }

        else if (option == 11)
        {
            int a, b;

            cout << "Conjunto A: ";
            cin >> a;

            cout << "Conjunto B: ";
            cin >> b;

            Set result = sets[a]->Intersection(*sets[b]);

            result.Show();
        }

        else if (option == 12)
        {
            int a, b;

            cout << "Conjunto A: ";
            cin >> a;

            cout << "Conjunto B: ";
            cin >> b;

            Set result = sets[a]->Difference(*sets[b]);

            result.Show();
        }

        else if (option == 13)
        {
            int id;

            cout << "ID do conjunto: ";
            cin >> id;

            cout << sets[id]->Size() << endl;
        }

        else if (option == 14)
        {
            int id;

            cout << "ID do conjunto: ";
            cin >> id;

            cout << sets[id]->Empty() << endl;
        }

        else if (option == 15)
        {
            int id;

            cout << "ID do conjunto: ";
            cin >> id;

            sets[id]->Clear();
        }

    } while (option != 0);

    for (Set *s : sets)
        delete s;

    return 0;
}