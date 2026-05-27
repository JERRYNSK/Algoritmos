#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main()
{
    int m = 3;
    int n = 3;
    int* v = (int*) malloc(sizeof(int) * m * n);
    for(int i = 0; i < 9; i++){
        v[i] = i;
    }
    printf("============= antes ================= \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("[%d]", v[i * m + j]);
        }
        printf("\n");
    }

    inverter(v, 3, 0);
    printf("================ depois ===================== \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("[%d]", v[i * m + j]);
        }
        printf("\n");
    }

    return 0;
}

int inverter(int* v, int n, int l){
    Pilha* pil;
    int k;
    int i = 0;
    k = l * n;
    pil = criar_pilha(n);
    for(i = 0; i < n; i++){
        push(pil, v[k + i]);
    }
    imprimir(pil);
    for(i = 0; i < n; i++){
        v[k + i] = pop(pil);
    }

    return 0;

}
