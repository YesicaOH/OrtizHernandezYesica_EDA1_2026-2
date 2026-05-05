#include <stdio.h>
#include <string.h>

void intercambiar(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permutar(char *a, int l, int r) {
    if (l == r) {
        printf("%s\n", a); // Caso base: se completó una permutación
    } else {
        for (int i = l; i <= r; i++) {
            intercambiar((a + l), (a + i)); // Acción: fijar carácter
            permutar(a, l + 1, r);          // Recursión: ir al siguiente nivel
            intercambiar((a + l), (a + i)); // BACKTRACK: restaurar el orden original
        }
    }
}

int main() {
    char str[] = "ABC";
    int n = strlen(str);
    permutar(str, 0, n - 1);
    return 0;
}
