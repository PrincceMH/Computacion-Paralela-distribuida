#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Función para multiplicar matrices clásicamente
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

// Función para multiplicar matrices usando bloques
void multiplicarMatricesBloques(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int N, int blockSize) {
    for (int ii = 0; ii < N; ii += blockSize) {
        for (int jj = 0; jj < N; jj += blockSize) {
            for (int kk = 0; kk < N; kk += blockSize) {
                for (int i = ii; i < min(ii + blockSize, N); i++) {
                    for (int j = jj; j < min(jj + blockSize, N); j++) {
                        for (int k = kk; k < min(kk + blockSize, N); k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
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
    int blockSize = 64; // Tamaño del bloque (puedes ajustar este valor)

    for (int N : tamanos) {
        // Inicializa las matrices A, B y C de tamaño N x N
        vector<vector<int>> A(N, vector<int>(N));
        vector<vector<int>> B(N, vector<int>(N));
        vector<vector<int>> C(N, vector<int>(N, 0));

        // Llena las matrices A y B con valores aleatorios
        llenarMatriz(A, N);
        llenarMatriz(B, N);

        // Mide el tiempo de inicio para la versión clásica
        auto inicioClásico = chrono::high_resolution_clock::now();

        // Multiplica las matrices de manera clásica
        multiplicarMatrices(A, B, C, N);

        // Mide el tiempo de fin para la versión clásica
        auto finClásico = chrono::high_resolution_clock::now();
        chrono::duration<double> duracionClásica = finClásico - inicioClásico;

        cout << "Tiempo para multiplicar matrices clásicas de tamaño " << N << "x" << N << ": " << duracionClásica.count() << " segundos" << endl;

        // Reinicializa la matriz C
        fill(C.begin(), C.end(), vector<int>(N, 0));

        // Mide el tiempo de inicio para la versión por bloques
        auto inicioBloques = chrono::high_resolution_clock::now();

        // Multiplica las matrices por bloques
        multiplicarMatricesBloques(A, B, C, N, blockSize);

        // Mide el tiempo de fin para la versión por bloques
        auto finBloques = chrono::high_resolution_clock::now();
        chrono::duration<double> duracionBloques = finBloques - inicioBloques;

        cout << "Tiempo para multiplicar matrices por bloques de tamaño " << N << "x" << N << ": " << duracionBloques.count() << " segundos" << endl;
    }

    return 0;
}
