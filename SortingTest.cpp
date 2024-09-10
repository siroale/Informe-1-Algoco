#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>

#include "SelectionSort.hpp"
#include "MergeSort.hpp"
#include "Quicksort.hpp"

using namespace std;
using namespace std::chrono;

/*  Función para leer un dataset desde un archivo y guardarlo en un vector
*
*   PARAMETROS:
*   const string& filename: El nombre del archivo a leer
*
*   RETURN:
*   vector<int> dataset: El dataset leido en un vector
*/
vector<int> readDataset(const string& filename) {
    vector<int> dataset;
    ifstream file(filename);
    if (file.is_open()) {
        int num;
        while (file >> num) {
            dataset.push_back(num);
        }
        file.close();

    } else {
        cerr << "No se pudo abrir el archivo " << filename << endl;
    }
    return dataset;
}

/*  Funcion para escribir el Output en un txt
*
*   PARAMETROS:
*   vector<int>& arr: El vector ordenado
*   int n: El largo del vector
*   string filename: El nombre del archivo a crear
*
*   RETURN:
*   No retorna nada.
*/
void writeOutput(vector<int>& arr, int n, string filename){
    filename = "Outputs/" + filename + ".txt";
    ofstream file(filename);
    for(int i = 0; i < n; i++){
        file << arr[i] << endl;
    }
    file.close();
}

int main() {
    
    vector<string> files = {"100", "1000", "10000", "100000", "1000000", "10000000"};
    string prefix; // Cambiar segun el tipo de dataset
    vector<double> promedios;
    string categoryFilename;

    // Menu que se muestra por consola para elegir el algoritmo y el dataset.
    int opcionAlgoritmo;
    std::cout << "1) Selection sort" << endl;
    std::cout << "2) Merge sort" << endl;
    std::cout << "3) Quicksort" << endl;
    std::cout << "4) Sort implementado en C++" << endl;
    std::cout << "Elija algoritmo a utilizar: ";cin >> opcionAlgoritmo; std::cout << endl;

    int categoriaDataset;
    std::cout << "1) Desordenado" << endl;
    std::cout << "2) Semiordenado" << endl;
    std::cout << "3) Parcialmente ordenado" << endl;
    std::cout << "4) Desordenado con repeticiones" << endl;
    std::cout << "Elija categoria de Dataset a utilizar: "; cin >> categoriaDataset; std::cout << endl;

    // Se elige la ruta del archivo correspondiente a la eleccion realizada
    switch(categoriaDataset){
        case 1: prefix = "Datasets/unordered_"; categoryFilename = "unordered_"; break;
        case 2: prefix = "Datasets/semiordered_"; categoryFilename = "semiordered_"; break;
        case 3: prefix = "Datasets/partially_ordered_"; categoryFilename = "partiallyordered_"; break;
        case 4: prefix = "Datasets/unordered_repeats_"; categoryFilename = "unorderedrepeats_"; break;
    }

    // Se realizan 10 pruebas por cada tamanio de dataset
    for (int index = 0; index < files.size(); index++){
        double promedio = 0;
        bool outputWritingFlag = 1; // Flag para escribir una sola vez
        string outputFilename = categoryFilename;
        for(int i = 0; i<10; i++){
        
            string filename = prefix + files[index] + ".txt";
            vector<int> dataset = readDataset(filename);
            
            if(outputWritingFlag){
                std::cout << "Dataset leído desde " << filename << " con " << dataset.size() << " elementos." << endl;
                std::cout << endl;
            }
            
            // Mide el tiempo de inicio
            auto start = high_resolution_clock::now();

            // Se ejecuta el algoritmo elegido
            switch(opcionAlgoritmo){
                case 1: selectionSort(dataset, dataset.size()); if (outputWritingFlag) {outputFilename += "selectionsort_";};break;
                case 2: mergeSort(dataset, 0, dataset.size() - 1); if (outputWritingFlag) {outputFilename += "mergesort_";};break;
                case 3: quickSort(dataset, 0, dataset.size() - 1); if (outputWritingFlag) {outputFilename += "quicksort_";}; break;
                case 4: sort(dataset.begin(), dataset.end()); if (outputWritingFlag) {outputFilename += "sortlibreria_";}; break;
            }

            // Mide el tiempo de fin
            auto stop = high_resolution_clock::now();

            // Se escribe el resultado en un archivo .txt
            if (outputWritingFlag){

                outputFilename = outputFilename + files[index];
                cout << "Escribiendo..." << endl;
                writeOutput(dataset, dataset.size(), outputFilename);
                outputWritingFlag = 0;
                cout << "Output escrito en " << outputFilename << endl;
                cout << endl;

            }

            // Calcula la duración en microsegundos
            auto duration_us = duration_cast<microseconds>(stop - start);
            // Calcula la duración en segundos
            double duration_s = duration_us.count() / 1e6;
            promedio = promedio + duration_s;

            // Imprime el tiempo tomado
            //std::cout << "Ciclo "<< i << " Tiempo de ejecución del Sort: " << duration_us.count() << " microsegundos" << endl;
            std::cout << "Ciclo "<< i + 1 << " Tiempo de ejecución del Sort: " << duration_s << " segundos" << endl;
        }
        promedio = promedio/10;
        std::cout << endl;
        std::cout << "Promedio de tiempo de ejecucion: " << promedio << endl;
        std::cout << "-----------------------------------------------------" << endl;
        promedios.push_back(promedio);
    }
    
    // Imprime todos los promedios
    for (int i = 0; i < promedios.size(); i++){
        std::cout <<"Promedio en tiempo de ejecucion "<< i << " : " << promedios[i] << endl;
    }

    return 0;
}