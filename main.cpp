#include <iostream>
#include "BST.h"

using namespace std;

void printMenu() {
    cout << "\n==== MENU DRZEWA BST ====\n";
    cout << "1. Dodaj element\n";
    cout << "2. Usun element\n";
    cout << "3. Usun cale drzewo\n";
    cout << "4. Wyswietl drzewo (1-Preorder, 2-Inorder, 3-Postorder, 4-Graficznie)\n";
    cout << "5. Wyswietl sciezke do elementu\n";
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
        case 2: {
            int val;
            cout << "Podaj wartosc do usuniecia: ";
            cin >> val;
            if (tree.remove(val)) cout << "Usunieto element " << val << ".\n";
            else cout << "Element " << val << " nie istnieje w drzewie.\n";
            break;
        }
        case 3:
            tree.clear();
            cout << "Drzewo zostalo usuniete.\n";
            break;
        case 4: {
            int method;
            cout << "Metoda (1: Preorder, 2: Inorder, 3: Postorder, 4: Graficznie): ";
            cin >> method;
            tree.display(method);
            break;
        }
        case 5: {
            int target;
            cout << "Wprowadz element do znalezienia: ";
            cin >> target;

            vector<int> path;
            if (tree.findPath(target, path)) {
                cout << "Element znaleziony! Sciezka: ";
                for (size_t i = 0; i < path.size(); ++i) {
                    cout << path[i] << (i + 1 < path.size() ? " -> " : "");
                }
                cout << "\n";
            }
            else {
                cout << "Element " << target << " nie istnieje w drzewie.\n";
            }
            break;
        } 
        case 0:
            cout << "Zamykanie programu.\n";
            break;
        default:
            cout << "Nieprawidlowa opcja. Sprobuj ponownie.\n"; //s
        }
    }

    return 0;
}
