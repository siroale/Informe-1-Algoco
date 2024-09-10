#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

/*  Implermentacion del Selection Sort
*
*   PARAMETROS:
*   vector<int>& arr: El vector a ordenar
*   int n: El largo del vector
*
*   RETURN:
*   No retorna nada.
*/
void selectionSort(vector<int>& arr, int n) {

    for (int i = 0; i < n - 1; i++) {
        // Encuentra el mínimo elemento en el array no ordenado
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Intercambia el mínimo elemento encontrado con el primer elemento
        swap(arr[i], arr[minIdx]);
    }
}