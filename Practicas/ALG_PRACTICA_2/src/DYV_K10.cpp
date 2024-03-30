#include <iostream>
#include <vector>
#include <fstream>
#include "ostream"
#include "chrono"
using namespace std;
/*
struct Punto {
    vector<double> coords;
};

// Comprueba si p1 domina a p2
bool esDominante(const Punto &p1, const Punto &p2) { //O(K)
    bool mayorOIgual = true;
    bool estrictamenteMayor = false;
    for (int i = 0; i < p1.coords.size(); ++i) {
        if (p1.coords[i] < p2.coords[i]) {
            return false;
        }
        if (p1.coords[i] > p2.coords[i]) {
            estrictamenteMayor = true;
        }
    }
    return mayorOIgual and estrictamenteMayor;
}

// Combina las soluciones parciales de los subproblemas
vector<Punto> combinar(vector<Punto>& puntosIzquierda, vector<Punto>& puntosDerecha) { //O(N² * K)
    vector<Punto> combinado;

    // Verificar si los puntos de izquierda dominan a los de derecha
    for (int i = 0; i < puntosIzquierda.size(); ++i) {
        bool esDominanteActual = true;
        for (int j = 0; j < puntosDerecha.size(); ++j) {
            if (esDominante(puntosDerecha[j], puntosIzquierda[i])) {
                esDominanteActual = false;
                break;
            }
        }
        if (esDominanteActual) {
            combinado.push_back(puntosIzquierda[i]);
        }
    }

    // Verificar si los puntos de derecha dominan a los de izquierda
    for (int i = 0; i < puntosDerecha.size(); ++i) {
        bool esDominanteActual = true;
        for (int j = 0; j < puntosIzquierda.size(); ++j) {
            if (esDominante(puntosIzquierda[j], puntosDerecha[i])) {
                esDominanteActual = false;
                break;
            }
        }
        if (esDominanteActual) {
            combinado.push_back(puntosDerecha[i]);
        }
    }

    return combinado;
}

// Encuentra los puntos dominantes usando divide y vencerás
vector<Punto> puntosDominantesDivideYVenceras(vector<Punto>& puntos, int inicio, int fin) { // O(N² * K * log(n))
    if (inicio == fin) {
        return vector<Punto>(1, puntos[inicio]);
    }

    int medio = (inicio + fin) / 2;
    vector<Punto> puntosIzquierda = puntosDominantesDivideYVenceras(puntos, inicio, medio);
    vector<Punto> puntosDerecha = puntosDominantesDivideYVenceras(puntos, medio + 1, fin);
    return combinar(puntosIzquierda, puntosDerecha);
}

vector<Punto> puntosDominantes(vector<Punto>& puntos) {// O(N² * K * log(n))
    if (puntos.empty()) {
        return puntos;
    }
    return puntosDominantesDivideYVenceras(puntos, 0, puntos.size() - 1);
}



int main() {
    //EJEMPLO INT CON K=10
    static const int k=10;
    Punto p1 = {{1, 2, 3, 6, 1, 5, 4, 1, 8, 2}};
    Punto p2 = {{4, 5, 6, 7, 2, 2, 1, 8, 5, 3}};
    Punto p3 = {{2, 4, 6, 4, 2, 1, 1, 7, 3, 1}};
    Punto p4 = {{3, 2, 1, 7, 1, 4, 2, 1, 9, 2}};
    Punto p5 = {{5, 4, 3, 8, 3, 6, 4, 2, 9, 3}};
    vector<Punto> puntos ={p1,p2,p3,p4,p5};
    vector<Punto> dominantes = puntosDominantes(puntos);

    cout << "Puntos dominantes: " << endl;
    for (int i = 0; i < dominantes.size(); i++) {
        cout << "(";
        for (int j = 0; j < dominantes[i].coords.size(); j++) {
            cout << dominantes[i].coords[j];
            if (j < dominantes[i].coords.size() - 1) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }



    return 0;
}
*/
