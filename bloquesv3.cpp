#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void block_matrix_multiply(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, vector<vector<int>>& result, int blockSize) {
    int size = mat1.size();

    // Multiplicación de matrices por bloques
    for (int i = 0; i < size; i += blockSize) {
        for (int j = 0; j < size; j += blockSize) {
            for (int k = 0; k < size; k += blockSize) {
                // Multiplicación de bloques
                for (int ii = i; ii < min(i + blockSize, size); ++ii) {
                    for (int jj = j; jj < min(j + blockSize, size); ++jj) {
                        int temp = 0;
                        for (int kk = k; kk < min(k + blockSize, size); ++kk) {
                            temp += mat1[ii][kk] * mat2[kk][jj];
                        }
                        result[ii][jj] += temp;
                    }
                }
            }
        }
    }
}

int main() {
    const int MATRIX_SIZE = 2000; // Tamaño de la matriz
    const int BLOCK_SIZE = 20; // Tamaño del bloque

    vector<vector<int>> mat1(MATRIX_SIZE, vector<int>(MATRIX_SIZE, 1));
    vector<vector<int>> mat2(MATRIX_SIZE, vector<int>(MATRIX_SIZE, 1));
    vector<vector<int>> result(MATRIX_SIZE, vector<int>(MATRIX_SIZE, 0));

    auto start = high_resolution_clock::now();

    block_matrix_multiply(mat1, mat2, result, BLOCK_SIZE);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Duración de la operación: " << duration.count() << " ms" << endl;
    cout << "Tamaño de la matriz: " << MATRIX_SIZE << ", Tamaño del bloque: " << BLOCK_SIZE << endl;
    return 0;
}
