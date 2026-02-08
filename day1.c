#include <stdio.h>

int main() {
    int n, pos, x;
    int a[50];
    printf("enter the number of elements : ");
 scanf("%d", &n);

    for(int i = 0; i < n; i++)
    printf("enter the elements : ")
        scanf("%d", &a[i]);
printf("position :")
    scanf("%d", &pos);
    printf("insert element : ")
    scanf("%d", &x);

    for(int i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = x;

    for(int i = 0; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}
