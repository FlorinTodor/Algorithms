#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;
/*
void insertarEnPos( double *apo, int pos){
    int idx = pos-1;
    int padre;
    if ( idx > 0){

        if ( idx%2 == 0){
            padre=(idx-2)/2;
        }else{
            padre=(idx-1)/2;
        }

        if( apo[padre] > apo[idx]){
            double tmp= apo[idx];
            apo[idx] = apo[padre];
            apo[padre] =tmp;
            insertarEnPos(apo,padre+1);
        }
    }
}

void reestructurarRaiz( double *apo, int pos, int tamapo){
    int minhijo;
    if( 2*pos+1 < tamapo){
        minhijo= 2*pos+1;
        if ((minhijo+1 < tamapo) && (apo[minhijo] > apo[minhijo+1])) minhijo++;
        if (apo[pos] > apo[minhijo]) {
            double tmp = apo[pos];
            apo[pos] = apo[minhijo];
            apo[minhijo] = tmp;
            reestructurarRaiz(apo,minhijo,tamapo);
        }

    }
}

void HeapSort(int *v, int n){
    double *apo= new double [n];
    int tamapo=0;

    for(int i=0; i< n; i++){
        apo[tamapo] = v[i];
        tamapo++;
        insertarEnPos(apo,tamapo);
    }

    for(int i=0; i<n; i++){
        v[i] = apo[0];
        tamapo--;
        apo[0]= apo[tamapo];
        reestructurarRaiz(apo,0,tamapo);
    }
    delete [] apo;
}

int main () {

    ofstream file;
    file.open("heapsort.txt");

    srand(time(0)); // Para generar números aleatorios diferentes cada vez

    for (int n = 1000; n <= 100000; n += 1000) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = rand() % 1000; // Generar números aleatorios entre 0 y 999
        }

        chrono::time_point<std::chrono::high_resolution_clock> t0, tf;
        t0 = chrono::high_resolution_clock::now(); // Tomar el tiempo de inicio

        HeapSort(v.data(),n);

        tf = chrono::high_resolution_clock::now(); // Tomar el tiempo de fin
        auto duration = chrono::duration_cast<chrono::microseconds>(tf - t0);

        file << n << " " << duration.count() << endl; // Guardar tamaño y tiempo en el archivo
    }

    file.close();



}*/