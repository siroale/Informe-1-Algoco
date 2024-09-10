#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*  Algoritmo iterativo cúbico optimizado con transposición
*
*   PARAMETROS:
*   vector<vector<int>>& A: Matriz A.
*   vector<vector<int>>& B: Matriz B
*   int n: tamaño de las matrices
*
*   RETURN:
*   Retorna la matriz resultante de la multiplicacion.
*/
vector<vector<int>> multiplicacionIterativaCuboOptimizada(const vector<vector<int>>& A, vector<vector<int>> B, int n) {

    vector<vector<int>> C(n, vector<int>(n, 0));

    // Transponemos la matriz B para mejorar la localidad de datos
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(B[i][j], B[j][i]);
        }
    }

    // Se realiza la multiplicacion
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[j][k];
            }
        }
    }

    return C;
}