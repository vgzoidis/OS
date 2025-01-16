#include <stdio.h>

// Function to add three integers passed by reference
int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int x, y, z;

    // Input integers from the user
    printf("Enter the first integer: ");
    scanf("%d", &x);
    printf("Enter the second integer: ");
    scanf("%d", &y);
    printf("Enter the third integer: ");
    scanf("%d", &z);

    // Calculate the sum
    int sum = add(&x, &y, &z);
    printf("The sum of %d, %d, and %d is: %d\n", x, y, z, sum);

    return 0;
}
