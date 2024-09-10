#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*  Algoritmo iterativo cúbico tradicional
*
*   PARAMETROS:
*   vector<vector<int>>& A: Matriz A.
*   vector<vector<int>>& B: Matriz B
*   int n: tamaño de las matrices
*
*   RETURN:
*   Retorna la matriz resultante de la multiplicacion.
*/

vector<vector<int>> multiplicacionIterativaCubo(const vector<vector<int>>& A, const vector<vector<int>>& B, int n) {
    
    // Se crea la matriz C para escribir el resultado
    vector<vector<int>> C(n, vector<int>(n, 0));

    // Se realiza la sumatoria antes mencionada
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}