#include<stdio.h>

int calculate();

int main() {
    printf("%d\n", calculate());
    return 0;
}

int calculate() {
    int n;
    int i = 1, j = 0, k;
    printf("Number: ");
    scanf("%d", &n);

    for(k = 1; k <= n; k++) {
        j = j + i;
        i = j - i;
    }

    return j;
}
