
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;

const int MAX = 1000; // NO vamos a crear una matriz dinámica para este algoritmo, vamos a hacer una matriz estática
int grafo[MAX][MAX];
int N;

void imprimirCircuito(vector<int> circuito) {
    for (int i = circuito.size() - 1; i >= 0; i--) {
        cout << circuito[i];
        if (i) cout << " -> "; // Para que solo muestres -> en el caso de que i sea verdadero, para que no haya un -> de más
    }
}

int encontrarSiguienteVertice(int u) {
    int maxGrado = -1;
    int siguienteVertice = -1;
    for (int v = 0; v < N; v++) {
        if (grafo[u][v]) {
            int grado = 0;
            for (int w = 0; w < N; w++) {
                if (grafo[v][w]) grado++;
            }
            if (grado > maxGrado) {
                maxGrado = grado;
                siguienteVertice = v;
            }
        }
    }
    return siguienteVertice;
}

bool esFactible(int u, int v) {
    return grafo[u][v];
}

bool esSolucion(vector<int> circuito) {
    for (int u = 0; u < N; u++) {
        for (int v = u + 1; v < N; v++) {
            if (grafo[u][v]) return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    ifstream fichero;
    if (argc < 2) {
        cerr << "NO SE HA ENVIADO EL FICHERO QUE CONTIENE LA MATRIZ DEL GRAFO" << endl;
    }
    fichero.open(argv[1]);
    if (fichero) {
        fichero >> N;  // O(1)

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                fichero >> grafo[i][j];  // O(1)
            }
        }
        fichero.close();  // O(1)

        vector<int> circuito;  // O(1)
        stack<int> pila;  // O(1)

        pila.push(0);  // O(1)

        while (!pila.empty()) {  // Hasta O(N)
            int u = pila.top();  // O(1)
            int v = encontrarSiguienteVertice(u);  // O(N)
            if (v != -1) {
                grafo[u][v] = grafo[v][u] = 0;  // O(1)
                pila.push(v);  // O(1)
            }
            else {
                circuito.push_back(u);  // O(1)
                pila.pop();  // O(1)
            }
        }
        if (esSolucion(circuito)) {  // O(N^2)
            if (circuito.front() == circuito.back()) {  // O(1)
                cout << N << endl;  // O(1)
                imprimirCircuito(circuito);  // O(N)
            }
            else {
                cerr << "NO ES UN CIRCUITO DE EULER";  // O(1)
            }
        }
    }
    else {
        throw ios::failure("No se ha podido abrir el fichero");  // O(1)
    }
    return 0;  // O(1)
}

