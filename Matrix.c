
#include<stdio.h>
#include<stdlib.h>
#include "Matrix.h"
typedef struct _mat_ {
    int numCol;
    int numLine;
    int* vec;
} MATRIX;

MATRIX* createMat(int i, int j){
    MATRIX* mat = (MATRIX*) malloc(sizeof(MATRIX));
    if (mat == NULL) return NULL;

    mat -> vec = (int*) malloc(i * j * sizeof(int));
    if ((mat -> vec) == NULL) return NULL;
    mat -> numLine = i;
    mat -> numCol = j;

    return mat;
}
void setMatrix(MATRIX* mat){
    int k = 0;
    for(int i = 0; i < (mat -> numLine); i++){
        for(int j = 0; j <  mat -> numCol; j++){
            k = i * (mat->numCol) + j;
            printf("qual valor desejar colocar em [%d][%d]: \n", i, j);
            scanf("%d", &mat -> vec[k]);
        }
        printf("\n");
    }
}
void printMat(MATRIX* mat){
    int k = 0;
    for(int i = 0; i < (mat -> numLine); i++){
        for(int j = 0; j <  mat -> numCol; j++){
            k = i * (mat->numCol) + j;
            printf("[%d]", mat -> vec[k]);
        }
        printf("\n");
    }
}
