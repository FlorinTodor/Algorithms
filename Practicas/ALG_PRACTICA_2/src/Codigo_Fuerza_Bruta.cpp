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

vector<Punto> puntosDominantes(vector<Punto> &puntos) {
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
    //EJEMPLO INT CON K=3

    static const int K = 10;
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf;

    ofstream file;

    srand(time(0)); // Para generar números aleatorios diferentes cada vez
    file.open("Fuerza_Bruta.txt");

    //Crear vector de puntos

    for(int n=200; n<=2000; n+=200){
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

        file << n << " " << duration << endl; // Guardar tamaño y tiempo en el archivo

    }







    return 0;
}

*/