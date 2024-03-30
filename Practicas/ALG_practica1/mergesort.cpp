#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
/*
vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> result;
    while (left.size() > 0 && right.size() > 0) {
        if (left[0] <= right[0]) {
            result.push_back(left[0]);
            left.erase(left.begin());
        }
        else {
            result.push_back(right[0]);
            right.erase(right.begin());
        }
    }
    if (left.size() > 0) {
        result.insert(result.end(), left.begin(), left.end());
    }
    if (right.size() > 0) {
        result.insert(result.end(), right.begin(), right.end());
    }
    return result;
}

vector<int> mergesort(vector<int> m) {
    if (m.size() <= 1) {
        return m;
    }
    else {
        int middle = m.size() / 2;
        vector<int> left, right;
        for (int i = 0; i < middle; i++) {
            left.push_back(m[i]);
        }
        for (int i = middle; i < m.size(); i++) {
            right.push_back(m[i]);
        }
        left = mergesort(left);
        right = mergesort(right);
        if (left.back() <= right.front()) {
            left.insert(left.end(), right.begin(), right.end());
            return left;
        }
        else {
            return merge(left, right);
        }
    }
}

int main() {
    ofstream file;
    file.open("mergesort.txt");

    srand(time(0)); // Para generar números aleatorios diferentes cada vez

    for (int n = 1000; n <= 100000; n += 1000) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = rand() % 1000; // Generar números aleatorios entre 0 y 999
        }

        chrono::time_point<std::chrono::high_resolution_clock> t0, tf;
        t0 = chrono::high_resolution_clock::now(); // Tomar el tiempo de inicio
        vector<int> sorted = mergesort(v);
        tf = chrono::high_resolution_clock::now(); // Tomar el tiempo de fin
        auto duration = chrono::duration_cast<chrono::microseconds>(tf - t0);

        file << n << " " << duration.count() << endl; // Guardar tamaño y tiempo en el archivo
    }

    file.close();

    return 0;
}

/*
 *
gnuplot
set title "Tiempos de ejecucion para MergeSort"
set xlabel "Tamaño del vector"
set ylabel "Tiempo (segundos)"
plot "mergesort.txt" with linespoints

 */