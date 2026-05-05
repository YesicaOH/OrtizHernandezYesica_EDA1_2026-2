#include <stdio.h>
#include <stdbool.h>

#define N 4

void imprimirTablero(int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %s ", tablero[i][j] ? "R" : ".");
        printf("\n");
    }
}

bool esSeguro(int tablero[N][N], int fila, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (tablero[fila][i]) return false;
    for (i = fila, j = col; i >= 0 && j >= 0; i--, j--)
        if (tablero[i][j]) return false;
    for (i = fila, j = col; j >= 0 && i < N; i++, j--)
        if (tablero[i][j]) return false;
    return true;
}

bool resolverReinas(int tablero[N][N], int col) {
    if (col >= N) return true; // Caso base: todas las reinas colocadas

    for (int i = 0; i < N; i++) {
        if (esSeguro(tablero, i, col)) {
            tablero[i][col] = 1; // Intentar colocar
            if (resolverReinas(tablero, col + 1)) return true;
            tablero[i][col] = 0; // BACKTRACK: quitar reina
        }
    }
    return false;
}

int main() {
    int tablero[N][N] = {0};
    if (resolverReinas(tablero, 0)) imprimirTablero(tablero);
    else printf("No hay solución");
    return 0;
}
