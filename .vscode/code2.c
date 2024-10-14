#include <stdio.h>
#define SIZE 5

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);

int main(){
    int m1[SIZE][SIZE] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    int m2[SIZE][SIZE] = {
        {21,22,23,24,25}, 
        {20,19,18,17,16},
        {15,14,13,12,11},       
        {10,9,8,7,6},
        {5,4,3,2,1}
    };

    int result[SIZE][SIZE];
    printf("Sum of matrix 1 and 2:\n");
    addMatrices(m1,m2,result);
    printMatrix(result);
    printf("\n");
    printf("Multiplication of matrix 1 and 2:\n");
    multiplyMatrices(m1,m2,result);
    printMatrix(result);
    printf("\n");
    printf("Transpose of matrix 1:\n");
    transposeMatrix(m1,result);    
    printMatrix(result);
    printf("\n");
    printf("Transpose of matrix 2:\n");
    transposeMatrix(m2,result);
    printMatrix(result);






    return 0;

}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]){
    for(int i = 0; i<SIZE;i++){
        for(int j =0; j<SIZE;j++){
            result[i][j] = m1[i][j]+m2[i][j];
            
        }
    }
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]){
        for(int i = 0; i<SIZE;i++){
            for(int j =0; j<SIZE;j++){
                result[i][j] = 0;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE]){
    for(int i=0; i < SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%4d ",  matrix[i][j]);
        }
        printf("\n");
    }
}