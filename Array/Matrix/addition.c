#include<stdio.h>
#include<stdlib.h>

int main() {
    
    int row, col;
    printf("Enter Row number: ");
    scanf("%d", &row);
    printf("Enter Column number: ");
    scanf("%d", &col);

    if(row == col) {
        int matrix_1[row][col];
    printf("Enter elements of Matrix 1: \n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &matrix_1[i][j]);
        }
    }

    int matrix_2[row][col];
    printf("Enter elements of Matrix 2: \n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &matrix_2[i][j]);
        }
    }

    int matrix_sum[row][col];
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            matrix_sum[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", matrix_sum[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    }
    else printf("Invalid input...\n");

    return 0;
}
