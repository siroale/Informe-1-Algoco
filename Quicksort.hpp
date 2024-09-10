#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

/*  Función para intercambiar dos elementos
*
*   PARAMETROS:
*   int& a: numero entero
*   int& b: numero entero
*
*   RETURN:
*   No retorna nada.
*/
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/*  Función de partición que toma el último elemento como pivote
*
*   PARAMETROS:
*   vector<int>& arr: El vector a ordenar
*   int low: Primera posicion del vector
*   int high: Ultima posicion del vector
*
*   RETURN:
*   Retorna la posicion en la que se coloca el pivote.
*/
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Pivote
    int i = (low - 1);  // Índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++;  // Incrementa el índice del elemento más pequeño
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/*  Función principal de Quick Sort
*
*   PARAMETROS:
*   vector<int>& arr: El vector a ordenar
*   int low: primera posicion del arreglo
*   int high: ultima posicion del arreglo
*
*   RETURN:
*   No retorna nada.
*/

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi es el índice de partición, arr[pi] está en el lugar correcto
        int pi = partition(arr, low, high);

        // Ordena los elementos por separado antes y después de la partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}