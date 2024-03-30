#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
void printTable(const vector<vector<int>>& table) {
    int n = table.size();
    int m = table[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }
}

int MochilaPD(int n, int W, const vector<int>& valores, const vector<int>& pesos) {
    vector<vector<int>> tabla(n + 1, vector<int>(W + 1, 0));

    // Paso inicial: Llenar la primera fila y columna con ceros
    for (int i = 0; i <= n; i++) {
        tabla[i][0] = 0;
    }
    for (int w = 0; w <= W; w++) {
        tabla[0][w] = 0;
    }

    // Llenar el resto de la tabla
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (pesos[i - 1] <= w) {
                // Calcular el máximo entre no incluir el artículo i o incluirlo
                tabla[i][w] = max(tabla[i - 1][w], valores[i - 1] + tabla[i - 1][w - pesos[i - 1]]);
            } else {
                tabla[i][w] = tabla[i - 1][w];
            }
        }
    }

    cout << "Tabla generada:" << endl;
    printTable(tabla);
    cout << endl;

    return tabla[n][W];
}

int main(int argc, char *argv[]) {
    int n, W;
    vector<int> valores, pesos;

    // Abrir el archivo de datos
    ifstream archivo(argv[1]);

    if (archivo.is_open()) {
        // Leer el valor de n y W
        archivo >> n >> W;

        // Leer los valores
        int valor;
        for (int i = 0; i < n; i++) {
            archivo >> valor;
            pesos.push_back(valor);
        }

        // Leer los pesos
        int peso;
        for (int i = 0; i < n; i++) {
            archivo >> peso;
            valores.push_back(peso);
        }

        // Cerrar el archivo
        archivo.close();

        // Resolver el problema de la mochila
        int maxValor = MochilaPD(n, W, valores, pesos);

        cout << "El valor máximo que se puede obtener es: " << maxValor << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
*/