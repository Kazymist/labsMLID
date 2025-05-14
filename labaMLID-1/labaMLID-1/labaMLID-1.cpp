#include <iostream>
#include <set>
#include <string>
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int numbers;
    string elements;

    set<string> ArrayA, ArrayB;
    set<string> obiedenenie, peresecehie, raznostAB, raznostBA, simetriaRaznosti;

    cout << "Введите размер множества A: ";
    cin >> numbers;

    cout << "Введите элементы A: ";
    for (int i = 0; i < numbers; i++) {
        cin >> elements;
        ArrayA.insert(elements);
    }

    cout << "Введите размер множества B: ";
    cin >> numbers;

    cout << "Введите элементы B: ";
    for (int i = 0; i < numbers; i++) {
        cin >> elements;
        ArrayB.insert(elements);
    }

    for (auto x : ArrayA) obiedenenie.insert(x);
    for (auto x : ArrayB) obiedenenie.insert(x);

    for (auto x : ArrayA)
        if (ArrayB.count(x)) peresecehie.insert(x);

    for (auto x : ArrayA)
        if (!ArrayB.count(x)) raznostAB.insert(x);

    for (auto x : ArrayB)
        if (!ArrayA.count(x)) raznostBA.insert(x);

    for (auto x : raznostAB) simetriaRaznosti.insert(x);
    for (auto x : raznostBA) simetriaRaznosti.insert(x);

    cout << "\nОбъединение: ";
    for (auto x : obiedenenie) cout << x << " ";

    cout << "\nПересечение: ";
    for (auto x : peresecehie) cout << x << " ";

    cout << "\nArrayA \\ ArrayB: ";
    for (auto x : raznostAB) cout << x << " ";

    cout << "\nArrayB \\ ArrayA: ";
    for (auto x : raznostBA) cout << x << " ";

    cout << "\nСимметрическая разность: ";
    for (auto x : simetriaRaznosti) cout << x << " ";

    return 0;
}