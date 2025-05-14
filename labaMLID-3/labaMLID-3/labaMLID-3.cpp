#include <iostream>
#include <vector>
#include <sstream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int sizeStolbcov;
    cout << "Введите размерность матрицы (n): ";
    cin >> sizeStolbcov;
    cin.ignore(); 

    vector<vector<int>> matrix(sizeStolbcov);

    cout << "ВАЖНО! При вводе '1' - связь есть, '0' - связи нет" << endl;
    cout << "Введите матрицу отношения:" << endl;

    for (int i = 0; i < sizeStolbcov; ++i) {
        string line;
        getline(cin, line);
        istringstream isstirng(line);
        int num;
        while (isstirng >> num) {
            matrix[i].push_back(num);
        }
    }

    bool functionOrNot = true;

    for (int i = 0; i < sizeStolbcov; ++i) {
        int count = 0;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
        if (count != 1) {
            functionOrNot = false;
            break;
        }
    }

    if (functionOrNot) {
        cout << "Данное отношение является функцией." << endl;
    }
    else {
        cout << "Данное отношение НЕ является функцией." << endl;
    }

    return 0;
}