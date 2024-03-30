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
vector<Punto> puntosDominantesDivideYVenceras(vector<Punto>&puntos, int inicio, int fin) { // O(N² * K * log(n))
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

    static const int K = 10;
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf;

    ofstream file;

    srand(time(0)); // Para generar números aleatorios diferentes cada vez
    file.open("Divide_Y_Venceras.txt");

    //Crear vector de puntos

    for(int n=100; n<=1500; n+=100){
        Punto aux[n];

        for(int j=0; j<n; j++){
            Punto p;
            for(int i=0; i< K; i++){
                double coord = (double)rand()/RAND_MAX * (1000 - 100);
                p.coords.push_back(coord);

            }
            aux[j]= p;

        }


        vector<Punto> puntos(aux,aux+n);
        t0 = chrono::high_resolution_clock::now(); // Tomar el tiempo de inicio
        puntosDominantes(puntos);
        tf = chrono::high_resolution_clock::now(); // Tomar el tiempo de fin

        unsigned long duration = chrono::duration_cast<chrono::microseconds>(tf - t0).count();

        file  << duration << endl; // Guardar tamaño y tiempo en el archivo


    }


}*/