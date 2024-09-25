#include <stdio.h>
#include <time.h>

#define MAX 1500  // Tamaño reducido para pruebas

void initialize(double A[MAX][MAX], double x[MAX], double y[MAX]) {
    for (int i = 0; i < MAX; i++) {
        x[i] = i * 0.5;
        y[i] = 0.0;
        for (int j = 0; j < MAX; j++) {
            A[i][j] = i + j;
        }
    }
}
void first_loop(double A[MAX][MAX], double x[MAX], double y[MAX]) {
    printf("Iniciando primer bucle\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    printf("Bucle 1 terminado\n");
}
void second_loop(double A[MAX][MAX], double x[MAX], double y[MAX]) {
    printf("Iniciando segundo bucle\n");
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
    printf("Bucle 2 terminado\n");
}
int main() {
    double A[MAX][MAX], x[MAX], y[MAX];
    clock_t start, end;
    double cpu_time_used;

    // Inicializamos A y x, y ponemos y a 0
    initialize(A, x, y);

    // Primer bucle (recorrido fila por fila)
    start = clock();
    first_loop(A, x, y);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo para el primer bucle: %f segundos\n", cpu_time_used);


     for (int i = 0; i < MAX; i++) {
        y[i] = 0.0;
    }

    start = clock();
    second_loop(A, x, y);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo para el segundo bucle: %f segundos\n", cpu_time_used);

    return 0;
}
