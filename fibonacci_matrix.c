#include<stdio.h>
#include<stdlib.h>

int *calculate(int *, int);
int *matrix_product(int *, int *);
const int IDENTIFY[4] = {1, 0, 0, 1}; // to return identify matrix in function: calculate()

int main(void) {
    int n;
    printf("Number: ");
    scanf("%d", &n);

    int matrix[4] = {0, 1, 1, 1};
    int *answer = calculate(matrix, n);

    printf("%d\n", answer[1]);

    return 0;
}

int *calculate(int *matrix, int n) {
    if(n == 0)
        return IDENTIFY;
    if(n % 2)
        return matrix_product(matrix, calculate(matrix, n - 1));

    int *mat = calculate(matrix, n / 2);
    return matrix_product(mat, mat);
}

int *matrix_product(int *mat1, int *mat2) {
    int i, j;
    int *res = malloc(sizeof(int) * 4);

    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            res[i * 2 + j] = mat1[i * 2] * mat2[j] + mat1[i * 2 + 1] * mat2[2 + j];

    return res;
}
