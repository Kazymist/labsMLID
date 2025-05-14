#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Введите элементы множества через пробел: ";
    string input_line;
    getline(cin, input_line);

    vector<int> elements;
    set<int> strockElements;

    stringstream ss(input_line);
    int num;
    while (ss >> num) {
        elements.push_back(num);
        strockElements.insert(num);
    }

    if (elements.empty()) {
        cout << "Множество не может быть пустым!" << endl;
        return 1;
    }

    cout << "\nВведите пары отношения \n";
    cout << "Пустая строка – конец ввода:\n";

    vector<pair<int, int>> pairs;
    while (true) {
        string line;
        getline(cin, line);
        if (line.empty()) break;

        stringstream pariStork(line);
        int a, b;

        if (!(pariStork >> a >> b)) {
            cout << "Ошибка формата!";
            continue;
        }

        string extra;
        if (pariStork >> extra) {
            cout << "Только два числа через пробел";
            continue;
        }

        if (!strockElements.count(a) || !strockElements.count(b)) {
            cout << "Ошибка: элементы должны быть из множества! Повторите: ";
            continue;
        }

        pairs.emplace_back(a, b);
    }

    bool refliksivnost = true;
    set<pair<int, int>> pair_set(pairs.begin(), pairs.end());
    for (int x : elements) {
        if (!pair_set.count({ x, x })) {
            refliksivnost = false;
            break;
        }
    }

    bool symmetrichnost = true;
    for (auto p : pairs) {
        if (!pair_set.count({ p.second, p.first })) {
            symmetrichnost = false;
            break;
        }
    }

    bool antisymmetrichnost = true;
    for (auto p : pairs) {
        if (p.first != p.second && pair_set.count({ p.second, p.first })) {
            antisymmetrichnost = false;
            break;
        }
    }

    bool transitivnost = true;
    for (auto p1 : pairs) {
        for (auto p2 : pairs) {
            if (p1.second == p2.first && !pair_set.count({ p1.first, p2.second })) {
                transitivnost = false;
                break;
            }
        }
    }

    cout << "\nРезультаты анализа:\n";
    cout << "Рефлексивность: " << (refliksivnost ? "Да" : "Нет") << endl;
    cout << "Симметричность: " << (symmetrichnost ? "Да" : "Нет") << endl;
    cout << "Кососимметричность: " << (antisymmetrichnost ? "Да" : "Нет") << endl;
    cout << "Транзитивность: " << (transitivnost ? "Да" : "Нет") << endl;

    return 0;
}