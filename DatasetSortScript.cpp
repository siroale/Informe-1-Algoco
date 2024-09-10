#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <fstream>
#include <unordered_set>

using namespace std;

// Función para guardar un dataset en un archivo
void saveDataset(const vector<int>& dataset, const string& filename) {
    ofstream file("Datasets/" + filename);
    if (file.is_open()) {
        for (const int& num : dataset) {
            file << num << "\n";
        }
        file.close();
        cout << "Dataset guardado en " << filename << endl;
    } else {
        cerr << "No se pudo abrir el archivo " << filename << endl;
    }
}

// Función para generar un dataset ordenado
vector<int> generateOrderedDataset(int size) {
    vector<int> dataset(size);
    iota(dataset.begin(), dataset.end(), 1); // Genera números de 1 a size
    return dataset;
}

// Función para generar un dataset parcialmente ordenado
vector<int> generatePartiallyOrderedDataset(int size) {
    vector<int> dataset = generateOrderedDataset(size);
    // Mezclar el 10% del dataset
    int mixCount = size / 10;
    random_device rd;
    mt19937 g(rd());
    shuffle(dataset.begin(), dataset.begin() + mixCount, g);
    return dataset;
}

// Función para generar un dataset semi ordenado
vector<int> generateSemiOrderedDataset(int size) {
    vector<int> dataset = generateOrderedDataset(size);
    // Mezclar el 25% del dataset
    int mixCount = size / 2;
    random_device rd;
    mt19937 g(rd());
    shuffle(dataset.begin(), dataset.begin() + mixCount, g);
    return dataset;
}

// Función para generar un dataset desordenado
vector<int> generateUnorderedDataset(int size) {
    vector<int> dataset = generateOrderedDataset(size);
    random_device rd;
    mt19937 g(rd());
    shuffle(dataset.begin(), dataset.end(), g);
    return dataset;
}

// Función para generar un dataset desordenado con números repetidos
vector<int> generateUnorderedWithRepeatsDataset(int size) {
    vector<int> dataset(size);
    random_device rd;
    mt19937 g(rd());
    uniform_int_distribution<int> dist(1, size / 10); // Números repetidos en un rango más pequeño
    generate(dataset.begin(), dataset.end(), [&]() { return dist(g); });
    shuffle(dataset.begin(), dataset.end(), g);
    return dataset;
}


int main() {
    vector<int> sizes = {100, 1000, 10000, 100000, 1000000, 10000000};
    
    for (int size : sizes) {
        // Generar datasets
        vector<int> partiallyOrderedDataset = generatePartiallyOrderedDataset(size);
        vector<int> semiOrderedDataset = generateSemiOrderedDataset(size);
        vector<int> unorderedDataset = generateUnorderedDataset(size);
        vector<int> unorderedWithRepeatsDataset = generateUnorderedWithRepeatsDataset(size);
        
        // Guardar datasets en archivos
        saveDataset(partiallyOrderedDataset, "partially_ordered_" + to_string(size) + ".txt");
        saveDataset(semiOrderedDataset, "semiordered_" + to_string(size) + ".txt");
        saveDataset(unorderedDataset, "unordered_" + to_string(size) + ".txt");
        saveDataset(unorderedWithRepeatsDataset, "unordered_repeats_" + to_string(size) + ".txt");
    }

    return 0;
}
