#include <iostream>
#include <vector>
#include <fstream>
#include "ostream"
#include "chrono"
using namespace std;

struct Punto {
    vector<double> coords;
};

bool esDominante(const Punto &p1, const Punto &p2) {
    bool mayorOIgual = true;
    bool estrictamenteMayor = false;
    for (int i = 0; i < p1.coords.size(); i++) {
        if (p1.coords[i] < p2.coords[i]) {
            return false;
        }
        if (p1.coords[i] > p2.coords[i]) {
            estrictamenteMayor = true;
        }
    }
    return mayorOIgual and estrictamenteMayor;
}

vector<Punto> puntosDominantes(vector<Punto> puntos) {
    vector<Punto> dominantes;
    for (int i = 0; i < puntos.size(); i++) {
        bool esDominanteActual = true;
        for (int j = 0; j < puntos.size() && esDominanteActual; j++) {

            if (i != j && esDominante(puntos[j], puntos[i])) {
                esDominanteActual = false;
            }
        }
        if (esDominanteActual) {
            dominantes.push_back(puntos[i]);
        }
    }
    return dominantes;
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

