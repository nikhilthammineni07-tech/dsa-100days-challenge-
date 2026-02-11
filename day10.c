#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i;

    scanf("%s", s);

    int n = strlen(s);

    for(i = 0; i < n/2; i++) {
        if(s[i] != s[n-1-i]) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}
