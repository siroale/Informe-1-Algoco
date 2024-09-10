#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <fstream>
#include <unordered_set>

using namespace std;

// Función para generar datasets de matrices nxn y guardarlas en un archivo
void generarDataset(int n, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
        return;
    }

    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file << rand() % 100 << " ";
        }
        file << std::endl;
    }

    file.close();
}

int main() {
    
    vector<int> sizes = {16, 32, 64, 128, 256, 512, 1024, 2048};

    string prefix1 = "Datasets/MatrizA_";
    string prefix2 = "Datasets/MatrizB_";
    // Generar datasets
    for (int size : sizes){
        generarDataset(size, prefix1 + to_string(size) + ".txt");
        generarDataset(size, prefix2 + to_string(size) + ".txt");

    std::cout << "Datasets generados y guardados en " << prefix1 + to_string(size) + ".txt" << " y en " << prefix2 + to_string(size) + ".txt" << std::endl;    
    }


    return 0;
}
