#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

//m1
int rows1 = SIZE;
int cols1 = SIZE;

//m2
int rows2 = SIZE;
int cols2 = SIZE;
    

void multiplyMatrices(int m1[SIZE][SIZE] ,int m2[SIZE][SIZE]);
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);

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

    bool prompt = true;

    while(prompt){
        //display
        printf("Choose an option:\n");
        printf("1. Add Matrices\n");
        printf("2. Multiply Matrices\n");
        printf("3. Transpose Matrix\n");
        printf("4. Print Matrix\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);
        
        //menu choices/call functions
        if (choice == 1){
            addMatrices(m1, m2); 
        }
        else if(choice == 2){
            multiplyMatrices(m1, m2);
        }
        else if(choice == 3){
            printf("(Matrix 1) \n");
            transposeMatrix(m1);
            printf("(Matrix 2)\n");
            transposeMatrix(m2);
        }
        else if(choice == 4){

            printf("Matrix 1: \n");
            printMatrix(m1);
            printf("Matrix 2: \n");
            printMatrix(m2);
        }
        else if(choice == 5){
            prompt = false;
        }
        else{
            printf("Invalid Choice! \n");
        }
    }
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
//mSUM[i][j] = m1[i][j] + m2[i][j], 
//mSUM[i][j + 1] = m1[i][j+1] + m2[i][j+1] etc..

    if (rows1 != rows2 || cols1 != cols2) {
        printf("Dimension Error: Matrices cannot be added.\n");
        return;
    }    
    int mSUM[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){

            mSUM[i][j] = m1[i][j] + m2[i][j];
        }
    }
    printf("Matrix Sum: \n");
    printMatrix(mSUM);
}

void multiplyMatrices(int m1[SIZE][SIZE],int m2[SIZE][SIZE]){
//mPROD[i][j] = (m1[i][0] * m2[0][j]) + (m1[i][1] * m2[1][j])

    if (cols1 != rows2) {
        printf("Dimension Error: Matrices cannot be multiplied.\n");
        return;
    }
    int mPROD[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){

            mPROD[i][j] = 0;

            for (int k = 0; k < SIZE; k++){
                mPROD[i][j] += m1[i][k] * m2[k][j];
            }
           
        }
    }

    printf("Matrix Product: \n");
    printMatrix(mPROD);
}

void transposeMatrix(int matrix[SIZE][SIZE]){
//for every interation swap row/column

int matrixT[SIZE][SIZE];

for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
        matrixT[j][i] = matrix[i][j];
        }
    }
printf("Transposed Matrix: \n");
printMatrix(matrixT);
}

void printMatrix(int matrix[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%5d", matrix[i][j]); 
        }
        printf("\n");
    }
}