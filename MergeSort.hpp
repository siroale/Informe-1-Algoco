#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

/*  Función para mezclar dos subarrays en orden
*
*   PARAMETROS:
*   vector<int>& arr: El vector a ordenar
*   int left: Numero entero que indica el inicio del vector
*   int mid: Numero entero que indica el centro del vector
*   int right: Numero entero que indica el final del vector
*
*   RETURN:
*   No retorna nada.
*/
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear arrays temporales
    vector<int> L(n1), R(n2);

    // Copiar datos a los arrays temporales
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    // Mezclar los arrays temporales en arr[l..r]
    int i = 0;  // Índice inicial del primer subarray
    int j = 0;  // Índice inicial del segundo subarray
    int k = left;  // Índice inicial del array mezclado

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*  Función principal de Merge Sort
*
*   PARAMETROS:
*   vector<int>& arr: El vector a ordenar
*   int left: Numero entero que indica el inicio del vector
*   int right: Numero entero que indica el final del vector
*
*   RETURN:
*   No retorna nada.
*/
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar la primera y segunda mitad
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mezclar las dos mitades ordenadas
        merge(arr, left, mid, right);
    }
}
