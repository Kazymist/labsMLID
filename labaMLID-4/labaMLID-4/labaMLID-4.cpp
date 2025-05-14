#include <iostream>
#include <vector>
#include <climits>
#include <locale.h>

using namespace std;

void blockVicislenyaProverka(const vector<vector<int>>& graph, int nachalo, int finish) {

    int Vershina = graph.size();

    vector<int> distancia(Vershina, INT_MAX);
    vector<bool> posehenie(Vershina, false);
    vector<int> pytb(Vershina, -1);

    distancia[nachalo] = 0;

    for (int i = 0; i < Vershina - 1; ++i) {

        int minDistans = INT_MAX, u;

        for (int n = 0; n < Vershina; ++n) {
            if (!posehenie[n] && distancia[n] < minDistans) {
                minDistans = distancia[n];
                u = n;
            }
        }
        if (minDistans == INT_MAX) break;
        posehenie[u] = true;

        for (int n = 0; n < Vershina; ++n) {
            if (!posehenie[n] && graph[u][n] && distancia[u] != INT_MAX
                && distancia[u] + graph[u][n] < distancia[n]) {
                distancia[n] = distancia[u] + graph[u][n];
                pytb[n] = u;
            }
        }
    }

    if (distancia[finish] == INT_MAX) {
        cout << "Пути между " << nachalo << " и " << finish << " нету.\n";
    }
    else {
        cout << "Минимальный путь: ";

        vector<int> path;

        for (int n = finish; n != -1; n = pytb[n]) {
            path.push_back(n);
        }
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i];
            if (i != 0) cout << " -> ";
        }
        cout << "\nОбщая стоимость: " << distancia[finish] << endl;
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    int Vershina, nachalo, finish;

    cout << "Введите количество вершин: ";
    cin >> Vershina;
    vector<vector<int>> graph(Vershina, vector<int>(Vershina));

    cout << "Введите матрицу смежности (" << Vershina << "x" << Vershina << "):\n";
    for (int i = 0; i < Vershina; ++i) {
        for (int j = 0; j < Vershina; ++j) {
            cin >> graph[i][j];
        }
    }

    cout << "Введите начальную вершину (0 - " << Vershina-1 << "): ";
    cin >> nachalo;
    cout << "Введите конечную вершину (0 - " << Vershina-1 << "): ";
    cin >> finish;

    blockVicislenyaProverka(graph, nachalo, finish);

    return 0;
}