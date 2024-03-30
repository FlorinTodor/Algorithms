
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;
vector<int> eliminar_repetidos_ordenado(vector<int>& v) {

    if (v.empty()) return v;
    sort(v.begin(), v.end());

    int j = 0; // última posición de un elemento único en el vector
    for (int i = 1; i < v.size(); i++) {
        if (v[i] != v[j]) {
            j++;
            v[j] = v[i];
        }
    }
    v.erase(v.begin() + j + 1, v.end());

    return v;
}
/*int main() {
    vector<int> v;
    srand(time(NULL));
    int n;
    ofstream salida("salida_ejercicio2.txt");
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf;

    for(n = 1; n <= 1000000; n*=10) {

        for (int i = 0; i < n; i++) {
            int num = rand() % 999999;
            v.push_back(num);
        }
        t0 = std::chrono::high_resolution_clock::now();

        eliminar_repetidos_ordenado(v);

        tf = std::chrono::high_resolution_clock::now();

        double tiempo = chrono::duration_cast<chrono::milliseconds>(tf - t0).count();
        salida << n << " " << tiempo << endl;
    }
    salida.close();
    return 0;
}*/
