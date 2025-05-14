#include <iostream>
#include <vector>
#include <climits>
#include <locale.h>

using namespace std;

void block(const vector<vector<int>>& graph) {

    int Vershina = graph.size();
    vector<vector<int>> poiskDostijimosti(Vershina, vector<int>(Vershina, 0));

    for (int i = 0; i < Vershina; ++i) {
        for (int j = 0; j < Vershina; ++j) {
            if (graph[i][j] > 0 || i == j) {
                poiskDostijimosti[i][j] = 1;
            }
        }
    }

    for (int k = 0; k < Vershina; ++k) {
        for (int i = 0; i < Vershina; ++i) {
            for (int j = 0; j < Vershina; ++j) {
                if (poiskDostijimosti[i][k] && poiskDostijimosti[k][j]) {
                    poiskDostijimosti[i][j] = 1;
                }
            }
        }
    }

    cout << "\nМатрица достижимости:\n";
    for (int i = 0; i < Vershina; ++i) {
        for (int j = 0; j < Vershina; ++j) {
            cout << poiskDostijimosti[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    int Vershina;
    cout << "Введите количество вершин: ";
    cin >> Vershina;

    vector<vector<int>> graph(Vershina, vector<int>(Vershina));

    cout << "Введите матрицу смежности (" << Vershina << "x" << Vershina << "):\n";
    for (int i = 0; i < Vershina; ++i) {
        for (int j = 0; j < Vershina; ++j) {
            cin >> graph[i][j];
        }
    }

    block(graph);

    return 0;
}