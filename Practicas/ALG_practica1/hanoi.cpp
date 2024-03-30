#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

void hanoi(int M, int i, int j){
    if (M > 0){
        hanoi(M-1,i,6-i-j);
        cout<< i << " -> "<<j<<endl;
        hanoi(M-1,6-i-j,j);
    }
}
/*
int main()
{
    int n;
    ofstream salida("hanoi.txt");
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf;
    for (n = 1000; n <= 100000; n+=1000)
    {
        t0 = std::chrono::high_resolution_clock::now();
        hanoi()
        tf = std::chrono::high_resolution_clock::now();
        double tiempo = chrono::duration_cast<chrono::milliseconds>(tf - t0).count();
        salida << n << " " << tiempo << endl;
    }
    salida.close();
    return 0;
}*/