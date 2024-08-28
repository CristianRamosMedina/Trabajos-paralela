#include <iostream>
#include <chrono>
#define max 10000  

using namespace std;

int main() {
    cout << "Datos " << max << endl;
    // Asignar memoria dinámica
    double** a = new double*[max];
    for(int i = 0; i < max; i++) {
        a[i] = new double[max];
    }
    
    double* x = new double[max];
    double* y = new double[max];

    // Inicialización de la matriz y vectores
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            a[i][j] = i + j;  
            // Llenar matriz con valores simples
        }
        x[i] = i;  
        // Llenar vector x
        y[i] = 0;  
        // Inicializar vector y a cero
    }
    
    auto start = chrono::high_resolution_clock::now();
    
    // Bucle1: acceso por filas
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            y[i] += a[i][j] * x[j];  // Multiplicación 
        }
    }
    
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> dur = end - start;
    cout << "Primer par de bucles: " << dur.count() << " s" << endl;
    
    start = chrono::high_resolution_clock::now();
    
    //Bucle2: acceso por columnas
    for (int j = 0; j < max; j++) {
        for (int i = 0; i < max; i++) {
            y[i] += a[i][j] * x[j];  // Multiplicación diferente orden
        }
    }
    
    end = chrono::high_resolution_clock::now();
    
    dur = end - start;
    cout << "Segundo par de bucles: " << dur.count() << " s" << endl;
    
    

    // Liberar memoria
    delete[] x;
    delete[] y;
    for(int i = 0; i < max; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
