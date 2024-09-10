#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

#include "Tradicional.hpp"
#include "Optimizado.hpp"
#include "Strassen.hpp"

using namespace std;
using namespace std::chrono;

// Función para leer matrices nxn desde un archivo
vector<vector<int>> leerMatriz(int n, const string& filename) {
    ifstream file(filename);
    vector<vector<int>> matriz(n, vector<int>(n));

    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo para leer." << endl;
        return matriz;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> matriz[i][j];
        }
    }

    file.close();
    return matriz;
}


int main() {

    // Tamaños de las matrices a leer 
    vector<int> sizes = {16, 32, 64, 128, 256, 512, 1024, 2048};
    string prefix1 = "Datasets/MatrizA_";
    string prefix2 = "Datasets/MatrizB_";

    // Menu para elegir el algoritmo a probar
    int algorithmChoice;
    cout << "1) Algoritmo cubico tradicional" << endl;
    cout << "2) Algoritmo cubico optimizado con transposicion" << endl;
    cout << "3) Algoritmo de Strassen" << endl;    
    cout << "Indique que algoritmo quiere probar: "; cin >> algorithmChoice ;cout << endl;

    for (int i = 0; i < sizes.size(); i++){

        // Leer matrices desde los archivos
        auto A = leerMatriz(sizes[i], prefix1 + to_string(sizes[i]) + ".txt");
        auto B = leerMatriz(sizes[i], prefix2 + to_string(sizes[i]) + ".txt");

        // Matriz para guardar el resultado
        vector<vector<int>> C(sizes[i], vector<int>(sizes[i]));

        int n = A.size();

        auto start = high_resolution_clock::now();
        switch(algorithmChoice){
            case 1: C = multiplicacionIterativaCubo(A, B, n); break;
            case 2: C = multiplicacionIterativaCuboOptimizada(A, B, n); break;
            case 3: C = strassenMultiplication(A, B); break;
        }
        auto stop = high_resolution_clock::now();
        auto duration_us = duration_cast<microseconds>(stop - start);
        double duration_s = duration_us.count() / 1e6;
    
        cout << "Tiempo de ejecucion del algoritmo en la matriz de tamaño " << to_string(sizes[i]) << " :" << duration_s << endl;
    }

    return 0;
}

