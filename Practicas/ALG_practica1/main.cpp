#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;


vector<int> eliminar_repetidos(vector<int> v) {
    vector<int> sin_repetidos;
    for (auto x : v) {
        if (find(sin_repetidos.begin(), sin_repetidos.end(), x) == sin_repetidos.end())
            sin_repetidos.push_back(x);
    }
    return sin_repetidos;
}

int main() {
    vector<int> v;
    srand(time(NULL));
    int n;
    ofstream salida("salida_ejercicio1.txt");
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf;
    for(n = 1000; n <= 10000; n+=1000){

        for (int i = 0; i < n; i++) {
            v.push_back(rand()%99999);
        }

        t0 = std::chrono::high_resolution_clock::now();

        vector<int> sin_repetidos = eliminar_repetidos(v);

        tf = std::chrono::high_resolution_clock::now();

        double tiempo = chrono::duration_cast<chrono::milliseconds>(tf - t0).count();
        salida << n << " " << tiempo << endl;


    }
    salida.close();
    return 0;
}