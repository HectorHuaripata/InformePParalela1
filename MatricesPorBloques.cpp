#include <iostream>
#include <algorithm>

void multiplicarMatricesPorBloques(int A[][100], int B[][100], int C[][100], int rowsA, int colsA, int rowsB, int colsB, int blockSize) {
    //TODO: Implementar validador
    // Verifica si la multiplicacion es posible
    if (colsA != rowsB) {
        std::cout << "No se puede realizar la multiplicacion de matrices." << std::endl;
        return;
    }
    // Verifica si el tamaño del bloque es valido
    if (blockSize <= 0 || blockSize > std::min(rowsA, std::min(colsA, colsB))) {
        std::cout << "Tamanio de bloque invalido." << std::endl;
        return;
    }

    // Multiplicación por bloques
    for (int i = 0; i < rowsA; i += blockSize) {
        for (int j = 0; j < colsB; j += blockSize) {
            for (int k = 0; k < colsA; k += blockSize) {
                // Calcula el tamaño de los bloques actuales
                int rowsBlockA = std::min(blockSize, rowsA - i);
                int colsBlockA = std::min(blockSize, colsA - k);
                int colsBlockB = std::min(blockSize, colsB - j);

                // Multiplica los bloques y los acumula en la matriz resultante
                for (int p = 0; p < rowsBlockA; p++) {
                    for (int q = 0; q < colsBlockB; q++) {
                        for (int r = 0; r < colsBlockA; r++) {
                            C[i + p][j + q] += A[i + p][k + r] * B[k + r][j + q];
                        }
                    }
                }
            }
        }
    }
}

int main(){
    //int MAX = 100;
    //int matrixA[MAX][MAX], matrixB[MAX][MAX], matrixC[MAX][MAX];
    int matrixA[100][100], matrixB[100][100], matrixC[100][100];
    int rowsA, columnsA, rowsB, columnsB;


    rowsA = 4;
    columnsA = 5;
    rowsB = 5;
    columnsB = 3;

    //Define matriz A
    matrixA[0][0] = 2;
    matrixA[0][1] = 1;
    matrixA[0][2] = 4;
    matrixA[0][3] = 3;
    matrixA[0][4] = 0;

    matrixA[1][0] = 1;
    matrixA[1][1] = -3;
    matrixA[1][2] = 2;
    matrixA[1][3] = 6;
    matrixA[1][4] = 8;

    matrixA[2][0] = 5;
    matrixA[2][1] = 4;
    matrixA[2][2] = 2;
    matrixA[2][3] = -1;
    matrixA[2][4] = -2;

    matrixA[3][0] = -5;
    matrixA[3][1] = -3;
    matrixA[3][2] = 2;
    matrixA[3][3] = -1;
    matrixA[3][4] = 7;

    //Define matriz B
    matrixB[0][0] = -3;
    matrixB[0][1] = 2;
    matrixB[0][2] = 1;

    matrixB[1][0] = 7;
    matrixB[1][1] = 6;
    matrixB[1][2] = 4;

    matrixB[2][0] = 1;
    matrixB[2][1] = 2;
    matrixB[2][2] = 5;

    matrixB[3][0] = -4;
    matrixB[3][1] = 5;
    matrixB[3][2] = 0;

    matrixB[4][0] = 7;
    matrixB[4][1] = 5;
    matrixB[4][2] = 2;
    
    multiplicarMatricesPorBloques(matrixA, matrixB, matrixC, rowsA, columnsA, rowsB, columnsB, 2);

    // Imprimir la matriz resultante
    std::cout << "La matriz resultante es:" << std::endl;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            std::cout << matrixC[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}