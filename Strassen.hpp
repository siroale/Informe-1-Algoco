#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*  Función para sumar matrices
*
*   PARAMETROS:
*   vector<vector<int>>& A: Matriz A.
*   vector<vector<int>>& B: Matriz B
*
*   RETURN:
*   Retorna la matriz resultante de la suma.
*/
vector<vector<int>> sumaMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

/*  Función para restar matrices
*
*   PARAMETROS:
*   vector<vector<int>>& A: Matriz A.
*   vector<vector<int>>& B: Matriz B
*
*   RETURN:
*   Retorna la matriz resultante de la resta.
*/
vector<vector<int>> restaMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

/*  Algoritmo de Strassen
*
*   PARAMETROS:
*   vector<vector<int>>& A: Matriz A.
*   vector<vector<int>>& B: Matriz B
*
*   RETURN:
*   Retorna la matriz resultante de la multiplicacion.
*/
vector<vector<int>> strassenMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int half = n / 2;
    vector<vector<int>> A11(half, vector<int>(half));
    vector<vector<int>> A12(half, vector<int>(half));
    vector<vector<int>> A21(half, vector<int>(half));
    vector<vector<int>> A22(half, vector<int>(half));
    vector<vector<int>> B11(half, vector<int>(half));
    vector<vector<int>> B12(half, vector<int>(half));
    vector<vector<int>> B21(half, vector<int>(half));
    vector<vector<int>> B22(half, vector<int>(half));

    // Dividimos las matrices en submatrices
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // Calculamos los productos intermedios
    auto P1 = strassenMultiplication(A11, restaMatrices(B12, B22));
    auto P2 = strassenMultiplication(sumaMatrices(A11, A12), B22);
    auto P3 = strassenMultiplication(sumaMatrices(A21, A22), B11);
    auto P4 = strassenMultiplication(A22, restaMatrices(B21, B11));
    auto P5 = strassenMultiplication(sumaMatrices(A11, A22), sumaMatrices(B11, B22));
    auto P6 = strassenMultiplication(restaMatrices(A12, A22), sumaMatrices(B21, B22));
    auto P7 = strassenMultiplication(restaMatrices(A11, A21), sumaMatrices(B11, B12));

    // Construimos la matriz resultado
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            C[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            C[i][j + half] = P1[i][j] + P2[i][j];
            C[i + half][j] = P3[i][j] + P4[i][j];
            C[i + half][j + half] = P1[i][j] + P5[i][j] - P3[i][j] - P7[i][j];
        }
    }

    return C;
}