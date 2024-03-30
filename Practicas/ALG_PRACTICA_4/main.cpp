#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

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
vector<int> getSelectedItems(const vector<vector<int>>& table, const vector<int>& valores, const vector<int>& pesos) {
    vector<int> selectedItems; //Almacena los indices de los elementos seleccionados para dar el resultado
    int i = table.size() - 1; //Tamaño de la tabla de filas
    int w = table[0].size() - 1; //Tamaño de la tabla de columnas

    while (i > 0 && w > 0) {
        if (table[i][w] != table[i - 1][w]) {
            selectedItems.push_back(i);
            w -= pesos[i - 1]; //Se resta la posición i porque se ha incluido como solucion, esto se utiliza para pasar a la siguiente columna
        }
        i--; //Pasamos a la fila anterior de la tabla y continuamos buscando
    }

    return selectedItems;
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
    for (int i = 1; i <= n; i++) { //REPRESENTA LOS ARTICULOS U OBJETOS
        for (int w = 1; w <= W; w++) { // REPRESENTA LOS PESOS DE CADA OBJETO
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

    cout << "Valores seleccionados:" << endl;
    vector<int> selectedItems = getSelectedItems(tabla, valores, pesos);
    for (int i = selectedItems.size() - 1; i >= 0; i--) {
        cout << "Objeto " << selectedItems[i] << ": Valor = " << valores[selectedItems[i] - 1] << ", Peso = " << pesos[selectedItems[i] - 1] << endl;
    }
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
