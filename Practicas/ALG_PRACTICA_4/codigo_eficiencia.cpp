#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>


using namespace std;
using namespace std::chrono;
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

    return tabla[n][W];
}

void generarNumerosRandom(int n, int& W, vector<int>& valores, vector<int>& pesos) {
    srand(static_cast<unsigned int>(time(0)));

    W = rand() % 101;

    valores.clear();
    pesos.clear();

    for (int i = 0; i < n; i++) {
        valores.push_back(rand() % 101);
        pesos.push_back(rand() % 101);
    }
}

int main() {
    ofstream datosFile("../tests/datos.txt"); // Contendrá toda la información que se usa, n, w, pesos y valores
    ofstream muestraFile("../tests/muestra.txt"); //Contendrá el tamaño de prueba y sus microsegundos
    ofstream tiemposFile("../tests/tiempos.txt");// Contendrá unicamente los microsegundos, para realizar la gráfica

    if (!datosFile.is_open() || !muestraFile.is_open() || !tiemposFile.is_open()) {
        cout << "Error al abrir los archivos." << endl;
        return 1;
    }

    vector<int> tamaños = {100, 500, 1000, 2000, 3000,4000, 5000, 6000, 7000, 8000};

    for (int i =0; i<tamaños.size(); ++i) {
        int n = tamaños[i];
        int W;
        vector<int> valores, pesos;

        generarNumerosRandom(n, W, valores, pesos);

        datosFile << "Tamaño: " << n << endl;
        datosFile << "W: " << W << endl;
        datosFile << "Valores: ";
        for (int i =0;  i< valores.size(); ++i) {
            datosFile << valores[i] << " ";
        }
        datosFile << endl;
        datosFile << "Pesos: ";
        for (int i=0; i<pesos.size(); ++i) {
            datosFile << pesos[i] << " ";
        }
        datosFile << endl;

        auto start = high_resolution_clock::now();
        int maxValor = MochilaPD(n, W, valores, pesos);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);

        muestraFile << "Tamaño: " << n;
        muestraFile << " -> Tiempo: " << duration.count() << " microsegundos" << endl;

        tiemposFile << duration.count() << endl;

        datosFile << "Valor máximo obtenido: " << maxValor << endl;
        datosFile << endl;
    }

    datosFile.close();
    muestraFile.close();
    tiemposFile.close();

    return 0;
}*/
