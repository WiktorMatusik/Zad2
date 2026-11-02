#include <iostream>
#include "BST.h"

using namespace std;

void printMenu() {
    cout << "\n==== MENU DRZEWA BST ====\n";
    cout << "1. Dodaj element\n";
    cout << "2. Usun cale drzewo\n";
    cout << "3. Wyswietl drzewo (1-Preorder, 2-Inorder, 3-Postorder, 4-Graficznie)\n";
    cout << "0. Wyjscie\n";
    cout << "Wybierz opcje: ";
}

int main() {
    BST tree;
    int choice = -1;

    while (choice != 0) {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int val;
            cout << "Podaj wartosc do dodania: ";
            cin >> val;
            tree.add(val);
            break;
        }
        case 2:
            tree.clear();
            cout << "Drzewo zostalo usuniete.\n";
            break;
        case 3: {
            int method;
            cout << "Metoda (1: Preorder, 2: Inorder, 3: Postorder, 4: Graficznie): ";
            cin >> method;
            tree.display(method);
            break;
        }
        case 0:
            cout << "Zamykanie programu.\n";
            break;
        default:
            cout << "Nieprawidlowa opcja. Sprobuj ponownie.\n";
        }
    }

    return 0;
}
