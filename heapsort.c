#include<stdio.h>
#include<stdlib.h>

#define N 1000000
int seed;

void init(int[]);
void heap_sort(int[]);
void makeheap(int[]);
void shift(int[], int, int);
void swap(int *, int *);

int main() {
    int A[N + 1];

    printf("Enter seed: ");
    scanf("%d", &seed);

    init(A);

    heap_sort(A);
    printf("%d\n", A[N / 2]);

    return 0;
}

void init(int A[]) {
    int i;
    srand((unsigned int) seed);
    for(i = 1; i <= N; i++)
        A[i] = rand();
}

void heap_sort(int A[]) {
    int i;
    makeheap(A);
    for(i = N; i > 1; i--) {
        swap(A + 1, A + i);
        shift(A, i - 1, 1);
    }
}

void makeheap(int A[]) {
    int i;
    for(i = N / 2; i >= 1; i--)
        shift(A, N, i);
}

void shift(int A[], int n, int i) {
    while(1) {
        int j = i;
        if(2 * j <= n && A[i] < A[2 * j])
            i = 2 * j;
        if(2 * j + 1 <= n && A[i] < A[2 * j + 1])
            i = 2 * j + 1;

        swap(A + i, A + j);

        if(i == j)
            break;
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
