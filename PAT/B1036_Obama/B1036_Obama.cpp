#include <bits/stdc++.h>
int main() {
    int n, line;
    char little;
    scanf("%d %c", &n,&little);
    line = (n % 2 ? (n / 2 + 1) : (n / 2));
    for (int i = 0; i < n; i++)
        printf("%c", little);
    printf("\n");
    for (int i = 0; i < line - 2; i++) {
        printf("%c", little);
        for (int j = 0; j < n - 2; j++)
            printf(" ");
        printf("%c\n", little);
    }
    for (int i = 0; i < n; i++)
        printf("%c", little);
    return 0;
}