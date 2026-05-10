#include <iostream>
#include "../lib/include/Set.h"

using namespace std;

void separator()
{
    cout << "\n----------------------------------\n";
}

void testInsertAndSize()
{
    separator();

    cout << "[TESTE] Insert + Size\n";

    Set s;

    s.Insert(10);
    s.Insert(5);
    s.Insert(20);
    s.Insert(10);

    s.Show();

    cout << "\nEsperado: 3";
    cout << "\nObtido: " << s.Size() << endl;
}

void testContains()
{
    separator();

    cout << "[TESTE] Contains\n";

    Set s;

    s.Insert(10);
    s.Insert(5);

    s.Show();

    cout << "\nContains(10) esperado: 1";
    cout << "\nObtido: " << s.Contains(10) << endl;

    cout << "\nContains(20) esperado: 0";
    cout << "\nObtido: " << s.Contains(20) << endl;
}

void testMinMax()
{
    separator();

    cout << "[TESTE] Minimum / Maximum\n";

    Set s;

    s.Insert(10);
    s.Insert(5);
    s.Insert(20);
    s.Insert(15);

    s.Show();

    cout << "\nMinimum esperado: 5";
    cout << "\nObtido: " << s.Minimum() << endl;

    cout << "\nMaximum esperado: 20";
    cout << "\nObtido: " << s.Maximum() << endl;
}

void testSuccessorPredecessor()
{
    separator();

    cout << "[TESTE] Successor / Predecessor\n";

    Set s;

    s.Insert(10);
    s.Insert(5);
    s.Insert(20);
    s.Insert(15);

    s.Show();

    cout << "\nSuccessor(10) esperado: 15";
    cout << "\nObtido: " << s.Successor(10) << endl;

    cout << "\nPredecessor(15) esperado: 10";
    cout << "\nObtido: " << s.Predecessor(15) << endl;
}

void testErase()
{
    separator();

    cout << "[TESTE] Erase\n";

    Set s;

    s.Insert(10);
    s.Insert(5);
    s.Insert(20);
    s.Insert(15);

    cout << "\nAntes:\n";
    s.Show();

    s.Erase(20);

    cout << "\nDepois:\n";
    s.Show();

    cout << "\nContains(20) esperado: 0";
    cout << "\nObtido: " << s.Contains(20) << endl;

    cout << "\nSize esperado: 3";
    cout << "\nObtido: " << s.Size() << endl;
}

void testUnion()
{
    separator();

    cout << "[TESTE] Union\n";

    Set A;
    Set B;

    A.Insert(1);
    A.Insert(2);
    A.Insert(3);

    B.Insert(3);
    B.Insert(4);
    B.Insert(5);

    cout << "\nConjunto A:\n";
    A.Show();

    cout << "\nConjunto B:\n";
    B.Show();

    Set C = A.Union(B);

    cout << "\nUniao:\n";
    C.Show();
}

void testIntersection()
{
    separator();

    cout << "[TESTE] Intersection\n";

    Set A;
    Set B;

    A.Insert(1);
    A.Insert(2);
    A.Insert(3);

    B.Insert(2);
    B.Insert(3);
    B.Insert(4);

    cout << "\nConjunto A:\n";
    A.Show();

    cout << "\nConjunto B:\n";
    B.Show();

    Set C = A.Intersection(B);

    cout << "\nIntersecao:\n";
    C.Show();
}

void testDifference()
{
    separator();

    cout << "[TESTE] Difference\n";

    Set A;
    Set B;

    A.Insert(1);
    A.Insert(2);
    A.Insert(3);
    A.Insert(4);

    B.Insert(2);
    B.Insert(4);

    cout << "\nConjunto A:\n";
    A.Show();

    cout << "\nConjunto B:\n";
    B.Show();

    Set C = A.Difference(B);

    cout << "\nDiferenca A - B:\n";
    C.Show();
}

void testEmpty()
{
    separator();

    cout << "[TESTE] Empty\n";

    Set s;

    cout << "\nEsperado: 1";
    cout << "\nObtido: " << s.Empty() << endl;

    s.Insert(1);

    cout << "\nEsperado: 0";
    cout << "\nObtido: " << s.Empty() << endl;
}

void testClear()
{
    separator();

    cout << "[TESTE] Clear\n";

    Set s;

    s.Insert(1);
    s.Insert(2);
    s.Insert(3);

    cout << "\nAntes:\n";
    s.Show();

    s.Clear();

    cout << "\nDepois:\n";
    s.Show();

    cout << "\nSize esperado: 0";
    cout << "\nObtido: " << s.Size() << endl;

    cout << "\nEmpty esperado: 1";
    cout << "\nObtido: " << s.Empty() << endl;
}

int main()
{
    cout << "========== TESTES ==========\n";

    testInsertAndSize();

    testContains();

    testMinMax();

    testSuccessorPredecessor();

    testErase();

    testUnion();

    testIntersection();

    testDifference();

    testEmpty();

    testClear();

    cout << "\n========== FIM ==========\n";

    return 0;
}