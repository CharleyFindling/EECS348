#include <stdlib.h>
# include <stdio.h>
# define SIZE 5

int** addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int **result = malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        result[i] = malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
}


int** multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int **result = malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        result[i] = malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}

int** transposeMatrix(int m[SIZE][SIZE]) {
    int **result = malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        result[i] = malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m[j][i];
        }
    }
    return result;
}

void printMatrix(int **m) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}





int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int **sum = addMatrices(m1, m2);
    int **product = multiplyMatrices(m1, m2);
    int **transposed = transposeMatrix(m1);

    printf("Sum:\n");
    printMatrix(sum);
    printf("Product:\n");
    printMatrix(product);
    printf("Transposed:\n");
    printMatrix(transposed);



    for (int i = 0; i < SIZE; i++) { //free the memory by iterating through each [row][col] of each result matrix
        free(sum[i]);
        free(product[i]);
        free(transposed[i]);
    }
    free(sum);
    free(product);
    free(transposed);



    return 0;
}

