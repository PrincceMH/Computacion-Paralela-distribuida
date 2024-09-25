#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Función para multiplicar matrices
void multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0; // Inicializa el valor
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Función para llenar una matriz con valores aleatorios
void llenarMatriz(vector<vector<int>>& matriz, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 100; // Valores aleatorios entre 0 y 99
        }
    }
}

int main() {
    // Tamaños de matriz que deseas probar
    vector<int> tamanos = {100, 200, 500, 1000};

    for (int N : tamanos) {
        // Inicializa las matrices A, B y C de tamaño N x N
        vector<vector<int>> A(N, vector<int>(N));
        vector<vector<int>> B(N, vector<int>(N));
        vector<vector<int>> C(N, vector<int>(N));

        // Llena las matrices A y B con valores aleatorios
        llenarMatriz(A, N);
        llenarMatriz(B, N);

        // Mide el tiempo de inicio
        auto inicio = chrono::high_resolution_clock::now();

        // Multiplica las matrices
        multiplicarMatrices(A, B, C, N);

        // Mide el tiempo de fin
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;

        cout << "Tiempo para multiplicar matrices de tamaño " << N << "x" << N << ": " << duracion.count() << " segundos" << endl;
    }

    return 0;
}
