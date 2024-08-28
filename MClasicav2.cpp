#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

const int MATRIX_SIZE = 2000;

void matrix_multiply(const vector<vector<double>>& mat1, 
                     const vector<vector<double>>& mat2, 
                     vector<vector<double>>& result) {
    // Inicializar la matriz de resultados con ceros
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            result[i][j] = 0.0;
        }
    }

    auto start = high_resolution_clock::now();

    // Multiplicación de matrices
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            for (int k = 0; k < MATRIX_SIZE; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Duración de la operación: " << duration.count() << " ms\n";
    cout << "Tamaño de la matriz: " << MATRIX_SIZE << "\n";
}

int main() {
    vector<vector<double>> mat1(MATRIX_SIZE, vector<double>(MATRIX_SIZE));
    vector<vector<double>> mat2(MATRIX_SIZE, vector<double>(MATRIX_SIZE));
    vector<vector<double>> result(MATRIX_SIZE, vector<double>(MATRIX_SIZE));

    // Inicializar las matrices con valores
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            mat1[i][j] = 1.0;
            mat2[i][j] = 1.0;
        }
    }

    matrix_multiply(mat1, mat2, result);

    return 0;
}
