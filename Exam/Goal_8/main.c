#include <stdio.h>

int main() {
    printf("Enter N:");
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);

    if(n <= 0 || k <= 0 || k >= n) return 1;

    float a[n];
    for(int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    for(int i = k + 1; i < n; i++) {
        a[i - 1] = a[i];
    }
    n--;

    return 0;
}
